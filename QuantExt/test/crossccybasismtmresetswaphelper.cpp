/*
 Copyright (C) 2018 Quaternion Risk Management Ltd
 All rights reserved.

 This file is part of ORE, a free-software/open-source library
 for transparent pricing and risk analysis - http://opensourcerisk.org

 ORE is free software: you can redistribute it and/or modify it
 under the terms of the Modified BSD License.  You should have received a
 copy of the license along with this program.
 The license is also available online at <http://opensourcerisk.org>

 This program is distributed on the basis that it will form a useful
 contribution to risk analytics and model standardisation, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
*/

#include "crossccybasismtmresetswaphelper.hpp"

#include <boost/make_shared.hpp>
#include <ql/currencies/all.hpp>
#include <ql/indexes/ibor/usdlibor.hpp>
#include <ql/indexes/ibor/gbplibor.hpp>
#include <ql/quotes/simplequote.hpp>
#include <ql/termstructures/yield/discountcurve.hpp>
#include <ql/termstructures/yield/flatforward.hpp>
#include <ql/termstructures/yield/piecewiseyieldcurve.hpp>
#include <ql/time/calendars/all.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/types.hpp>
#include <qle/pricingengines/crossccyswapengine.hpp>
#include <qle/termstructures/crossccybasismtmresetswaphelper.hpp>

#include <iostream>

using namespace std;
using namespace boost::unit_test_framework;
using namespace QuantLib;
using namespace QuantExt;

namespace {

struct CommonVars {

    Date asof;
    Natural settlementDays;
    Calendar domCalendar, fgnCalendar, payCalendar;
    BusinessDayConvention payConvention;
    Natural payLag;
    Period tenor;
    Currency fgnCurrency, domCurrency;
    DayCounter dayCount;
    Real fgnNominal;
    Spread spread;
    boost::shared_ptr<SimpleQuote> spotFxQuote;
    boost::shared_ptr<SimpleQuote> spreadQuote;
    Handle<YieldTermStructure> domProjCurve;
    Handle<YieldTermStructure> domDiscCurve;
    Handle<YieldTermStructure> fgnProjCurve;
    boost::shared_ptr<IborIndex> domIndex;
    boost::shared_ptr<IborIndex> fgnIndex;
    boost::shared_ptr<CrossCcyBasisMtMResetSwapHelper> helper;

    CommonVars() {
        asof = Date(11, Sep, 2018);
        settlementDays = 2;
        domCalendar = UnitedStates();
        fgnCalendar = UnitedKingdom();
        payCalendar = JointCalendar(domCalendar, fgnCalendar);
        payConvention = Following;
        payLag = 0;
        tenor = 5*Years;
        domCurrency = USDCurrency();
        fgnCurrency = GBPCurrency();
        dayCount = Actual360();
        fgnNominal = 10000000.0;
        spotFxQuote = boost::make_shared<SimpleQuote>(1.2);
        spreadQuote = boost::make_shared<SimpleQuote>(spread);
        spread = 0.0;

        // curves
        domProjCurve = Handle<YieldTermStructure>
            (boost::make_shared<FlatForward>(0, domCalendar, 0.02, Actual365Fixed()));
        fgnProjCurve = Handle<YieldTermStructure>
            (boost::make_shared<FlatForward>(0, fgnCalendar, 0.03, Actual365Fixed()));
        domDiscCurve = Handle<YieldTermStructure>
            (boost::make_shared<FlatForward>(0, domCalendar, 0.01, Actual365Fixed()));
        
        // indices
        fgnIndex = boost::make_shared<GBPLibor>(3*Months, fgnProjCurve);
        domIndex = boost::make_shared<USDLibor>(3*Months, domProjCurve);
    }
};

boost::shared_ptr<CrossCcyBasisMtMResetSwap> makeTestSwap(const CommonVars& vars,
                                                          const Handle<YieldTermStructure>& fgnDiscCurve) {
    // Swap schedule
    Date referenceDate = Settings::instance().evaluationDate();
    referenceDate = vars.payCalendar.adjust(referenceDate);
    Date start = vars.payCalendar.advance(referenceDate, vars.settlementDays*Days);
    Date end = start + vars.tenor;
    Schedule schedule(start, end, 3*Months, vars.payCalendar, vars.payConvention, 
                      vars.payConvention, DateGeneration::Backward, false);
    // Create swap
    boost::shared_ptr<FxIndex> fxIndex
        = boost::make_shared<FxIndex>("dummy", vars.settlementDays, vars.fgnCurrency, vars.domCurrency, 
                                      vars.payCalendar, Handle<Quote>(vars.spotFxQuote), 
                                      fgnDiscCurve, vars.domDiscCurve);
    boost::shared_ptr<CrossCcyBasisMtMResetSwap> swap
        = boost::make_shared<CrossCcyBasisMtMResetSwap>(vars.fgnNominal, vars.fgnCurrency, schedule, 
                                                        vars.fgnIndex, vars.spread, vars.domCurrency, schedule,
                                                        vars.domIndex, 0.0, fxIndex, false);
    // Attach pricing engine
    boost::shared_ptr<PricingEngine> engine 
        = boost::make_shared<CrossCcySwapEngine>(vars.domCurrency, vars.domDiscCurve, 
                                                 vars.fgnCurrency, fgnDiscCurve, 
                                                 Handle<Quote>(vars.spotFxQuote));
    swap->setPricingEngine(engine);
    return swap;
}

// Use helper to build bootstrapped curve
Handle<YieldTermStructure> bootstrappedCurve(CommonVars& vars) {

    // Create a helper
    vector<boost::shared_ptr<RateHelper>> helpers(1);
    vars.helper.reset(new CrossCcyBasisMtMResetSwapHelper(Handle<Quote>(vars.spreadQuote), Handle<Quote>(vars.spotFxQuote), 
                                                          vars.settlementDays, vars.payCalendar, vars.tenor, vars.payConvention, 
                                                          vars.fgnIndex, vars.domIndex, Handle<YieldTermStructure>(), vars.domDiscCurve));
    helpers[0] = vars.helper;

    // Build yield curve referencing the helper
    return Handle<YieldTermStructure>(
        boost::make_shared<PiecewiseYieldCurve<Discount, LogLinear>>(0, NullCalendar(), helpers, Actual365Fixed()));
}
} // namespace

namespace testsuite {

void CrossCcyBasisMtMResetSwapHelperTest::testBootstrap() {

    BOOST_TEST_MESSAGE("Test simple bootstrap against cross currency MtM resetting swap");

    SavedSettings backup;
    CommonVars vars;
    Settings::instance().evaluationDate() = vars.asof;

    // Create bootstrapped curve
    Handle<YieldTermStructure> discCurve = bootstrappedCurve(vars);

    // Create the helper swap manually and price it using curve bootstrapped from helper
    boost::shared_ptr<CrossCcyBasisMtMResetSwap> swap = makeTestSwap(vars, discCurve);

    // Print out cashflow to validate. Remove later
    /*
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < swap->leg(j).size(); i++) {
            cout << swap->leg(j)[i]->date() << "     " << swap->leg(j)[i]->amount() << endl;
        }
    };
    */
    // Swap should have NPV = 0.0. 
    Real tol = 1e-5;
    BOOST_CHECK_SMALL(swap->NPV(), tol);
}

test_suite* CrossCcyBasisMtMResetSwapHelperTest::suite() {

    test_suite* suite = BOOST_TEST_SUITE("CrossCcyBasisMtMResetSwapHelperTests");

    suite->add(BOOST_TEST_CASE(&CrossCcyBasisMtMResetSwapHelperTest::testBootstrap));

    return suite;
}

} // namespace testsuite
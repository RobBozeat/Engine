// Autogenerated by cmake
// Do not edit

#ifdef BOOST_MSVC
#include <ored/auto_link.hpp>
#endif

#include <ored/configuration/basecorrelationcurveconfig.hpp>
#include <ored/configuration/bootstrapconfig.hpp>
#include <ored/configuration/capfloorvolcurveconfig.hpp>
#include <ored/configuration/cdsvolcurveconfig.hpp>
#include <ored/configuration/commoditycurveconfig.hpp>
#include <ored/configuration/commodityvolcurveconfig.hpp>
#include <ored/configuration/conventions.hpp>
#include <ored/configuration/correlationcurveconfig.hpp>
#include <ored/configuration/curveconfig.hpp>
#include <ored/configuration/curveconfigurations.hpp>
#include <ored/configuration/defaultcurveconfig.hpp>
#include <ored/configuration/equitycurveconfig.hpp>
#include <ored/configuration/equityvolcurveconfig.hpp>
#include <ored/configuration/fxspotconfig.hpp>
#include <ored/configuration/fxvolcurveconfig.hpp>
#include <ored/configuration/genericyieldvolcurveconfig.hpp>
#include <ored/configuration/iborfallbackconfig.hpp>
#include <ored/configuration/inflationcapfloorvolcurveconfig.hpp>
#include <ored/configuration/inflationcurveconfig.hpp>
#include <ored/configuration/onedimsolverconfig.hpp>
#include <ored/configuration/reportconfig.hpp>
#include <ored/configuration/securityconfig.hpp>
#include <ored/configuration/swaptionvolcurveconfig.hpp>
#include <ored/configuration/volatilityconfig.hpp>
#include <ored/configuration/yieldcurveconfig.hpp>
#include <ored/configuration/yieldvolcurveconfig.hpp>
#include <ored/marketdata/adjustmentfactors.hpp>
#include <ored/marketdata/basecorrelationcurve.hpp>
#include <ored/marketdata/capfloorvolcurve.hpp>
#include <ored/marketdata/cdsvolcurve.hpp>
#include <ored/marketdata/clonedloader.hpp>
#include <ored/marketdata/commoditycurve.hpp>
#include <ored/marketdata/commodityvolcurve.hpp>
#include <ored/marketdata/compositeloader.hpp>
#include <ored/marketdata/correlationcurve.hpp>
#include <ored/marketdata/csvloader.hpp>
#include <ored/marketdata/curvespec.hpp>
#include <ored/marketdata/curvespecparser.hpp>
#include <ored/marketdata/defaultcurve.hpp>
#include <ored/marketdata/dependencygraph.hpp>
#include <ored/marketdata/dummymarket.hpp>
#include <ored/marketdata/equitycurve.hpp>
#include <ored/marketdata/equityvolcurve.hpp>
#include <ored/marketdata/expiry.hpp>
#include <ored/marketdata/fittedbondcurvehelpermarket.hpp>
#include <ored/marketdata/fixings.hpp>
#include <ored/marketdata/fxtriangulation.hpp>
#include <ored/marketdata/fxvolcurve.hpp>
#include <ored/marketdata/genericyieldvolcurve.hpp>
#include <ored/marketdata/inflationcapfloorvolcurve.hpp>
#include <ored/marketdata/inflationcurve.hpp>
#include <ored/marketdata/inmemoryloader.hpp>
#include <ored/marketdata/loader.hpp>
#include <ored/marketdata/market.hpp>
#include <ored/marketdata/marketdatum.hpp>
#include <ored/marketdata/marketdatumparser.hpp>
#include <ored/marketdata/marketimpl.hpp>
#include <ored/marketdata/security.hpp>
#include <ored/marketdata/strike.hpp>
#include <ored/marketdata/structuredcurveerror.hpp>
#include <ored/marketdata/swaptionvolcurve.hpp>
#include <ored/marketdata/todaysmarket.hpp>
#include <ored/marketdata/todaysmarketcalibrationinfo.hpp>
#include <ored/marketdata/todaysmarketparameters.hpp>
#include <ored/marketdata/wrappedmarket.hpp>
#include <ored/marketdata/yieldcurve.hpp>
#include <ored/marketdata/yieldvolcurve.hpp>
#include <ored/model/blackscholesmodelbuilder.hpp>
#include <ored/model/blackscholesmodelbuilderbase.hpp>
#include <ored/model/calibrationbasket.hpp>
#include <ored/model/calibrationconfiguration.hpp>
#include <ored/model/calibrationinstrumentfactory.hpp>
#include <ored/model/calibrationinstruments/cpicapfloor.hpp>
#include <ored/model/calibrationinstruments/yoycapfloor.hpp>
#include <ored/model/calibrationinstruments/yoyswap.hpp>
#include <ored/model/calibrationpointcache.hpp>
#include <ored/model/commodityschwartzmodelbuilder.hpp>
#include <ored/model/commodityschwartzmodeldata.hpp>
#include <ored/model/crcirbuilder.hpp>
#include <ored/model/crcirdata.hpp>
#include <ored/model/crlgmbuilder.hpp>
#include <ored/model/crlgmdata.hpp>
#include <ored/model/crossassetmodelbuilder.hpp>
#include <ored/model/crossassetmodeldata.hpp>
#include <ored/model/eqbsbuilder.hpp>
#include <ored/model/eqbsdata.hpp>
#include <ored/model/fxbsbuilder.hpp>
#include <ored/model/fxbsdata.hpp>
#include <ored/model/hwbuilder.hpp>
#include <ored/model/inflation/infdkbuilder.hpp>
#include <ored/model/inflation/infdkdata.hpp>
#include <ored/model/inflation/infjybuilder.hpp>
#include <ored/model/inflation/infjydata.hpp>
#include <ored/model/inflation/inflationmodeldata.hpp>
#include <ored/model/irhwmodeldata.hpp>
#include <ored/model/irlgmdata.hpp>
#include <ored/model/irmodeldata.hpp>
#include <ored/model/lgmbuilder.hpp>
#include <ored/model/lgmdata.hpp>
#include <ored/model/localvolmodelbuilder.hpp>
#include <ored/model/modeldata.hpp>
#include <ored/model/modelparameter.hpp>
#include <ored/model/structuredmodelerror.hpp>
#include <ored/model/utilities.hpp>
#include <ored/portfolio/ascot.hpp>
#include <ored/portfolio/asianoption.hpp>
#include <ored/portfolio/barrierdata.hpp>
#include <ored/portfolio/barrieroption.hpp>
#include <ored/portfolio/barrieroptionwrapper.hpp>
#include <ored/portfolio/basketdata.hpp>
#include <ored/portfolio/bond.hpp>
#include <ored/portfolio/bondoption.hpp>
#include <ored/portfolio/bondposition.hpp>
#include <ored/portfolio/bondrepo.hpp>
#include <ored/portfolio/bondtotalreturnswap.hpp>
#include <ored/portfolio/bondutils.hpp>
#include <ored/portfolio/builders/ascot.hpp>
#include <ored/portfolio/builders/asianoption.hpp>
#include <ored/portfolio/builders/bond.hpp>
#include <ored/portfolio/builders/bondoption.hpp>
#include <ored/portfolio/builders/bondrepo.hpp>
#include <ored/portfolio/builders/bondtotalreturnswap.hpp>
#include <ored/portfolio/builders/cachingenginebuilder.hpp>
#include <ored/portfolio/builders/capfloor.hpp>
#include <ored/portfolio/builders/capflooredaverageonindexedcouponleg.hpp>
#include <ored/portfolio/builders/capflooredcpileg.hpp>
#include <ored/portfolio/builders/capfloorediborleg.hpp>
#include <ored/portfolio/builders/capfloorednonstandardyoyleg.hpp>
#include <ored/portfolio/builders/capflooredovernightindexedcouponleg.hpp>
#include <ored/portfolio/builders/capflooredyoyleg.hpp>
#include <ored/portfolio/builders/cdo.hpp>
#include <ored/portfolio/builders/cliquetoption.hpp>
#include <ored/portfolio/builders/cms.hpp>
#include <ored/portfolio/builders/cmsspread.hpp>
#include <ored/portfolio/builders/commodityapo.hpp>
#include <ored/portfolio/builders/commodityapomodelbuilder.hpp>
#include <ored/portfolio/builders/commodityasianoption.hpp>
#include <ored/portfolio/builders/commodityforward.hpp>
#include <ored/portfolio/builders/commodityoption.hpp>
#include <ored/portfolio/builders/commodityspreadoption.hpp>
#include <ored/portfolio/builders/commodityswap.hpp>
#include <ored/portfolio/builders/commodityswaption.hpp>
#include <ored/portfolio/builders/convertiblebond.hpp>
#include <ored/portfolio/builders/cpicapfloor.hpp>
#include <ored/portfolio/builders/creditdefaultswap.hpp>
#include <ored/portfolio/builders/creditdefaultswapoption.hpp>
#include <ored/portfolio/builders/creditlinkedswap.hpp>
#include <ored/portfolio/builders/currencyswap.hpp>
#include <ored/portfolio/builders/durationadjustedcms.hpp>
#include <ored/portfolio/builders/equityasianoption.hpp>
#include <ored/portfolio/builders/equitybarrieroption.hpp>
#include <ored/portfolio/builders/equitycompositeoption.hpp>
#include <ored/portfolio/builders/equitydigitaloption.hpp>
#include <ored/portfolio/builders/equitydoublebarrieroption.hpp>
#include <ored/portfolio/builders/equitydoubletouchoption.hpp>
#include <ored/portfolio/builders/equityforward.hpp>
#include <ored/portfolio/builders/equityfuturesoption.hpp>
#include <ored/portfolio/builders/equityoption.hpp>
#include <ored/portfolio/builders/equitytouchoption.hpp>
#include <ored/portfolio/builders/forwardbond.hpp>
#include <ored/portfolio/builders/forwardrateagreement.hpp>
#include <ored/portfolio/builders/fxasianoption.hpp>
#include <ored/portfolio/builders/fxbarrieroption.hpp>
#include <ored/portfolio/builders/fxdigitalbarrieroption.hpp>
#include <ored/portfolio/builders/fxdigitaloption.hpp>
#include <ored/portfolio/builders/fxdoublebarrieroption.hpp>
#include <ored/portfolio/builders/fxdoubletouchoption.hpp>
#include <ored/portfolio/builders/fxforward.hpp>
#include <ored/portfolio/builders/fxoption.hpp>
#include <ored/portfolio/builders/fxtouchoption.hpp>
#include <ored/portfolio/builders/indexcreditdefaultswap.hpp>
#include <ored/portfolio/builders/indexcreditdefaultswapoption.hpp>
#include <ored/portfolio/builders/multilegoption.hpp>
#include <ored/portfolio/builders/quantoequityoption.hpp>
#include <ored/portfolio/builders/quantovanillaoption.hpp>
#include <ored/portfolio/builders/swap.hpp>
#include <ored/portfolio/builders/swaption.hpp>
#include <ored/portfolio/builders/vanillaoption.hpp>
#include <ored/portfolio/builders/varianceswap.hpp>
#include <ored/portfolio/builders/yoycapfloor.hpp>
#include <ored/portfolio/capfloor.hpp>
#include <ored/portfolio/cdo.hpp>
#include <ored/portfolio/cliquetoption.hpp>
#include <ored/portfolio/commodityapo.hpp>
#include <ored/portfolio/commoditydigitalapo.hpp>
#include <ored/portfolio/commoditydigitaloption.hpp>
#include <ored/portfolio/commodityforward.hpp>
#include <ored/portfolio/commoditylegbuilder.hpp>
#include <ored/portfolio/commoditylegdata.hpp>
#include <ored/portfolio/commodityoption.hpp>
#include <ored/portfolio/commodityoptionstrip.hpp>
#include <ored/portfolio/commodityspreadoption.hpp>
#include <ored/portfolio/commodityswap.hpp>
#include <ored/portfolio/commodityswaption.hpp>
#include <ored/portfolio/compositeinstrumentwrapper.hpp>
#include <ored/portfolio/compositetrade.hpp>
#include <ored/portfolio/convertiblebond.hpp>
#include <ored/portfolio/convertiblebonddata.hpp>
#include <ored/portfolio/convertiblebondreferencedata.hpp>
#include <ored/portfolio/creditdefaultswap.hpp>
#include <ored/portfolio/creditdefaultswapdata.hpp>
#include <ored/portfolio/creditdefaultswapoption.hpp>
#include <ored/portfolio/creditlinkedswap.hpp>
#include <ored/portfolio/crosscurrencyswap.hpp>
#include <ored/portfolio/durationadjustedcmslegbuilder.hpp>
#include <ored/portfolio/durationadjustedcmslegdata.hpp>
#include <ored/portfolio/enginedata.hpp>
#include <ored/portfolio/enginefactory.hpp>
#include <ored/portfolio/envelope.hpp>
#include <ored/portfolio/equitybarrieroption.hpp>
#include <ored/portfolio/equityderivative.hpp>
#include <ored/portfolio/equitydigitaloption.hpp>
#include <ored/portfolio/equitydoublebarrieroption.hpp>
#include <ored/portfolio/equitydoubletouchoption.hpp>
#include <ored/portfolio/equityeuropeanbarrieroption.hpp>
#include <ored/portfolio/equityforward.hpp>
#include <ored/portfolio/equityfuturesoption.hpp>
#include <ored/portfolio/equityfxlegbuilder.hpp>
#include <ored/portfolio/equityfxlegdata.hpp>
#include <ored/portfolio/equityoption.hpp>
#include <ored/portfolio/equityoptionposition.hpp>
#include <ored/portfolio/equityposition.hpp>
#include <ored/portfolio/equityswap.hpp>
#include <ored/portfolio/equitytouchoption.hpp>
#include <ored/portfolio/failedtrade.hpp>
#include <ored/portfolio/fixingdates.hpp>
#include <ored/portfolio/forwardbond.hpp>
#include <ored/portfolio/forwardrateagreement.hpp>
#include <ored/portfolio/fxaverageforward.hpp>
#include <ored/portfolio/fxbarrieroption.hpp>
#include <ored/portfolio/fxderivative.hpp>
#include <ored/portfolio/fxdigitalbarrieroption.hpp>
#include <ored/portfolio/fxdigitaloption.hpp>
#include <ored/portfolio/fxdoublebarrieroption.hpp>
#include <ored/portfolio/fxdoubletouchoption.hpp>
#include <ored/portfolio/fxeuropeanbarrieroption.hpp>
#include <ored/portfolio/fxforward.hpp>
#include <ored/portfolio/fxkikobarrieroption.hpp>
#include <ored/portfolio/fxoption.hpp>
#include <ored/portfolio/fxswap.hpp>
#include <ored/portfolio/fxtouchoption.hpp>
#include <ored/portfolio/indexcreditdefaultswap.hpp>
#include <ored/portfolio/indexcreditdefaultswapdata.hpp>
#include <ored/portfolio/indexcreditdefaultswapoption.hpp>
#include <ored/portfolio/indexing.hpp>
#include <ored/portfolio/inflationswap.hpp>
#include <ored/portfolio/instrumentwrapper.hpp>
#include <ored/portfolio/legbuilders.hpp>
#include <ored/portfolio/legdata.hpp>
#include <ored/portfolio/legdatafactory.hpp>
#include <ored/portfolio/multilegoption.hpp>
#include <ored/portfolio/nettingsetdefinition.hpp>
#include <ored/portfolio/nettingsetdetails.hpp>
#include <ored/portfolio/nettingsetmanager.hpp>
#include <ored/portfolio/optiondata.hpp>
#include <ored/portfolio/optionexercisedata.hpp>
#include <ored/portfolio/optionpaymentdata.hpp>
#include <ored/portfolio/optionwrapper.hpp>
#include <ored/portfolio/portfolio.hpp>
#include <ored/portfolio/premiumdata.hpp>
#include <ored/portfolio/rangebound.hpp>
#include <ored/portfolio/referencedata.hpp>
#include <ored/portfolio/referencedatafactory.hpp>
#include <ored/portfolio/schedule.hpp>
#include <ored/portfolio/simmcreditqualifiermapping.hpp>
#include <ored/portfolio/structuredconfigurationerror.hpp>
#include <ored/portfolio/structuredconfigurationwarning.hpp>
#include <ored/portfolio/structuredtradeerror.hpp>
#include <ored/portfolio/structuredtradewarning.hpp>
#include <ored/portfolio/swap.hpp>
#include <ored/portfolio/swaption.hpp>
#include <ored/portfolio/trade.hpp>
#include <ored/portfolio/tradeactions.hpp>
#include <ored/portfolio/tradebarrier.hpp>
#include <ored/portfolio/tradefactory.hpp>
#include <ored/portfolio/trademonetary.hpp>
#include <ored/portfolio/tradestrike.hpp>
#include <ored/portfolio/tranche.hpp>
#include <ored/portfolio/trs.hpp>
#include <ored/portfolio/trsunderlyingbuilder.hpp>
#include <ored/portfolio/trswrapper.hpp>
#include <ored/portfolio/types.hpp>
#include <ored/portfolio/underlying.hpp>
#include <ored/portfolio/vanillaoption.hpp>
#include <ored/portfolio/varianceswap.hpp>
#include <ored/report/csvreport.hpp>
#include <ored/report/inmemoryreport.hpp>
#include <ored/report/report.hpp>
#include <ored/utilities/calendaradjustmentconfig.hpp>
#include <ored/utilities/calendarparser.hpp>
#include <ored/utilities/conventionsbasedfutureexpiry.hpp>
#include <ored/utilities/correlationmatrix.hpp>
#include <ored/utilities/csvfilereader.hpp>
#include <ored/utilities/currencyconfig.hpp>
#include <ored/utilities/currencyhedgedequityindexdecomposition.hpp>
#include <ored/utilities/currencyparser.hpp>
#include <ored/utilities/dategrid.hpp>
#include <ored/utilities/fileio.hpp>
#include <ored/utilities/filteredbufferedlogger.hpp>
#include <ored/utilities/flowanalysis.hpp>
#include <ored/utilities/indexnametranslator.hpp>
#include <ored/utilities/indexparser.hpp>
#include <ored/utilities/inflationstartdate.hpp>
#include <ored/utilities/initbuilders.hpp>
#include <ored/utilities/log.hpp>
#include <ored/utilities/marketdata.hpp>
#include <ored/utilities/osutils.hpp>
#include <ored/utilities/parsers.hpp>
#include <ored/utilities/progressbar.hpp>
#include <ored/utilities/serializationdate.hpp>
#include <ored/utilities/serializationdaycounter.hpp>
#include <ored/utilities/serializationperiod.hpp>
#include <ored/utilities/strike.hpp>
#include <ored/utilities/timeperiod.hpp>
#include <ored/utilities/to_string.hpp>
#include <ored/utilities/vectorutils.hpp>
#include <ored/utilities/wildcard.hpp>
#include <ored/utilities/xmlutils.hpp>
#include <ored/version.hpp>

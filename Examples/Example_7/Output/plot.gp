set datafile sep ","
set decimal locale
set format y "%'.0f"

set title "Example 3"
set xlabel "Time / Years"
set ylabel "Exposure"

set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 3
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 3
set style line 3 linecolor rgb '#008000' linetype 1 linewidth 3
set style line 4 linecolor rgb '#990099' linetype 1 linewidth 3

set autoscale
set term pdfcairo 
set out "tmp.pdf"

plot "exposure_trade_Swap.csv" us 3:4 title "EPE Swap" w l ls 1
replot "exposure_trade_SwaptionCash.csv" us 3:4 title "EPE Swaption Cash" w l ls 2
replot "exposure_trade_SwaptionPhysical.csv" us 3:4 title "EPE Swaption Physical" w l ls 3

set out "plot.pdf"
replot

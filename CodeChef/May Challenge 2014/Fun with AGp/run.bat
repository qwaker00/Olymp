@echo off
gen.exe >.in
del .hax
del .brute
hax.exe <.in >.hax
brute.exe <.in >.brute
fc .hax .brute

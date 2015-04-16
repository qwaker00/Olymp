echo off
gen.py >.in
sol.exe <.in >.out
hax.exe <.in >.brute
fc .out .brute
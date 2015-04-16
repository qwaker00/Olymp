@echo off
gen.py >.in
hax.exe <.in >.out1
sol.exe <.in >.out2
fc .out1 .out2
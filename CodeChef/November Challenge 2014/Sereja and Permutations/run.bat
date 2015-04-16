@echo off
gen.py >.in
hax.exe <.in >.out
type .out

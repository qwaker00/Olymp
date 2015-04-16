@echo off
echo Start >log
for /l %%i in (1, 1, 1000) do call :r %%i
goto :eof


:r
echo Test#%1
gen.py >.in
copy .in test\%1.in >nul
doit.py <.in >.brute
hax.exe <.in >.out
fc .out .brute
fc .out .brute >>log
goto :eof
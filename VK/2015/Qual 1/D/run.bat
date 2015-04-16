@echo off
echo Start >log
for /l %%i in (1, 1, 1000) do call :test %%i
goto :eof


:test
	echo Test#%1
	gen.py >.in
	copy .in test\%1.in
	sol.exe <.in >.out
	brute2.exe <.in >.brute
	fc .out .brute
	fc .out .brute >>log
goto :eof
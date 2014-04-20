@echo off
for /l %%i in (1, 1, 1000) do call :run %%i
goto :eof

:run
	echo %1
	gen.exe %1 >.in
	hax.exe <.in >.out
	if %ERRORLEVEL% GEQ 1 call :whiletrue
goto :eof

:whiletrue
	goto :whiletrue

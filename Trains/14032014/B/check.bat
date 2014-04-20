for /l %%i in (1, 1, 1000) do call :run

:run
python gen.py >financial.in
hax.exe
check.bat
goto :eof
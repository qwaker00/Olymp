@echo off
for /l %%i in (1, 1, 1000) do call :run %%i
goto :eof

:run
    echo #%1
    gen.py >palindromes.in
    hax.exe
goto :eof
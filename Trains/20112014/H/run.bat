@echo off
for /l %%i in (1, 1, 30) do call :run %%i
goto :eof


:run
echo Test %1
echo %1 >.in
hax.exe
type .out
type .out >>result

@echo off
echo Start >result
for /l %%i in (1, 1, 1000) do call :run %%i
goto :eof

:run
echo Test#%1
echo Test#%1 >>result

gen.py >%1.in
copy %1.in average.in
rm average.out

hax.exe
move average.out sol.out

brute.exe
fc average.out sol.out

fc average.out sol.out >>result


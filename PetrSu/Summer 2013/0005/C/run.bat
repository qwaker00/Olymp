@echo off

echo Start >res.txt
for /l %%i in (1, 1, 1000) do call :r %%i

:r
echo %1 >>res.txt
gen.exe >.in
cp .in ins\%1.in
hax.exe <.in >.hax 2>>res.txt
new.exe <.in >.new 2>>res.txt
diff .hax .new >>res.txt
goto :eof
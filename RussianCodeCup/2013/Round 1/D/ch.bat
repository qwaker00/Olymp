@echo off

for /l %%i in (1, 1, 16) do (
    echo %%i >.in
    hax.exe <.in >.out
    wc -l .out
)

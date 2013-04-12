@echo off

call :%~x1 %*
goto :eof
    
:.cpp
:.c
    if "%2" == "templater" (
rem        C:\Olymp\runner.bat C:\Olymp\template\templater.py %1 C:\Olymp\template
    ) else  (
        if "%2" == "gdb" (
            gdb %~n1.exe
        ) else  (
            if exist %~n1.exe del %~n1.exe
            if "%2" == "O2" (
                g++ -Wl,--stack=268435456 %1 -Wall -o %~n1.exe -O2
            ) else (
                g++ -Wl,--stack=268435456 -g %1 -Wall -o %~n1.exe -O0 -D_DEBUG
            )
        )
   )
goto :eof

:.py
    python.exe %*
    goto :eof

:.pas
    if exist %~n1.exe del %~n1.exe
    if "%2" == "O2" (
        fpc.exe -O2 %1
    ) else  (
        fpc.exe %1
    )
    del %~n1.o >nul
    goto :eof

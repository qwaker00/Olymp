@echo off

set OLYMPDIR=C:\Prog\Olymp\

call :%~x1 %*
goto :eof
    
:.cpp
    if "%2" == "templater" (
        %OLYMPDIR%\runner.bat %OLYMPDIR%\\template\templater.py %1 %OLYMPDIR%\template
    ) else  (
        if "%2" == "gdb" (
            gdb %~n1.exe
        ) else  (
            if exist %~n1.exe del %~n1.exe
            if "%2" == "O2" (
                g++ -I%OLYMPDIR%\template -x c++ -std=c++11 -Wl,--stack=268435456 %1 -Wall -o %~n1.exe -O2
            ) else (
                g++ -I%OLYMPDIR%\template -x c++ -std=c++11 -Wl,--stack=268435456 -g %1 -Wall -o %~n1.exe -O0 -DDEBUG
            )
        )
   )
goto :eof

:.c
    if "%2" == "gdb" (
        gdb %~n1.exe
    ) else  (
        if exist %~n1.exe del %~n1.exe
        if "%2" == "O2" (
            gcc -x c %1 -Wall -o %~n1.exe -O2 -static
        ) else (
            gcc -x c -g %1 -Wall -o %~n1.exe -O0 -DDEBUG -static
        )
    )
goto :eof

:.py
    if "%2" == "O2" (
        python.exe %*
    ) else (
        python.exe -O %*
    )
    goto :eof

:.py3
    if "%2" == "O2" (
        python3.exe %*
    ) else (
        python3.exe -O %*
    )
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

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
                g++ -I%OLYMPDIR%\template -x c++ -std=c++11 %1 -Wall -o %~n1.exe -O2 %CPPOPT% -Wl,--stack=268435456
            ) else (
                g++ -I%OLYMPDIR%\template -x c++ -std=c++11 -g %1 -Wall -o %~n1.exe -DDEBUG -D_GLIBCXX_DEBUG -ftrapv %CPPOPT% -Wl,--stack=268435456
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
        python.exe -O %*
    ) else (
        python.exe %*
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
    if "%2" == "gdb" (
        gdb %~n1.exe
    ) else  (
        if exist %~n1.exe del %~n1.exe
        if "%2" == "O2" (
            fpc.exe -O2 %1
        ) else  (
            fpc.exe %1 -g
        )
        del %~n1.o >nul
    )
    goto :eof

:.java
    javac %1
    goto :eof

:.class
    java %~n1
    goto :eof

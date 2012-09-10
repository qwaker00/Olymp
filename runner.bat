@echo off

call :%~x1 %1 %2
goto :eof

    
:.cpp
    if "%2" == "gdb" (
        gdb %~n1.exe
    ) else  (
        if exist %~n1.exe del %~n1.exe
        if "%2" == "O2" (
            g++ %~n1.cpp -Wall -o %~n1.exe -O2
        ) else (
            g++ -g %~n1.cpp -Wall -o %~n1.exe
        )
    )
goto :eof

:.py
    C:\Python27\python.exe %1
goto :eof

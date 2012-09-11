@echo off

call :%~x1 %*
goto :eof

    
:.cpp
    if "%2" == "templater" (
        C:\Olymp\runner.bat C:\Olymp\template\templater.py %1 C:\Olymp\template
    ) else  (
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
   )
goto :eof

:.py
    C:\Python27\python.exe %*
goto :eof

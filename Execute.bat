@echo off

gcc -o test src/main.c src/Estructures/LinkedList.c -o test.exe

if %errorlevel% neq 0 (
    echo Error de compilacion
    pause
    exit /b
)

echo.
echo Ejecutando programa...
echo.

test.exe

pause
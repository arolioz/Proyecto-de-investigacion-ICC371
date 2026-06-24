@echo off

gcc ./test.c src/Estructures/LinkedList.c src/Estructures/stack.c -o testBuild.exe

if %errorlevel% neq 0 (
    echo Error de compilacion
    pause
    exit /b
)

echo.
echo Ejecutando programa...
echo.

testBuild.exe

pause
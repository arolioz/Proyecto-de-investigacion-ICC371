@echo off

gcc ./src/main.c src/Estructures/LinkedList.c src/Estructures/stack.c src/Estructures/queue.c src/Estructures/binary_tree.c src/Estructures/hash_table.c src/Estructures/array.c -o main.exe

if %errorlevel% neq 0 (
    echo Error de compilacion
    pause
    exit /b
)

echo.
echo Ejecutando programa...
echo.

main.exe

pause
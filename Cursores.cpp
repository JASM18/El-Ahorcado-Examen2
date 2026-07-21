#include "Cursores.hpp"
#include <cstdio>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void MoverCursor(short x, short y)
{
    #ifdef _WIN32
        COORD coord = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else
        // ANSI: fila (y) primero, luego columna (x). Ambos empiezan en 1, no en 0.
        printf("\033[%d;%dH", y + 1, x + 1);
        fflush(stdout);
    #endif
}

void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/)
{
    #ifdef _WIN32
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info = { modo, estado };
        SetConsoleCursorInfo(consoleHandle, &info);
    #else
        if (estado == ENCENDIDO)
            printf("\033[?25h"); // muestra cursor
        else
            printf("\033[?25l"); // oculta cursor
        fflush(stdout);
        (void)modo; // evita warning de parámetro no usado
    #endif
}

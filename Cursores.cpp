#include <windows.h>

enum ModoCursor{MINI = 1, NORMAL = 40,SOLIDO = 80}; //Tamaño cursor
enum EstadoCursor{APAGADO, ENCENDIDO}; //Cursor on/off

void MoverCursor(short x, short y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = {modo,estado};
	SetConsoleCursorInfo(consoleHandle, &info);
}

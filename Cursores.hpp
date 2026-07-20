#ifndef CURSORES_HPP_INCLUDED
#define CURSORES_HPP_INCLUDED

enum EstadoCursor{APAGADO, ENCENDIDO}; //Cursor on/off
enum ModoCursor{MINI = 1, NORMAL = 40,SOLIDO = 80}; //Tamaño cursor

void MoverCursor(short x, short y);
void CambiarCursor(EstadoCursor estado, ModoCursor modo = NORMAL);

#endif // CURSORES_HPP_INCLUDED

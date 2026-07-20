#include <iostream>

#include "Cursores.hpp"

bool EstaLaLetra(char letra[], char palabra[])
{
    for(int i = 0 ; palabra[i] != '\0' ; ++i){ //Comprobamos si letra[0] esta en palabra[i]
        if(palabra[i] == letra[0]){
            return true;
        }
    }
    return false;
}

void UpdateProgress(char cadena[], char* cubierto, char letra[])
{
    for(int j = 0 ; cadena[j] != '\0' ; ++j) {
        if(cadena[j] == letra[0]) {
            MoverCursor(j, 2);
            std::cout << letra[0];
            cubierto[j] = letra[0]; // Modifica el arreglo original
        }
    }
}

void LimpiarPantalla()
{
    for(int i = 18 ; i < 120 ; ++i){ //Limpia Escribe una letra:
        MoverCursor(i, 4);
        std::cout << " ";
    }
    for(int i = 0 ; i < 8 ; ++i){ //Limpia Tu letra: #
        MoverCursor(i, 6);
        std::cout << " ";
    }
    for(int i = 0 ; i < 40 ; ++i){ //Limpia Tu letra... SI ESTA/NO ESTA
        MoverCursor(i, 7);
        std::cout << " ";
    }
    for(int i = 0 ; i < 40 ; ++i){ //Limpia el system pause
        MoverCursor(i, 9);
        std::cout << " ";
    }
    MoverCursor(0, 2);
}


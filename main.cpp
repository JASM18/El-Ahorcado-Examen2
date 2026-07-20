/*
Nombre del archivo: Examen 2
Descripción: Este es un juego que simula el juego del ahorcado, en donde la palabra esta definida por el programador y el usuario debe de encontrar la palabra letra por letra...
Autor: Jesus Axel Sanchez Montoy
Fecha: 10 de abril del 2025
*/

#include <iostream>
#include <cstring>
#include <cctype>

#include <windows.h>

#include "Destapar.hpp"
#include "Cursores.hpp"

enum {AMAYU = 181, EMAYU = 144, IMAYU = 214, OMAYU = 224, UMAY = 233};
enum {Amin = 160, Emin = 130, Imin = 161, Omin, Umin};

using namespace std;

int main()
{
    char cadena[100] = {"alicia en el pais de las maravillas"};
    char cubierto[100];
    char letra[2];

    int intentos = 0;

    CambiarCursor(ENCENDIDO);

    for(int i = 0 ; cadena[i] != '\0' ; ++i){ //Toda la cadena en mayuscula
        cadena[i] = toupper(cadena[i]);
    }

    for(int i = 0 ; cadena[i] != '\0' ; ++i){ //Creamos "cubierto" tal que {*** ** **** *...]
        if(cadena[i] == ' '){
            cubierto[i] = ' ';
        }else{
            cubierto[i] = '*';
        }
    }
    cubierto[strlen(cadena)] = '\0'; // Asegura terminación nula

    cout << "EXAMEN 2 - EL AHORCADO" << endl;
    cout << endl;

    for(int i = 0 ; cadena[i] != '\0' ; ++i){ //Imprimimos en pantalla los asteriscos

        if(cadena[i] == ' '){
            cout << ' ';
        }else{
            cout << '*';
        }
    }

    //AHORA JUGAMOS
    while(true){
        if(strcmp(cubierto, cadena) == 0){
            break;
        }

        cout << "\n\nEscribe una letra: ";
        cin.getline(letra, 2);

        letra[0] = toupper(letra[0]); //Ajustamos para que sea mayuscula

        std::cout << "\nLetra: " << letra[0] << endl;

        CambiarCursor(APAGADO);

        cout << "Tu letra";
        for(int i = 0 ; i < 3 ; i++){ //SUSPENSO DRAMATICO...
            Sleep(500);
            cout << ".";
        }
        Sleep(500);

        if(EstaLaLetra(letra, cadena)){

            cout << " S" << (char) IMAYU << " EST"<< (char)AMAYU <<" EN LA PALABRA";

            UpdateProgress(cadena, cubierto, letra);
        }else{
            cout << " No est" << (char) Amin << " en la palabra... :(";
            intentos += 1;
        }

        CambiarCursor(ENCENDIDO);
        MoverCursor(0, 9);
        system ("pause");

        LimpiarPantalla();
    }

    MoverCursor(0,6);

    cout << "\255Felicidades! Adivinaste toda la frase." << endl;
    cout << "N" << (char) Umin << "mero de fallos: " << intentos << endl;

    cout << "\n\n";
    system ("pause");
    return 0;
}

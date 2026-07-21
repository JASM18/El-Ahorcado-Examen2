/*
Nombre del archivo: Examen 2
Descripción: Este es un juego que simula el juego del ahorcado, en donde la palabra esta definida por el programador y el usuario debe de encontrar la palabra letra por letra...
Autor: Jesus Axel Sanchez Montoy
Fecha: 10 de abril del 2025
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>

#include "Destapar.hpp"
#include "Cursores.hpp"

// ======================================

#ifdef _WIN32
    #include <windows.h>
#else
    #include <chrono>
    #include <thread>
#endif

using namespace std;

// ======================================
#ifdef _WIN32
    // Códigos CP437 de la consola de Windows
    enum {AMAYU = 181, EMAYU = 144, IMAYU = 214, OMAYU = 224, UMAY = 233};
    enum {Amin = 160, Emin = 130, Imin = 161, Omin = 162, Umin = 163};
    #define CHR(x) ((char)(x))   // en Windows se sigue casteando a char
    #define INV_EXCL "\255"
#else
    // Para terminal Linux
    #define AMAYU "Á"
    #define EMAYU "É"
    #define IMAYU "Í"
    #define OMAYU "Ó"
    #define UMAY  "Ú"
    #define Amin  "á"
    #define Emin  "é"
    #define Imin  "í"
    #define Omin  "ó"
    #define Umin  "ú"
    #define CHR(x) (x)
    #define INV_EXCL "¡"
#endif
// ======================================

// ======================================
// Función auxiliar para dormir la terminal por milisegundos
void EsperarMs(int ms)
{
    #ifdef _WIN32
        Sleep(ms);
    #else
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    #endif
}

// Reemplazo de system("pause") para linux/windows
void Pausa()
{
    #ifdef _WIN32
        system("pause");
    #else
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout << "Presione Enter para continuar..." << flush;
        cin.get();
    #endif
}
// ======================================

int main()
{
    char cadena[100] = {"alicia en el pais de las maravillas"};
    char cubierto[100];
    char letra[2];
    int intentos = 0;

    CambiarCursor(ENCENDIDO);

    for(int i = 0 ; cadena[i] != '\0' ; ++i){
        cadena[i] = toupper(cadena[i]);
    }

    for(int i = 0 ; cadena[i] != '\0' ; ++i){
        if(cadena[i] == ' '){
            cubierto[i] = ' ';
        }else{
            cubierto[i] = '*';
        }
    }

    cubierto[strlen(cadena)] = '\0';
    cout << "EXAMEN 2 - EL AHORCADOOO" << endl;
    cout << endl;

    // Se imprime en pantalla los asteriscos
    for(int i = 0 ; cadena[i] != '\0' ; ++i){
        if(cadena[i] == ' '){
            cout << ' ';
        }else{
            cout << '*';
        }
    }

    // AHORA JUGAMOS
    while(true){
        if(strcmp(cubierto, cadena) == 0){
            break;
        }

        cout << "\n\nEscribe una letra: ";
        cin.getline(letra, 2);
        letra[0] = toupper(letra[0]);

        std::cout << "\nLetra: " << letra[0] << endl;
        CambiarCursor(APAGADO);

        // Momento de tension...
        cout << "Tu letra" << flush;
        for(int i = 0 ; i < 3 ; i++){
            EsperarMs(500);
            cout << "." << flush;
        }

        EsperarMs(500);
        if(EstaLaLetra(letra, cadena)){
            cout << " S" << CHR(IMAYU) << " EST" << CHR(AMAYU) << " EN LA PALABRA";
            UpdateProgress(cadena, cubierto, letra);
        }else{
            cout << " No est" << CHR(Amin) << " en la palabra... :(";
            intentos += 1;
        }

        CambiarCursor(ENCENDIDO);
        MoverCursor(0, 9);
        Pausa();
        LimpiarPantalla();
    }

    MoverCursor(0,6);
    cout << INV_EXCL << "Felicidades! Adivinaste toda la frase." << endl;
    cout << "N" << CHR(Umin) << "mero de fallos: " << intentos << endl;
    cout << "\n\n";

    Pausa();
    return 0;
}

// Se lee de teclado una secuencia de números que finaliza con la primera ocurrencia de un número negativo, el
// cual no debe ser procesado. Los números deben ser almacenados en una lista enlazada simple. Se solicita:
// A. Leer de teclado un número e informar si existe en la lista.
// B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista.
// C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
// números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
// original, la que quedará vacía después de invocar a la función. Imprimir las listas resultantes.

// META DATA
#include <iostream>
#include <limits>       // Para std::numeric_limits
#include <string>      // Para el uso de strings
#include <fstream>      //Para manejo de archivos

using namespace std;

// VARIABLES GLOBALES Y CONSTANTES

// ESTRUCTURAS
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// DECLARACIÓN DE FUNCIONES
void agregar_a_pila(Nodo*& pila, int num);
void imprimir_pila(Nodo* pila);
void buscar_en_pila(Nodo* pila, int num);
int contar_ocurrencias(Nodo* pila, int num);
void separar_pares_e_impares(Nodo*& pila, Nodo*& pares, Nodo*& impares);

// FUNCIÓN PRINCIPAL
int main() {
    Nodo* pila = nullptr; // Pila principal
    Nodo* pares = nullptr; // Pila para números pares
    Nodo* impares = nullptr; // Pila para números impares
    int numero;

    cout << "Ingresar valor (negativo para terminar): ";
    cin >> numero;

    while (numero >= 0) {
        agregar_a_pila(pila, numero);
        cout << "Ingresar valor (negativo para terminar): ";
        cin >> numero;
    }

    // Imprimir la pila original
    cout << "\nContenido de la pila:\n";
    imprimir_pila(pila);

    // A. Buscar un número en la pila
    cout << "\nIngresar número para verificar su existencia: ";
    cin >> numero;
    buscar_en_pila(pila, numero);

    // B. Contar ocurrencias de un número en la pila
    cout << "\nIngresar número para contar ocurrencias: ";
    cin >> numero;
    int ocurrencias = contar_ocurrencias(pila, numero);
    if (ocurrencias == 1)
    {
        cout << "El número " << numero << " aparece " << ocurrencias << " vez en la pila.\n";
    } else if (ocurrencias > 1)
    {
        cout << "El número " << numero << " aparece " << ocurrencias << " veces en la pila.\n";
    } else {
        cout<<"El número ingresado no está en la pila.\n";
    }
    
    

    // C. Separar en listas de pares e impares
    separar_pares_e_impares(pila, pares, impares);

    // Imprimir pilas resultantes
    cout << "\nPila de números pares:\n";
    imprimir_pila(pares);

    cout << "\nPila de números impares:\n";
    imprimir_pila(impares);

    return 0;
}

// FUNCIONES

// Agregar elemento a la pila
void agregar_a_pila(Nodo*& pila, int num) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = num;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

// Imprimir todos los elementos de la pila
void imprimir_pila(Nodo* pila) {
    Nodo* actual = pila;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

// A. Buscar un número en la pila
void buscar_en_pila(Nodo* pila, int num) {
    Nodo* actual = pila;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->dato == num) {
            cout << "El número " << num << " se encuentra en la pila.\n";
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        cout << "El número " << num << " NO se encuentra en la pila.\n";
    }
}

// B. Contar ocurrencias de un número en la pila
int contar_ocurrencias(Nodo* pila, int num) {
    Nodo* actual = pila;
    int contador = 0;

    while (actual != nullptr) {
        if (actual->dato == num) {
            contador++;
        }
        actual = actual->siguiente;
    }
    return contador;
}

// C. Separar números pares e impares en pilas diferentes y vaciar la pila original
void separar_pares_e_impares(Nodo*& pila, Nodo*& pares, Nodo*& impares) {
    while (pila != nullptr) {
        Nodo* actual = pila;
        pila = pila->siguiente;

        if (actual->dato % 2 == 0) {
            actual->siguiente = pares;
            pares = actual;
        } else {
            actual->siguiente = impares;
            impares = actual;
        }
    }
}
//------------------------------------------------------------------------
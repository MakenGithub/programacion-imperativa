// Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
// debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
// versiones, insertando en cada una con diferente criterio, a saber:
// a) Al inicio de la lista.
// b) Al final de la lista.
// c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
// se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
// Finalmente, imprimir la lista.

//Descripción del programa

// META DATA
#include <iostream>
#include <limits>       // Para std::numeric_limits
#include <string>      // Para el uso de strings
#include <fstream>      //Para manejo de archivos

using namespace std;

// VARIABLES GLOBALES Y CONSTANTES

// ESTRUCTURAS
struct Nodo
{
    int dato;
    Nodo* siguiente;
};


// DECLARACIÓN DE FUNCIONES
void insertar_al_inicio(Nodo* &lista, int valor);
void insertar_al_final(Nodo* &lista, int valor);
void insertar_en_orden(Nodo* &lista, int valor);
void imprimir_lista(Nodo* lista);

// FUNCION PRINCIPAL
int main() {
    Nodo* lista = NULL;
    int valor;
    
    cout << "Ingresar valor (0 para finalizar): ";
    cin >> valor;

    while (valor != 0) {
        // Cambia la llamada según el tipo de inserción deseada
        // insertar_al_inicio(lista, valor);
        // insertar_al_final(lista, valor);
        insertar_en_orden(lista, valor);

        cout << "Ingresar valor: ";
        cin >> valor;
    }

    imprimir_lista(lista);
}

//DEFINICIÓN DE FUNCIONES
// Insertar al inicio
void insertar_al_inicio(Nodo* &lista, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
}

// Insertar al final
void insertar_al_final(Nodo* &lista, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevoNodo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}

// Insertar en orden ascendente
void insertar_en_orden(Nodo* &lista, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;

    Nodo* aux1 = lista;
    Nodo* aux2 = NULL;

    while (aux1 != NULL && aux1->dato < valor) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (aux1 == lista) {
        lista = nuevoNodo;
    } else {
        aux2->siguiente = nuevoNodo;
    }

    nuevoNodo->siguiente = aux1;
}

// Imprimir la lista
void imprimir_lista(Nodo* lista) {
    Nodo* actual = lista;
    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}
//------------------------------------------------------------------------
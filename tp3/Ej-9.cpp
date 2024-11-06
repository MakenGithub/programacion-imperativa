// Desarrollar un programa que realice las siguientes operaciones en listas enlazadas simples de números enteros.
// A. Cargar una lista insertando los elementos ordenados en forma descendente. Finaliza luego de ingresar
// el cero, que también se debe agregar a la lista.
// B. Eliminar las ocurrencias de los números que son múltiplos de 3.
// C. Imprimir la lista antes y después de la eliminación.

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
    int numero;
    Nodo* siguiente;
};

// DECLARACIÓN DE FUNCIONES
//Cargar lista de forma descendente
void agregar_a_lista_descendente(Nodo* &lista, int numero);

//Eliminar ocurrencias de los números que son múltiplos de 3
void eliminar_multiplos_de_3(Nodo* &lista);

//Imprimir lista
void imprimir_lista(Nodo* lista);

// FUNCION PRINCIPAL
int main() {
    // Variables
    Nodo* lista = nullptr;
    int numero = -1;

    cout<<"Cargar lista con valores enteros..."<<endl;

    while (numero != 0)
    {
        cout<<"Ingresar numero: ";
        cin>>numero;
        agregar_a_lista_descendente(lista, numero);
    }
    cout<<"La lista se cargó de forma descendente..."<<endl;
    imprimir_lista(lista);
    cout<<endl;

    cout<<"Eliminando valores múltiplos de 3...";
    eliminar_multiplos_de_3(lista);
    cout<<"Lista final: "<<endl;
    imprimir_lista(lista);
    cout<<endl;

    return 0;
}

//DEFINICIÓN DE FUNCIONES
//Cargar lista de forma descendente
void agregar_a_lista_descendente(Nodo* &lista, int numero){
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->numero = numero;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr || lista->numero <= numero)
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    } else {
        Nodo* actual = lista;
        while (actual->siguiente != nullptr && actual->siguiente->numero > numero)
        {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

//Eliminar ocurrencias de los números que son múltiplos de 3
void eliminar_multiplos_de_3(Nodo* &lista){
    Nodo* actual = lista;
    Nodo* anterior = nullptr;

    while (actual != nullptr)
    {
        if (actual->numero % 3 == 0)
        {
            if (actual == lista)    //Si es el primer Nodo de la lista
            {
                lista = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            Nodo* nodoAEliminar = actual;
            actual = actual->siguiente;
            delete nodoAEliminar;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

//Imprimir lista
void imprimir_lista(Nodo* lista){
    Nodo* actual = lista;
    while (actual != nullptr) {
        cout << actual->numero << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

//------------------------------------------------------------------------
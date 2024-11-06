// Implementar una función que reciba dos parámetros: una lista enlazada simple de números enteros y un
// número entero. La función debe eliminar todas las ocurrencias del número indicado en el segundo parámetro.
// Retornar la cantidad de ocurrencias eliminadas. Nota: se debe pasar una sola vez por cada uno de los
// elementos de la lista.

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
void agregar_a_lista(Nodo* &lista, int numero);
int eliminar_ocurrencias(Nodo* &lista, int numero);
void mostrar_lista(Nodo* lista);

// FUNCION PRINCIPAL
int main() {
    // Variables
    Nodo* lista = nullptr;
    int numero;
    char opcion;

    cout<<"Cargando lista enlazada..."<<endl;

    for (int i = 0; i < 10; i++)    //Agrega 10 valores a la lista
    {
        cout<<"Ingresar número: ";
        cin>>numero;
        agregar_a_lista(lista, numero);
    }

    mostrar_lista(lista);

    cout<<"\nEliminar ocurrencias de la lista..."<<endl;

    cout<<"Ingresar número a eliminar: ";
    cin>>numero;

    cout<<"El número fue hallado "<<eliminar_ocurrencias(lista, numero)<<" veces."<<endl
        <<"Se han eliminado sus ocurrencias de la lista"<<endl;

    cout<<"Mostrar lista? (S/N): ";
    cin>>opcion;

    opcion = toupper(opcion);
    if (opcion == 'S')
    {
        mostrar_lista(lista);
    }
    

    return 0;
}

//DEFINICIÓN DE FUNCIONES
void agregar_a_lista(Nodo* &lista, int numero){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = numero;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
}

int eliminar_ocurrencias(Nodo* &lista, int numero){
    int contador = 0;
    Nodo* actual = lista;
    Nodo* anterior = nullptr;

    while (actual != nullptr)
    {
        if (actual->dato == numero)
        {
            if (actual == lista)
            {
                lista = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            Nodo* nodoAEliminar = actual;
            actual = actual->siguiente;
            delete nodoAEliminar;
            contador++;
        } else {
            //Avanzar solo si no hubo eliminación
            anterior = actual;
            actual = actual->siguiente;
        }
    }
    return contador;
    
}

void mostrar_lista(Nodo* lista){
    Nodo* actual = lista;
    while (actual != nullptr)
    {
        cout<<actual->dato<<" -> ";
        actual = actual->siguiente;
    }
    cout<<endl;
}
//------------------------------------------------------------------------
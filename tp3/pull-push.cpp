// Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
// debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
// versiones, insertando en cada una con diferente criterio, a saber:
// a) Al inicio de la lista.
// b) Al final de la lista.
// c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
// se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
// Finalmente, imprimir la lista.


//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits
#include <stdlib.h>     //New y Delete

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES

// Definición de la estructura del nodo
struct Nodo {
    int dato;
    Nodo *siguiente; // Puntero al siguiente nodo
};


//DECLARACIÓN DE FUNCIONES
void agregar_a_pila(Nodo *&pila, int num);
void sacar_de_pila(Nodo *&pila, int &num);

//FUNCION PRINCIPAL
int main(){

    //Variables
    Nodo *pila = NULL;
    int dato;

    cout<<"Ingresar número: ";
    cin>>dato;
    agregar_a_pila(pila, dato);

    cout<<"Ingresar número: ";
    cin>>dato;
    agregar_a_pila(pila, dato);

    cout<<"\nSacando elementos de la pila..."<<endl;

    while (pila != NULL){
        sacar_de_pila(pila, dato);
        if (pila != NULL){
            cout<<dato<<" eliminado, "<<endl;
        } else {
            cout<<dato<<" eliminado.";
        }
        
    }
    

    return 0;
}

//DEFINICIÓN DE FUNCIONES
void agregar_a_pila(Nodo *&pila, int num){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = num;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

void sacar_de_pila(Nodo *&pila, int &num){
    Nodo *aux = pila;
    num = aux->dato;
    pila = aux->siguiente;
    delete aux;
}
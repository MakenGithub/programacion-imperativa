//Descripción del programa

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES

//ESTRUCTURAS
struct Nodo
{
    int dato;
    Nodo *siguiente;
};


//DECLARACIÓN DE FUNCIONES
void agregar_a_pila(Nodo *&pila, int dato);
void sacar_de_pila(Nodo *&pila, int &dato);
char verificar_opcion(char opcion);

//FUNCION PRINCIPAL
int main(){

    //Variables
    Nodo *pila = NULL;
    int dato;
    char opcion;

    do
    {
        cout<<"Ingresar un valor: ";
        cin>>dato;
        agregar_a_pila(pila, dato);

        cout<<"Agregar otro valor?(S/N): ";
        opcion = verificar_opcion(opcion);

    } while (opcion != 'N');

    cout<<"\nEliminando datos de la pila..."<<endl;

    while (pila != NULL)
    {
        sacar_de_pila(pila, dato);
        if (pila != NULL)
        {
            cout<<dato<<" eliminado, ";
        } else {
            cout<<dato<<" eliminado.";
        }
        
    }
    
    

    return 0;
}

//DEFINICIÓN DE FUNCIONES
void agregar_a_pila(Nodo *&pila, int dato){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout<<"Elemento "<<dato<<" agregado a la pila.\n";
}

void sacar_de_pila(Nodo *&pila, int &dato){
    Nodo *aux = pila;
    dato = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

//VERIFICACIONES
char verificar_opcion(char opcion){
    cin>>opcion;
    opcion = toupper(opcion);
    while (opcion != 'S' && opcion != 'N')
    {
        cout<<"Ingresar opción válida (S/N): ";
        cin>>opcion;
        opcion = toupper(opcion);
    }

    return opcion;
    
}
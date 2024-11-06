//Descripción del programa

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits
#include <cstdlib>

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES

//ESTRUCTURAS
struct Nodo
{
    int dato;
    Nodo *siguiente;
};


//DECLARACIÓN DE FUNCIONES
void insertar_a_cola(Nodo *&frente, Nodo *&fin, int num);
void eliminar_de_cola(Nodo *&frente, Nodo *&fin, int &num);
bool verificar_cola(Nodo *frente);
char verificar_opcion(char opcion);

//FUNCION PRINCIPAL
int main(){

    //Variables
    Nodo *frente = NULL, *fin = NULL;
    int dato;
    char opcion;

    do
    {
        cout<<"Ingresar un valor: ";
        cin>>dato;
        insertar_a_cola(frente, fin, dato);

        cout<<"Agregar otro valor?(S/N): ";
        opcion = verificar_opcion(opcion);

        system("cls");

    } while (opcion != 'N');

    cout<<"\nEliminando elementos de la cola..."<<endl;
    while (frente != NULL)
    {
        eliminar_de_cola(frente, fin, dato);
        if (frente != NULL)
        {
            cout<<dato<<" eliminado, ";
        } else {
            cout<<dato<<" eliminado.";
        }
        
    }
    

    return 0;
}

//DEFINICIÓN DE FUNCIONES
void insertar_a_cola(Nodo *&frente, Nodo *&fin, int num){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = num;
    nuevo_nodo->siguiente = NULL;

    if (verificar_cola(frente)){
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;

    cout<<"Elemento "<<num<<" agregado.\n";
}

void eliminar_de_cola(Nodo *&frente, Nodo *&fin, int &num){
    num = frente->dato;
    Nodo *aux = frente;

    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente;
    }
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

//Determinar si la cola está vacía o no
bool verificar_cola(Nodo *frente){
    return (frente == NULL)? true : false;
}
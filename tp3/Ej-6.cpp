// Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso, insertando al
// final de la lista y cortando la carga cuando se inserte como nombre "x", ya sea en mayúscula o en minúscula (el
// cual no debe insertarse en la lista).
// A continuación, solicitar al usuario el nombre de un alumno e informar si se encuentra en la lista o no.
// Por último, eliminar a la alumna "Josefina Ortega" de la lista (se asume que no se han almacenado nombres
// repetidos).

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
    string nombre;
    Nodo* siguiente;
};


// DECLARACIÓN DE FUNCIONES
void insertar_al_final(Nodo* &lista, string nombre);
void buscar_alumno(Nodo* lista, string nombre);
void eliminar_alumno(Nodo* &lista, string nombre);
void imprimir_lista(Nodo* lista);

// FUNCION PRINCIPAL
int main() {
    // Variables
    string nombre;
    Nodo* lista = NULL;
    char opcion;

    cout<<"Ingresar nombre: ";
    getline(cin >> ws, nombre);

    while (nombre != "x" && nombre != "X")
    {
        insertar_al_final(lista, nombre);
    
        cout<<"Ingresar nombre: ";
        getline(cin >> ws, nombre);
    }

    cout<<"Buscar un alumno? (S/N): ";
    cin>>opcion;
    opcion = toupper(opcion);

    if (opcion == 'S')
    {
        cout<<"Ingresar nombre: ";
        getline(cin >> ws, nombre);
        buscar_alumno(lista, nombre);
    }

    cout<<"Eliminar alumno especifico de la lista..."<<endl;
    eliminar_alumno(lista, "Josefina Ortega");
    

    cout<<"Imprimir lista? (S/N): ";
    cin>>opcion;
    opcion = toupper(opcion);

    if (opcion == 'S')
    {
        imprimir_lista(lista);
    }
    


    return 0;
}

//DEFINICIÓN DE FUNCIONES
//Insertar al final de la lista
void insertar_al_final(Nodo* &lista, string nombre){
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->nombre = nombre;
    nuevoNodo->siguiente = NULL;

    if (lista == NULL)
    {
        lista = nuevoNodo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}

//Buscar alumno en la lista enlazada
void buscar_alumno(Nodo* lista, string nombre){
    Nodo* actual = lista;
    bool encontrado = false;

    while (actual != NULL)
    {
        if (actual->nombre == nombre)
        {
            cout<<"El alumno "<<nombre<<" se encuentra en la lista."<<endl;
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrado)
    {
        cout<<"El alumno "<<nombre<<" NO se encuentra en la lista."<<endl;
    }
}

//Eliminar un alumno específico de la lista
void eliminar_alumno(Nodo* &lista, string nombre){
    if (lista == NULL)
    {
        cout<<"La lista está vacía..."<<endl;
        return;
    }

    Nodo* actual = lista;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->nombre != nombre)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    //Si se encuentra el Nodo
    if (actual != NULL)     //Si es el primer Nodo de la lista
    {
        if (anterior == NULL)
        {
            lista = actual->siguiente;
        } else {            //Si está en el medio o al final
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
        cout<<"El alumno "<<nombre<<" ha sido eliminado de la lista."<<endl;
    } else {
        cout<<"El alumno "<<nombre<<" no se encuentra en la lista."<<endl;
    }

    

}

//Imprimir lista
void imprimir_lista(Nodo* lista){
    Nodo* actual = lista;
    int i = 0;
    while (actual != NULL)
    {
        cout<<i + 1<<". "<<actual->nombre<<endl;
        actual = actual->siguiente;
        i++;
    }
    cout<<"\033[32mFin de la lista\033[0m";
}
//------------------------------------------------------------------------
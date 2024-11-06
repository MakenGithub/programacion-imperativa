#include <iostream>
#include <string>
using namespace std;

int main(){
    string nombre;
    int cantidadLetras;
    int posicion;
    //Depuración y prueba de algoritmos:
    cout<<"Nombre: ";
    getline(cin >> ws, nombre);
    cantidadLetras = nombre.length();

    for (int i = 0; i < cantidadLetras; i++)
    {
        nombre[0] = toupper(nombre[0]);
        nombre[i] = tolower(nombre[i]);
    }

    cout<<nombre;

    return 0;
}
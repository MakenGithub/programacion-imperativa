// Escribe un programa que busque un número en una matriz dada y devuelva su posición. Si el número no se
// encuentra, debe indicarlo.

//META DATA
#include <iostream>
using namespace std;

//CONSTANTES Y GLOBALES
const int ELEMENTOS = 10;
int matriz[ELEMENTOS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int numero, posicion = -1;

//DECLARACION DE FUNCIONES
bool encontrar_valor(int numero);

//FUNCION PRINCIPAL
int main(){

    cout<<"El programa indicará la posición en el arreglo del valor buscado por el usuario."<<endl
        <<"También informará en caso de no haberlo encontrado.\n"<<endl;

    cout<<"Ingrese el valor buscado: ";
    cin>>numero;

    if (encontrar_valor(numero))
    {
        cout<<"El valor "<<numero<<" se halló en la posición "<<(posicion);
    } else {
        cout<<"No se encontró el valor solicitado.";
    }
    


    return 0;
}


//DEFINICION DE FUNCIONES
bool encontrar_valor(int numero){
    for (int i = 0; i < ELEMENTOS; i++)
    {
        if (matriz[i] == numero)
        {   
            posicion = i;
            return true;
        }
        
    }
    return false;
}
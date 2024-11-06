// Escribe un programa que imprima un cuadrado de asteriscos de tamaño `n x n`, donde `n` es un número
// ingresado por el usuario.

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES
const char ASTERISCO = '*';
int cuadricula = 0;

//DECLARACIÓN DE FUNCIONES
void crear_cuadricula();
int verificar_valor();

//FUNCION PRINCIPAL
int main(){

    //Variables

    cout<<"Ingrese valor para la altura y anchura de la cuadrícula: ";
    cuadricula = verificar_valor();  //Ingresar valor positivo

    crear_cuadricula();


    return 0;
}

//DEFINICIÓN DE FUNCIONES

//VERIFICAR VALOR POSITIVO
int verificar_valor(){
    while(true){
        cin>>cuadricula;
        
        // Verificar si la entrada es válida
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la línea
            cout << "Entrada no válida. Por favor ingrese un número entero positivo: ";
        } else if (cuadricula > 0) {
            break; // Salir del bucle si el número es positivo
        } else {
            cout << "Ingrese un número positivo: ";
        }
    }
    
    return cuadricula;
}

//Crea una cuadricula con el valor ingresado por el usuaio
void crear_cuadricula(){
    //Variables
    int j, i;

    for (i = 0; i < cuadricula; i++)
    {
        for (j = 0; j < cuadricula; j++)
        {
            cout<<ASTERISCO<<" ";
        }
        
        cout<<endl;
    }
    
}
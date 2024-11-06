//El programa imprimirá en pantalla la tabla de multiplicación de los números del 1 al 10

//META DATA
#include <iostream>
using namespace std;

//VARIABLES GLOBALES
const int TOPE_TABLA = 10;
const int TOPE_MULTIPLICAR = 10;

//DECLARACIÓN DE FUNCIONES
void tablas_de_multiplicacion();

//FUNCIÓN PRINCIPAL
int main(){

    tablas_de_multiplicacion();

    system("pause > null");

    return 0;
}

//DEFINICIÓN DE FUNCIONES
void tablas_de_multiplicacion(){
    //Variables
    int i, j;

    for (i = 1; i <= TOPE_TABLA; i++)
    {
        cout<<"Tabla del "<<i<<": "<<endl;
        for (j = 1; j <= TOPE_MULTIPLICAR; j++)
        {
            cout<<i<<" x "<<j<<" = "<<i*j<<endl;
        }

        cout<<endl;
        
    }
}

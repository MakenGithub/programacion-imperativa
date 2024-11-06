// Escribir las sentencias necesarias para:
// A. Declarar un matriz de enteros de 7 filas y 10 columnas
// B. Asignar el valor 105 a la posición que se encuentra en la segunda fila, quinta columna.
// C. Asignar en todas las posiciones de la cuarta fila el valor 5.
// D. Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
// E. Permutar las columnas 3 y 5.
// F. Sumar todos los elementos de las filas 2 y 6.
// G. Imprimir todos los valores de la tercera columna.
// H. Hallar en qué fila y columna se encuentra almacenado el mayor elemento.

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES
const int FILAS = 7, COLUMNAS = 10;
int matriz[FILAS][COLUMNAS];     //7 filas, 10 columnas

//DECLARACIÓN DE FUNCIONES
void imprimir_matriz();

//FUNCION PRINCIPAL
int main(){

    //Variables
    int f, c;

    // B. Asignar el valor 105 a la posición que se encuentra en la segunda fila, quinta columna.
    matriz[1][4] = 105;    

    // C. Asignar en todas las posiciones de la cuarta fila el valor 5.
    for (f = 3; f < 4; f++)
    {
        for (c = 0; c < COLUMNAS; c++)
        {
            matriz[f][c] = 5;
        }
        
    }

    // D. Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
        //imprimir_matriz();

    // E. Permutar las columnas 3 y 5.
    

    return 0;
}

//DEFINICIÓN DE FUNCIONES

//Imrpimir la matriz "matriz"
void imprimir_matriz(){
    for (int f = 0; f < FILAS; f++)
    {
        for (int c = 0; c < COLUMNAS; c++)
        {
            cout<<matriz[f][c]<<" | ";
        }

        cout<<endl;
        
    }
}
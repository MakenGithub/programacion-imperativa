//Escribe un programa que sume dos matrices de 3x3 y muestre la matriz resultante

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES
const int MATRIZ_1[3][3] = {1, 3, 5,
                            4, 6, 8,
                            9, 8, 5};
                            
const int MATRIZ_2[3][3] = {1, 3, 5,
                            4, 6, 8,
                            9, 8, 5};
int total_matriz[3][3];

//DECLARACIÓN DE FUNCIONES
void sumar_matrices();
void imprimir_total_matriz();

//FUNCION PRINCIPAL
int main(){

    sumar_matrices();
    imprimir_total_matriz();

    return 0;
}

//DEFINICIÓN DE FUNCIONES
//Suma ambas matrices y almacena en total_matriz
void sumar_matrices(){
        //Variables
    int i, j;

        for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            total_matriz[i][j] = (MATRIZ_1[i][j] + MATRIZ_2[i][j]);
        }
        
    }
}

//Imprime matriz resultante
void imprimir_total_matriz(){
        for (int imp = 0; imp < 3; imp++)
    {
        for (int imp2 = 0; imp2 < 3; imp2++)
        {
            cout<<total_matriz[imp][imp2]<<", ";
        }

        cout<<endl;
        
    }
}
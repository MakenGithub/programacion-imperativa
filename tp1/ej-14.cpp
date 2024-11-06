// Una matriz cuadrada A se dice que es simétrica si A(i,j) = A(j,i) para todo i, j. Escribir un programa que decida si
// una matriz dada es o no simétrica.
// Una crotada lo que escribieron osea si los lados son iguales y también todos sus índices

//META DATA
#include <iostream>
using namespace std;

//CONSTANTES Y GLOBALES
const int FILAS = 3, COLUMNAS = 3;
int matriz[FILAS][COLUMNAS];
int i, j;

//DECLARACION DE FUNCIONES
void rellenar_matriz();
void mostrar_matriz();
bool verificar_simetria();

//FUNCION PRINCIPAL
int main(){

    //Variables

    cout<<"Una matriz es simétrica cuando tiene el mismo número de filas y columnas"<<endl
        <<"y además sus valores coinciden al momento de invertir filas por columnas:\n"<<endl;

    rellenar_matriz();
    mostrar_matriz();

    if (FILAS == COLUMNAS)
    {
        if(verificar_simetria()){
            cout<<"\nLa matriz es simétrica";
        }
        else {
            cout<<"\nLa matriz no es simétrica";
        }
    }
    

    return 0;
}


//DEFINICION DE FUNCIONES

//Número de FILAS y COLUMNAS y el contenido de cada índice

int numero;
void rellenar_matriz(){
    cout<<"Valores enteros para la matriz de "<<FILAS<<" x "<<COLUMNAS<<": \n";
    for (i = 0; i < FILAS; i++)
    {
        for (j = 0; j < COLUMNAS; j++)
        {
            cout<<"Ingrese valor ["<<i<<"]["<<j<<"]: ";
            cin>>numero;
            matriz[i][j] = numero;
        }
        cout<<endl;
        
    }
    
}

void mostrar_matriz(){
    cout<<"Matriz "<<FILAS<<" x "<<COLUMNAS<<" resultante:\n"<<endl;
    for (i = 0; i < FILAS; i++)
    {
        for (j = 0; j < COLUMNAS; j++)
        {
            cout<<"| "<<matriz[i][j]<<" | ";
        }

        cout<<endl;   
    }
}

//Es verdadero si la matriz invertida coincide en índices y dimensión con la matriz original
bool verificar_simetria(){
        for (i = 0; i < FILAS; i++)
        {
            for (j = 0; j < COLUMNAS; j++)
            {
                if (matriz[i][j] != matriz[j][i])
                {
                    cout<<"Valor ["<<i<<"]["<<j<<"]: No coincide. ("<<matriz[i][j]<<" != "<<matriz[j][i]<<")\n";
                    return false;
                } else {
                    cout<<"Valor ["<<i<<"]["<<j<<"]: Coincide. ("<<matriz[i][j]<<" = "<<matriz[j][i]<<")\n";
                }
            }
            cout<<endl;
        }
        
        return true;
}
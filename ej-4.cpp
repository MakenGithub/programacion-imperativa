// Cargar un arreglo con 10 números enteros ingresados por teclado de manera que el arreglo siempre se 
// encuentre ordenado en forma ascendente. El arreglo se cargará por completo. 
// Hacer dos variantes, suponiendo que el usuario carga los datos de las siguientes formas: 
// a) El usuario ingresa los números en orden ascendente (Inserción al final) 
// b) El usuario ingresa los números sin un orden en particular (Inserción ordenada)

//META DATA
#include <iostream>
using namespace std;

//CONSTANTES Y GLOBALES
const int DIMENSION_FISICA = 10;
int datosDeUsuario[DIMENSION_FISICA];
int dimensionLogica = 0;
int valorAleatorio = datosDeUsuario[0];

// FUNCION PRINCIPAL
int main() {
    int valorAleatorio;
    
    while (dimensionLogica < DIMENSION_FISICA) {
        cout << "Ingresar valor n°" << dimensionLogica + 1 << ": ";
        cin >> valorAleatorio;

        // Encontrar la posición correcta para el nuevo valor
        int pos = 0;
        while (pos < dimensionLogica && datosDeUsuario[pos] < valorAleatorio) {
            pos++;
        }

        // Desplazar los elementos para hacer espacio
        for (int i = dimensionLogica; i > pos; i--) {
            datosDeUsuario[i] = datosDeUsuario[i - 1];
        }

        // Insertar el nuevo valor en la posición correcta
        datosDeUsuario[pos] = valorAleatorio;
        dimensionLogica++;

    }
        // Mostrar el arreglo actual
        cout << "Arreglo ordenado: ";
        for (int i = 0; i < dimensionLogica; i++) {
            cout << datosDeUsuario[i] << " ";
        }
        cout << endl;

    return 0;
}
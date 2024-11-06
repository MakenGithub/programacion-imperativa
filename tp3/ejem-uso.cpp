#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> size;

    // Crear arreglo dinámico
    int* arr = new int[size];
    
    // Asignar valores al arreglo
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    // Mostrar valores
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Liberar la memoria
    delete[] arr;
    
    return 0;
}
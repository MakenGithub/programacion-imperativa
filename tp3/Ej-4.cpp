//Descripción del programa:
// Escribir y luego ejecutar las instrucciones necesarias para:
// a) Declarar una variable puntero a Venta y reservar memoria.
// b) Pedir al usuario que ingrese una cantidad vendida, descripción de producto y precio de producto,
// almacenando los datos en la Venta apuntada por el puntero declarado en el inciso anterior.
// c) Restar un 15% al precio del Producto guardado en la Venta apuntada por el puntero.
// d) Imprimir la descripción del producto dentro de la Venta y monto total (precio del producto * cantidad).


// META DATA
#include <iostream>
#include <limits>       // Para std::numeric_limits
#include <string>      // Para el uso de strings
#include <fstream>      //Para manejo de archivos

using namespace std;

// VARIABLES GLOBALES Y CONSTANTES
const float DESCUENTO = 0.15f;

// ESTRUCTURAS
struct Producto {
    string descripcion;
    float precio;
};

struct Venta {
    Producto producto;
    int cantidad;
};


// DECLARACIÓN DE FUNCIONES


// FUNCION PRINCIPAL
int main() {
    // Variables
    // A)
    Venta* ventaPtr = new Venta;

    cout<<"Ingresar cantidad vendida: ";
    cin>>ventaPtr->cantidad;

    cout<<"Ingresar descripción del producto: ";
    getline(cin >> ws, ventaPtr->producto.descripcion);

    cout<<"Ingresar precio del producto: ";
    cin>> ventaPtr->producto.precio;

    cout<<"\nDatos ingresados:"<<endl;
    cout<<"Cantidad: "<<ventaPtr->cantidad<<endl;
    cout<<"Descripción: "<<ventaPtr->producto.descripcion<<endl;
    cout<<"Precio: "<<ventaPtr->producto.precio<<endl;

    // Aplicar descuento del 15% al precio del producto
    ventaPtr->producto.precio -= ventaPtr->producto.precio * DESCUENTO;
    cout<<"Precio con descuento (15%): "<<ventaPtr->producto.precio<<endl;

    float montoTotal = ventaPtr->cantidad * ventaPtr->producto.precio;
    cout << "\nDescripción del producto: " << ventaPtr->producto.descripcion << endl;
    cout << "Monto total de la venta: $" << montoTotal << endl;

    delete ventaPtr;


    return 0;
}

//DEFINICIÓN DE FUNCIONES
//------------------------------------------------------------------------
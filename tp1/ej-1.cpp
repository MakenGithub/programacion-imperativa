// Escribe un programa que solicite al usuario ingresar un carácter y un número entero positivo. Luego imprime en
// pantalla un triángulo formado por el carácter ingresado, con altura igual al número que se ingresó.

//META DATA
#include <iostream>
#include <limits> //Para std::numeric_limits

using namespace std;

//CONSTANTES Y GLOBALES
int altura = 0;
char caracter;

//DECLARACIÓN DE FUNCIONES
void piramyd_mk(char caracter, int altura);
int verificar_altura();
char verificar_caracter();

//FUNCIÓN PRINCIPAL
int main(){

    //Variables-------
    //----------------

    cout<<"El siguiente programa mostrará en pantalla una piramide"<<endl;

    //ALTURA
    altura = verificar_altura();  //Ingresar valor positivo

    //CUERPO
    caracter = verificar_caracter();

    piramyd_mk(caracter, altura);

    return 0;
}


//DEFINICIÓN DE FUNCIONES

//Verificar que el valor ingresado para la altura sea un numero positivo
int verificar_altura(){
    cout<<"Ingresar la altura: ";
    while(true){
        cin>>altura;
        
        // Verificar si la entrada es válida
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la línea
            cout << "Entrada no válida. Por favor ingrese un número entero positivo: ";
        } else if (altura > 0) {
            break; // Salir del bucle si el número es positivo
        } else {
            cout << "Ingrese un número positivo: ";
        }
    }
    
    return altura;
}

// Verificar que solo se ingrese un carácter
char verificar_caracter() {
    string input;

    cout<<"Ingrese un carácter."<<endl
        <<"Este constituye el cuerpo de la pirámide: ";

    while(true){
        cin >> input;

        if (input.length() == 1) {
            caracter = input[0]; // Tomar el único carácter
            break;
        } else {
            cout<<"Por favor, ingrese solo un carácter."<<endl;
        }
    }

    return caracter;
}

//Construye la piramide con los datos ingresados por el usuario
void piramyd_mk(char caracter, int altura){
    int i, j;

    for (i = 1; i <= altura; i++)
    {
        for (j = 0; j < i; j++)
        {
            cout<<caracter;
        }
        cout<<endl;       
    }
    
}
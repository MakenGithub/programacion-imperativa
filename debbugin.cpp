//Debuggin input char in a int buffer

//META DATA
#include <iostream>
using namespace std;

//Funcion principal
int main(){

    int num = 0;

    cout<<"Ingresar valor positivo: ";
    cin>>num;

    //Verificar número positivo
    while (num <= 0)
    {
        cout<<"Ingrese número válido: ";
        cin>>num;
    }
    
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------
// #include <iostream>
// #include <limits> // Para std::numeric_limits
// using namespace std;

//int main() {
//     int num = 0;

//     cout << "Ingresar valor positivo: ";
//     while (true) {
//         cin >> num;
        
//         // Verificar si la entrada es válida
//         if (cin.fail()) {
//             cin.clear(); // Limpiar el estado de error de cin
//             cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la línea
//             cout << "Entrada no válida. Por favor ingrese un número entero positivo: ";
//         } else if (num > 0) {
//             break; // Salir del bucle si el número es positivo
//         } else {
//             cout << "Ingrese un número positivo: ";
//         }
//     }
    
//     cout << "Número ingresado: " << num << endl;
    
//     // Pausar la ejecución
//     cout << "Presione Enter para salir...";
//     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
//     cin.get(); // Esperar una entrada del usuario
    
//     return 0;
// }
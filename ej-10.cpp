// Escribir un programa que permita al usuario gestionar los pagos de la cuota de un club. Para ello, almacenar en 
// un arreglo los números de DNI de los socios que pagaron. El club no tiene más de 200 socios. 
// Permitir al usuario buscar un DNI en el arreglo y, si el DNI está en el arreglo, imprimir "Cuota al día". Si no está, 
// imprimir "Socio con deuda". 
// También se debe permitir al usuario eliminar un DNI del arreglo, en caso de haberlo ingresado erróneamente. 
// Finalmente, imprimir todo el arreglo

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES
const int DF = 200;
int DL = 0;
const int sociosClub[DF] = {2356789, 456321, 987456, 1234567, 7654321,
321654, 7896543, 654987, 876123, 9988776,
2348765, 987321, 543987, 321789, 567123,
765987, 876432, 123654, 789123, 654321,
765987, 897456, 765321, 654789, 789654};

//DECLARACIÓN DE FUNCIONES
void comprobar_pago();
void eliminar_usuario();
void imprimir_usuarios();

//FUNCION PRINCIPAL
int main(){

    //Variables

    return 0;
}

//DEFINICIÓN DE FUNCIONES

//Comprueba un DNI en el arreglo y comprueba si tiene deuda de cuota
void comprobar_pago(){

}

//Elimina un DNI del arreglo en caso de haber sido agregado erroneamente
void eliminar_usuario(){

}

//Muestra los usuarios socios del club almacenados en el arreglo
void imprimir_usuarios(){

}
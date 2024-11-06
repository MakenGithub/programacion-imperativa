// Implementar la función Buscar elemento que reciba un arreglo de números enteros, su dimensión lógica y un
// número por parámetro e indique si dicho número existe en el arreglo.

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits
#include <string>

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES
const int DIMENSION_FISICA = 10;
int enteros[DIMENSION_FISICA] = {1, 4, 8,
                                4, 5, 6,
                                23, 31, 43};
int dimensionLogica = 0;

int numero = 0;

//DECLARACIÓN DE FUNCIONES
bool buscar_elemento(int numero);

//FUNCION PRINCIPAL
int main(){

    //Variables

    cout<<"Ingrese valor buscado: ";
    cin>>numero;

    buscar_elemento(numero);

    return 0;
}

//DEFINICIÓN DE FUNCIONES

bool buscar_elemento(int numero){

  for (int i = 0; i < DIMENSION_FISICA; i++)
  {
    if (numero == enteros[i])
    {
      cout<<"Existe el valor "<<numero<<" en el arreglo.";
      return true;
    }
    
  }
  
  cout<<"No existe el valor "<<numero<<" en el arreglo.";
  return false;
}
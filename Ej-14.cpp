// Generar una lista con los datos personales de los alumnos de un colegio (legajo, apellido y nombre, DNI) y las
// notas de tres materias: matemática, literatura y geografía (para cada alumno se cargarán las tres materias). Las
// notas pueden ir de 1 a 10 y se debe validar que el usuario no ingrese notas incorrectas, volviendo a pedir una
// nueva nota cada vez que ingrese una incorrecta, hasta que ingrese un valor en el rango indicado. Se pide
// informar la cantidad de alumnos que aprobaron las tres materias (se aprueba con 7) y el porcentaje que
// representan los aprobados sobre el total de alumnos.

// META DATA
#include <iostream>
#include <limits>       // Para std::numeric_limits
#include <string>      // Para el uso de strings
#include <fstream>      //Para manejo de archivos

using namespace std;

// VARIABLES GLOBALES Y CONSTANTES
string materias[3] = {"Matemática", "Literatura", "Geografía"};
float cantidadDeAlumnos = 0;

// for (int i = 0; i < 3; i++)
// {
//     cout<<"Nota de "<<materias[i]<<": ";
//     cin>>alumnos.notas[i];
// }


// ESTRUCTURAS
    //Estructura Alumno
    struct Alumno
    {
        int legajo;
        string nombre;      //Para nombre y apellido
        int dni;
        int notas[3];
    };

    //Estructura Nodo
    struct Nodo
    {
        Alumno alumnos;
        Nodo* siguiente;
    };
    
    

// DECLARACIÓN DE FUNCIONES
//Agregar alumnos a la lista con sus respectivos datos cargados
void agregar_a_lista(Nodo* &lista, Alumno alumnos);

//Validar que "nota" se encuentre en el rango [1 - 10]
int validar_nota(int nota);

//Verificar estado de alumno (desaprobado = 0 / aprobado = 1)
bool verificar_estado(Alumno alumnos);

//Generar informe de estado de alumnos aprobados y desaprobados
float generar_informe(Nodo* lista);

// FUNCION PRINCIPAL
int main() {
    // Variables
    Alumno alumnos;
    Nodo* lista = nullptr;
    int numLegajo, nota;
    float aprobados;

    cout<<"Cargar datos de alumnos en la lista..."<<endl;

    cout<<"N° de Legajo (0 para salir): ";
    cin>>numLegajo;

    while (numLegajo != 0)
    {
        alumnos.legajo = numLegajo;

        cout<<"Nombre y apellido: ";
        getline(cin >> ws, alumnos.nombre);

        cout<<"DNI: ";
        cin>>alumnos.dni;

        cout<<"Notas..."<<endl;
        for (int i = 0; i < 3; i++)
        {
            cout<<materias[i]<<": ";
            cin>>nota;
            validar_nota(nota);
            alumnos.notas[i] = nota;
        }

        agregar_a_lista(lista, alumnos);

        cout<<"N° de Legajo (0 para salir): ";
        cin>>numLegajo;
    }

    cout<<"Generando informe de aprobados..."<<endl;

    if (cantidadDeAlumnos > 0)
    {
        aprobados = generar_informe(lista);
    cout<<"Cantidad de alumnos: "<<cantidadDeAlumnos<<endl
        <<"Cantidad de alumnos APROBADOS: "<<aprobados<<endl
        <<"Estos representan un %"<<aprobados / cantidadDeAlumnos * 100<<"del total.";
    } else {
        cout<<"No hay alumnos en la lista."<<endl;
    }
    
    
    return 0;
}

//DEFINICIÓN DE FUNCIONES
//Agregar alumnos a la lista con sus respectivos datos cargados
void agregar_a_lista(Nodo* &lista, Alumno alumnos){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->alumnos = alumnos;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;

    cantidadDeAlumnos++;
}

//Validar que "nota" se encuentre en el rango [1 - 10]
int validar_nota(int nota){
    while (nota < 1 || nota > 10)
    {
        cout<<"Ingrese nota válida: ";
        cin>>nota;
    }
    return nota;
}

//Verificar estado de alumno (desaprobado = 0 / aprobado = 1)
bool comprobar_estado(Alumno &alumnos) {
    for (int i = 0; i < 3; i++) {
        if (alumnos.notas[i] < 7) {
            return false;
        }
    }
    return true;
}

//Generar informe de estado de alumnos aprobados y desaprobados
float generar_informe(Nodo* lista){
    float aprobados = 0;
    Nodo* actual = lista;

    while (actual != nullptr)
    {
        if (comprobar_estado(actual->alumnos))
        {
            aprobados++;
        }

        actual = actual->siguiente;
    }
    return aprobados;
}
//------------------------------------------------------------------------
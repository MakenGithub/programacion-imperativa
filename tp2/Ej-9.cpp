// Escribir un programa que almacene en un arreglo los datos de los alumnos de una escuela luego de finalizado el
// año académico. Como máximo, puede haber 5.000 alumnos. De cada alumno se debe guardar el nombre y la
// calificación obtenida en el primer, segundo y tercer trimestre del año académico. Imprimir el listado de nombres
// de alumnos mostrando un mensaje de "APTO" si el alumno supera o iguala la calificación de 5 para todas las
// notas o "NO APTO" si no lo alcanza. Utilizar un arreglo como campo del struct para almacenar las tres
// calificaciones

//META DATA
#include <iostream>
#include <limits>       //Para std::numeric_limits
#include <string>

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES
    //ESTRUCTURAS
    struct alumno
    {
        string nombre;
        int calificaciones[3];
    };

    const int DIMENSION_FISICA = 5000;
    int dimensionLogica = 0;

//DECLARACIÓN DE FUNCIONES
    //Cargar el arreglo con el nombre y las calificaciones de los estudiantes
    void cargar_arreglo(alumno alumnos[], int &dimensionLogica);
    void cargar_calificaciones(alumno alumnos[], int dimensionLogica);

    //Muestra en pantalla el nombre de los estudiantes y su estado segun sus notas
    void mostrar_aptitud(alumno alumnos[], int dimensionLogica);
    bool estado_final(alumno alumnos[], int dimensionLogica);

//FUNCION PRINCIPAL
int main(){

    //Variables
    alumno alumnos[DIMENSION_FISICA];
    char opcion;

    cout<<"MENU PRINCIPAL"<<endl;


    do
    {
        cout<<"Seleccione opcion..."<<endl
            <<"1 para cargar un alumno a la lista"<<endl
            <<"2 para mostrar la lista"<<endl
            <<"3 para salir..."<<endl
            <<"Opcion: ";
            cin>>opcion;

        switch (opcion)
        {
        case '1':
            cargar_arreglo(alumnos, dimensionLogica);
            break;

        case '2':
            mostrar_aptitud(alumnos, dimensionLogica);
            break;

        case '3':
            cout<<"Gracias por usar nuestro sistema.";
            break;
        default:
            cout<<"Ingresar opcion valida: ";
            break;
        }
    } while (opcion != '3');
    

    return 0;
}

//DEFINICIÓN DE FUNCIONES
    //Cargar el arreglo con el nombre y las calificaciones de los estudiantes
    void cargar_arreglo(alumno alumnos[], int &dimensionLogica){
        //Variables
        string nombreCompleto;

        cout<<"Pulse 'Q' para salir...\nApellido y nombre: ";
        getline(cin >> ws, nombreCompleto);

        while (dimensionLogica < DIMENSION_FISICA && nombreCompleto.compare("Q") != 0 && nombreCompleto.compare("q") != 0)
        {
            alumnos[dimensionLogica].nombre = nombreCompleto;

            //Solicita al usuario las 3 calificaciones del alumno ingresado
            cargar_calificaciones(alumnos, dimensionLogica);

            dimensionLogica++;

            cout<<"Pulse 'Q' para salir...\nApellido y nombre: ";
            getline(cin >> ws, nombreCompleto);
        }
        
    }

    void cargar_calificaciones(alumno alumnos[], int dimensionLogica){
        //Variables
        int calificacion;

        for (int i = 0; i < 3; i++)
        {
            cout<<"Calificacion n°"<<i+1<<": ";
            cin>>calificacion;

            alumnos[dimensionLogica].calificaciones[i] = calificacion;
        }
        
    }

    // Muestra en pantalla el nombre de los estudiantes y su estado segun sus notas
    void mostrar_aptitud(alumno alumnos[], int dimensionLogica) {
        cout << "Mostrando lista de alumnos con su respectivo estado...\n" << endl;
        for (int i = 0; i < dimensionLogica; i++) {
            cout << alumnos[i].nombre << ": ";
            if (estado_final(alumnos[i])) {  // Ahora pasamos el alumno actual
                cout << "APTO" << endl;
            } else {
                cout << "NO APTO" << endl;
            }
        }
    }

    // Evalúa si el alumno está "APTO" o "NO APTO"
    bool estado_final(alumno unAlumno) {  // Recibe un solo alumno, no todo el arreglo
        for (int i = 0; i < 3; i++) {
            if (unAlumno.calificaciones[i] < 5) {
                return false;  // NO APTO si alguna calificación es menor a 5
            }
        }
        return true;  // APTO si todas las calificaciones son 5 o más
    }
// Realizar un programa que almacene en un arreglo la lista de invitados a una fiesta. El salon donde se realizara,
// tiene capacidad maxima para 150 personas.
// De cada invitado se conoce su nombre, apellido, sexo y edad. Se ingresaran datos hasta que el nombre sea
// igual a “Q” o hasta que la capacidad del salon este completa.
// Una vez finalizada la carga:
// A. Informar la cantidad de invitados que asistiran a la fiesta.
// B. Realizar una funcion que liste los nombres de las mujeres cuya edad sea <= 20.
// C. Realizar una funcion que, dado un apellido y nombre, permita eliminar un invitado en caso de no poder
// asistir.

//META DATA
// -*- coding: utf-8 -*-
#include <iostream>
#include <limits>       //Para std::numeric_limits
#include <fstream>  // Para manejo de archivos
#include <string>

using namespace std;

//VARIABLES GLOBALES Y CONSTANTES
    //Estructura de lista de invitados
    struct invitado
    {
        string nombre;
        string apellido;
        int edad;
        string sexo;
    };

    const int DF = 150;
    int DL = 0;
    

//DECLARACIoN DE FUNCIONES
    //Guardar la lista de invitados en un documento externo
    void guardar_lista_en_archivo(invitado invitados[], int DL);

    //Leer datos del archivo de invitados
    void cargar_lista_desde_archivo(invitado invitados[], int &DL);

    //1) Cargar lista de invitados
    void cargar_invitados(invitado invitados[], int &DL);

    //2) Elimina invitados de la lista por inasistencia
    void eliminar_invitado(invitado invitados[], int &DL);

    //3) Informar cantidad de asistencias
    void cantidad_asistencias(invitado invitados[], int DL);

    //4) Informa cantidad de mujeres de 20 años o menos
    int mujeres_20_o_menos(invitado invitados[], int DL);

    //Q) Funcion para finalizar la ejecucion del programa
    void finalizar_ejecucion();

    // Funcion para comparar si un invitado ya esta en la lista
    bool verificar_invitado(invitado invitados[], int DL, const invitado& nuevoInvitado);

    //Convierte la primera letra de cada nombre y apellido a mayus y el resto minus
    string capitalizarNombre(const string &nombreCompleto);

    //Verifica que la edad ingresada sea mayor a 0 y menor a 100
    int validar_edad();

    //Verifica que el sexo ingresado sea una opcion valida (M o F)
    string validar_sexo();

    //Ordena los nombres en el arreglo de manera lexicografica
    void insertar_invitado_ordenado(invitado invitados[], int &DL, const invitado& nuevoInvitado);

    // Funcion auxiliar para busqueda binaria
    int buscar_invitado(invitado invitados[], int DL, const string &nombreEliminado, const string &apellidoEliminado);

//FUNCION PRINCIPAL
int main(){
    //Variables
    char opcion;
    invitado invitados[DF];

    // Cargar la lista desde el archivo
    cargar_lista_desde_archivo(invitados, DL);

    cout<<"\n\033[32m| --- Lista de invitados --- |\033[0m"<<endl
        <<"Seleccione opcion que quiere realizar:"<<endl;

    do
    {
        //Menu interactivo con la lista de invitados
        cout<<"\n1) Agregar invitados a la lista."<<endl
            <<"2) Eliminar invitados de la lista."<<endl
            <<"3) Informar cantidad de asistencias."<<endl
            <<"4) Informar cantidad de mujeres de 20 o menos."<<endl
            <<"Pulse 'Q' para salir..."<<endl;

        cin>>opcion;
        opcion = toupper(opcion);

        switch (opcion)
        {
        case '1':
            cout<<"\033[32mAgregar invitados a la lista:\033[0m"<<endl;
            cargar_invitados(invitados, DL);
            break;
        
        case '2':
            cout<<"\033[31mEliminar invitados de la lista...\033[0m"<<endl;
                eliminar_invitado(invitados, DL);
            break;

        case '3':
            cantidad_asistencias(invitados, DL);
            break;

        case '4':
            cout<<"Cant. mujeres de 20 años o menos: "
                <<mujeres_20_o_menos(invitados, DL)<<endl;
            break;

        case 'Q':
            finalizar_ejecucion();
            break;

        default:
            cout<<"\033[31mPor favor, ingrese opcion valida...\033[0m\n";
            break;
        }

    } while (opcion != 'Q');
    

    return 0;
}

//DEFINICIoN DE FUNCIONES
    //1) Funcion para cargar el arreglo con invitados
    void cargar_invitados(invitado invitados[], int &DL) {
        string nombre;
        cout << "Nombre (pulse 'Q' para salir): ";
        getline(cin >> ws, nombre);

        while (DL < DF && nombre.compare("Q") != 0 && nombre.compare("q") != 0) {
            //Capitalizar  nombre
            invitado nuevoInvitado;
            nuevoInvitado.nombre = capitalizarNombre(nombre);

            cout << "Apellido: ";
            getline(cin >> ws, nuevoInvitado.apellido);
            //Capitalizar apellido
            nuevoInvitado.apellido = capitalizarNombre(nuevoInvitado.apellido);

            cout << "Edad: ";
            nuevoInvitado.edad = validar_edad();

            cout << "Ingrese sexo (M/F): ";
            nuevoInvitado.sexo = validar_sexo();

            // Verificar si el invitado ya existe
            if (verificar_invitado(invitados, DL, nuevoInvitado)) {
                cout<<"\033[31mEl invitado ya esta en la lista. No se añadira nuevamente.\033[0m\n";
            } else {
                insertar_invitado_ordenado(invitados, DL, nuevoInvitado);  // Insertar el invitado de manera ordenada
                guardar_lista_en_archivo(invitados, DL);        //Actualizar lista de invitados en documento externo
            }

            cout << endl;
            cout << "Nombre (pulse 'Q' para salir): ";
            getline(cin >> ws, nombre);
        }
    }

    //2) Elimina invitados de la lista por inasistencia
    void eliminar_invitado(invitado invitados[], int &DL) {
        if (DL == 0) {
            cout << "\033[0mNo hay invitados en la lista.\033[0m" << endl;
            return;
        }

        string nombreEliminado;
        string apellidoEliminado;
        char opcion;

        do {
            cout << "Ingrese nombre: ";
            getline(cin >> ws, nombreEliminado);
            nombreEliminado = capitalizarNombre(nombreEliminado);

            cout << "Ingrese apellido: ";
            getline(cin >> ws, apellidoEliminado);
            apellidoEliminado = capitalizarNombre(apellidoEliminado);

            // Usar busqueda binaria para encontrar el invitado
            int posicion = buscar_invitado(invitados, DL, nombreEliminado, apellidoEliminado);

            if (posicion == -1) {
                cout<<"\033[31mInvitado no encontrado.\033[0m" << endl;
                return;
            }

            // Desplazar los elementos hacia la izquierda para eliminar el invitado
            for (int i = posicion; i < DL - 1; i++) {
                invitados[i] = invitados[i + 1];
            }
            DL--;
            guardar_lista_en_archivo(invitados, DL);        //Actualizar lista de invitados en documento externo
            cout<<"\033[32mInvitado eliminado correctamente.\033[0m" << endl;

            if (DL > 0) {
                cout << "Desea eliminar otro invitado? (S/N): ";
                cin >> opcion;
                opcion = toupper(opcion);

                while (opcion != 'N' && opcion != 'S') {
                    cout << "Ingresar opcion valida (S/N): ";
                    cin >> opcion;
                    opcion = toupper(opcion);
                }
            } else {
                cout<<"\033[31mNo hay mas invitados en la lista.\033[0m" << endl;
                opcion = 'N';
            }

        } while (opcion != 'N');
    }

    //3) Informar cantidad de asistencias
    void cantidad_asistencias(invitado invitados[], int DL){
        char opcion;

        cout<<"Cantidad de invitados que asisten: "<<DL<<" de "<<DF<<endl;
        if (DL != 0)
        {
            cout<<"Desea ver la lista? (S/N): ";
            cin>>opcion;
            opcion = toupper(opcion);

            while (opcion != 'N' && opcion != 'S')
            {
                cout<<"\033[31mIngresar opcion valida: \033[0m";
                cin>>opcion;
                opcion = toupper(opcion);
            }

            //SWITCH
            switch (opcion)
            {
                case 'S':
                    cout<<"\n1) Solo nombres."<<endl
                        <<"2) Lista detallada."<<endl;
                    cin>>opcion;

                    while (opcion != '1' && opcion != '2')
                    {
                        cout<<"\033[31mIngresar opcion valida: \033[0m";
                        cin>>opcion;
                    }
                        //Switch anidado
                    switch (opcion)
                    {
                
                        //Lista solo apellido y nombre
                        case '1':
                            for (int i = 0; i < DL; i++)
                            {
                                cout<<"Nro: "<<i+1<<": "
                                <<invitados[i].apellido<<" "<<invitados[i].nombre<<endl;
                            }
                            cout<<endl;
                            break;

                        //Lista detallada
                        case '2':
                            for (int i = 0; i < DL; i++)
                            {
                                cout<<"\nNro: "<<i+1<<":"<<endl
                                <<"Nombre: "<<invitados[i].nombre<<endl
                                <<"Apellido: "<<invitados[i].apellido<<endl
                                <<"Edad: "<<invitados[i].edad<<endl
                                <<"Sexo: "<<invitados[i].sexo<<endl;
                            }
                            cout<<endl;
                            break;
                        
                        default:
                            break;
                        }
                    //Break caso 'S'
                    break;

                case 'N':
                    break;
                    
                default:
                    break;
            }
        }
            
    }

    //4) Informa cantidad de mujeres de 20 años o menos
    int mujeres_20_o_menos(invitado invitados[], int DL){
        int cantidad = 0;
        
        for (int i = 0; i < DL; i++)
        {
            if (invitados[i].sexo == "F" && invitados[i].edad <= 20)
            {
                cantidad++;
            }
            
        }
        return cantidad;
    }

    // Funcion para comparar si un invitado ya esta en la lista
    bool verificar_invitado(invitado invitados[], int DL, const invitado& nuevoInvitado) {
        for (int i = 0; i < DL; i++) {
            if (invitados[i].nombre == nuevoInvitado.nombre &&
                invitados[i].apellido == nuevoInvitado.apellido &&
                invitados[i].edad == nuevoInvitado.edad &&
                invitados[i].sexo == nuevoInvitado.sexo) {
                return true;  // El invitado ya existe
            }
        }
        return false;
    }

    //Q) Funcion para finalizar la ejecucion del programa
    void finalizar_ejecucion(){
        cout<<"Gracias por usar nuestro sistema."<<endl
            << "Pulse Enter para salir...";
            cin.ignore();
            cin.get();  // Espera la pulsacion de Enter.
    }

    //Verifica que el sexo ingresado sea una opcion valida (M o F)
    string validar_sexo(){
		string sexoValidado;
		getline(cin >> ws, sexoValidado);

		// Verificar que la entrada sea de un solo caracter y sea M o F
		while (sexoValidado.length() != 1 || (toupper(sexoValidado[0]) != 'M' && toupper(sexoValidado[0]) != 'F')) {
				cout<<"\033[31mEntrada no valida. Ingresa un genero valido (M/F): \033[0m";
				getline(cin >> ws, sexoValidado);
		}

		// Devolver el valor en mayuscula
		return string(1, toupper(sexoValidado[0]));
	}

    //Verifica que la edad ingresada sea mayor a 0 y menor a 100
    int validar_edad(){
        int edadValidada;

        while(true){
        cin>>edadValidada;
        
        // Verificar si la entrada es valida
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la linea
            cout << "\033[31mEntrada no valida. Ingrese un numero entero positivo: \033[0m";
        } else if (edadValidada >= 0 && edadValidada < 100) {
            break; // Salir del bucle si el numero es positivo
        } else {
            cout << "\033[31mIngrese una edad valida (0 - 100): \033[0m";
        }
    }
        
        return edadValidada;
    }

    //Convierte la primera letra de cada nombre y apellido a mayus y el resto minus
    string capitalizarNombre(const string &nombreCompleto) {
        string resultado = nombreCompleto;
        bool esNuevaPalabra = true;

        for (size_t i = 0; i < resultado.length(); i++) {
            if (esNuevaPalabra && isalpha(resultado[i])) {
                resultado[i] = toupper(resultado[i]);  // Mayuscula al inicio de la palabra
                esNuevaPalabra = false;
            } else {
                resultado[i] = tolower(resultado[i]);  // Minusculas para el resto
            }

            if (resultado[i] == ' ') {
                esNuevaPalabra = true;
            }
        }

        return resultado;
    }

    //Ordena los nombres en el arreglo de manera lexicografica
    void insertar_invitado_ordenado(invitado invitados[], int &DL, const invitado& nuevoInvitado) {
    // Encontrar la posicion correcta para insertar el nuevo invitado
    int pos = DL;
    while (pos > 0 && (invitados[pos - 1].apellido > nuevoInvitado.apellido || 
                      (invitados[pos - 1].apellido == nuevoInvitado.apellido && 
                       invitados[pos - 1].nombre > nuevoInvitado.nombre))) {
        // Desplazar los invitados hacia adelante para hacer espacio
        invitados[pos] = invitados[pos - 1];
        pos--;
    }
    
    // Insertar el nuevo invitado en la posicion encontrada
    invitados[pos] = nuevoInvitado;
    DL++;  // Incrementar el tamaño logico del arreglo
}

    // Funcion auxiliar para busqueda binaria
    int buscar_invitado(invitado invitados[], int DL, const string &nombreEliminado, const string &apellidoEliminado) {
        int izquierda = 0;
        int derecha = DL - 1;

        while (izquierda <= derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;

            // Comparacion lexicografica del nombre y apellido
            if (invitados[medio].apellido == apellidoEliminado && invitados[medio].nombre == nombreEliminado) {
                return medio; // Se encontro el invitado
            } 
            // Si el apellido es menor, buscar en la izquierda
            else if (invitados[medio].apellido < apellidoEliminado || 
                    (invitados[medio].apellido == apellidoEliminado && invitados[medio].nombre < nombreEliminado)) {
                izquierda = medio + 1;
            } 
            // Si es mayor, buscar en la derecha
            else {
                derecha = medio - 1;
            }
        }

        return -1; // No se encontro
    }

    //Leer datos del archivo de invitados
    void cargar_lista_desde_archivo(invitado invitados[], int &DL) {
        ifstream archivo("Lista_de_invitados.txt");  // Abre el archivo en modo lectura
        if (!archivo) {
            cout<<"\033[31mNo se pudo abrir el archivo."<<endl
                <<"\033[32mComenzando con una lista vacia.\033[0m" << endl;
            return;
        }

        DL = 0;  // Reiniciar la cantidad de invitados

        // Leer los datos del archivo y almacenarlos en el arreglo
        while (archivo >> invitados[DL].nombre >> invitados[DL].apellido >> invitados[DL].edad >> invitados[DL].sexo) {
            DL++;
            if (DL >= DF) {
                cout<<"\033[33mSe ha alcanzado la capacidad maxima de la lista de invitados.\033[0m"<<endl;
                break;
            }
        }

        archivo.close();  // Cerrar el archivo despues de la lectura
        cout <<"\033[32mLista de invitados cargada exitosamente desde el archivo.\033[0m" << endl;
    }

    // Guardar la lista de invitados en un documento externo
    void guardar_lista_en_archivo(invitado invitados[], int DL) {
        ofstream archivo("Lista_de_invitados.txt");  // Abre el archivo en modo escritura (sobreescribe)
        if (!archivo) {
            cout<<"\033[31mNo se pudo abrir el archivo para guardar los datos.\033[0m" << endl;
            return;
        }

        // Escribir los datos de los invitados en el archivo
        for (int i = 0; i < DL; i++) {
            archivo << invitados[i].apellido << " "
                    << invitados[i].nombre << " - "
                    << invitados[i].edad << " - "
                    << invitados[i].sexo << endl;
        }

        archivo.close();  // Cerrar el archivo despues de guardar
        cout<<"\033[32mLista de invitados actualizada.\033[0m"<<endl;
    }
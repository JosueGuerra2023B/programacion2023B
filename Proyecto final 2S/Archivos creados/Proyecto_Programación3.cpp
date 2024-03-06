#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream> 
#include <limits>
#include <stdio.h>
#include <wchar.h>

using namespace std;

struct Proforma {
    int id;
    string tipo;
};

vector<Proforma> proformas;

int generarID() {
    return rand() % 9000 + 1000;
}

string intToString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

int stringToInt(const string& str) {
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

struct Cliente {
    string nombre;
    string apellido;
    string direccion;
    int cedula; 
    string correo;
};

vector<Cliente> clientes;

void escribirArchivo(Proforma& proforma) {
    string id_str = intToString(proforma.id);
    ofstream archivo(("proforma_" + id_str + ".txt").c_str());

    if (archivo.is_open()) {
        archivo << "Proforma de " << proforma.tipo << endl;
        archivo.close();
        cout << "Archivo de proforma creado correctamente: proforma_" << id_str << ".txt" << endl;
        cout <<"\n";
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void abrirProforma() {
    int id;
    cout << "Ingrese el ID de la proforma que desea abrir: ";
    cin >> id;

    string id_str = intToString(id);
    string comando = "notepad proforma_" + id_str + ".txt";
    system(comando.c_str());
}

void crearProforma() {
    Proforma nueva_proforma;
    nueva_proforma.id = generarID();

    cout << "�Qu� tipo de proforma desea crear?" << endl;
    cout << "1. Proforma de Viaje" << endl;
    cout << "2. Proforma de Regalo" << endl;

    int opcion;
    cout << "Ingrese su selecci�n: ";
    cin >> opcion;
    string inicio, fin; 

    switch(opcion) {
        case 1:
            nueva_proforma.tipo = "Viaje";
            break;
        case 2:
            nueva_proforma.tipo = "Regalo";
            break;
        default:
            cout << "Opci�n inv�lida" << endl;
            return;
    }

    proformas.push_back(nueva_proforma);
    cout << "\n";
    escribirArchivo(nueva_proforma);
}




void mostrarProformas() {
    if (proformas.empty()) {
        cout << "No hay proformas para mostrar." << endl;
        return;
    }

    for (size_t i = 0; i < proformas.size(); i++) {
        cout << "Proforma: " << proformas[i].id << " - Tipo: " << proformas[i].tipo << endl;
    }
    cout << "\n";
}

void eliminarProforma() {
    if (proformas.empty()) {
        cout << "No hay proformas para eliminar." << endl;
        cout << "\n";
        return;
    }

    int id;
    cout << "Ingrese el ID de la proforma que desea eliminar: ";
    cin >> id;

    string id_str = intToString(id);
    string comando = "notepad proforma_" + id_str + ".txt";
    system(comando.c_str());

    for (size_t i = 0; i < proformas.size(); ++i) {
        if (proformas[i].id == id) {
            proformas.erase(proformas.begin() + i);
            if (remove(("proforma_" + id_str + ".txt").c_str()) != 0) {
                cout << "Error al eliminar el archivo de la proforma." << endl;
            } else {
                cout << "Proforma con ID " << id << " eliminada correctamente." << endl;
                cout << "\n";
            }
            return;
        }
    }

    cout << "No se encontr� ninguna proforma con el ID proporcionado." << endl;
}

void menuOpciones(){
	int seleccion;
    do {
        cout << "--- Viajes BOROJO ---" << endl;
        cout << " Le da la bienvenida";
        cout << "\n";
        cout << "1. Crear una nueva proforma" << endl << "2. Mostrar proformas creadas (solo ID)" << endl << "3. Abrir una proforma por ID" << endl << "4. Eliminar una proforma por ID" << endl  << "5. Finalizar Programa" << endl;
        cout << "Ingresa tu seleccion: ";
        cin >> seleccion;
        cout <<"\n";

        switch (seleccion) {
            case 1:
                crearProforma();
                break;
            case 2:
                mostrarProformas();
                break;
            case 3:
                abrirProforma();
                break;
            case 4:
                eliminarProforma();
                break;
            case 5:
                cout << "Gracias por tu visita :D";
                exit(0);
                break;
            default:
                cout << "Selecci�n no v�lida." << endl;
                break;
        }

    } while (seleccion != 6);
}

void cargarClientes() {
    ifstream archivo("CLIENTES.txt");
    if (archivo.is_open()) {
        string linea;
        Cliente cliente;
        while (getline(archivo, linea)) {
            if (linea.find("Nombre: ") != string::npos) {
                cliente.nombre = linea.substr(8);
            } else if (linea.find("Apellido: ") != string::npos) {
                cliente.apellido = linea.substr(10);
            } else if (linea.find("Direcci�n: ") != string::npos) {
                cliente.direccion = linea.substr(11);
            } else if (linea.find("C�dula: ") != string::npos) {
                cliente.cedula = stringToInt(linea.substr(8));
            } else if (linea.find("Correo electr�nico: ") != string::npos) {
                cliente.correo = linea.substr(21);
                clientes.push_back(cliente);
            }
        }
        archivo.close();
    }
}
void registrarCliente() {
    cargarClientes(); 

    Cliente nuevoCliente;
    cout << "=== Registro de Cliente ===" << endl;
    cout << "Ingrese su nombre: ";
    getline(cin >> ws, nuevoCliente.nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, nuevoCliente.apellido);
    cout << "Ingrese su direcci�n: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese su correo electr�nico: ";
    getline(cin, nuevoCliente.correo);
    cout << "Ingrese su cedula: ";
    cin >> nuevoCliente.cedula;

    bool cedulaExiste = false;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].cedula == nuevoCliente.cedula) {
            cedulaExiste = true;
            break;
        }
    }

    if (cedulaExiste) {
        cout << "La c�dula ya est� registrada." << endl;
        return;
    }

    ofstream archivo("CLIENTES.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nuevoCliente.nombre << endl;
        archivo << "Apellido: " << nuevoCliente.apellido << endl;
        archivo << "Direcci�n: " << nuevoCliente.direccion << endl;
        archivo << "C�dula: " << nuevoCliente.cedula << endl;
        archivo << "Correo electr�nico: " << nuevoCliente.correo << endl;
        archivo << "---------------------------------------" << endl;
        archivo.close();
        cout << "Usuario creado. Sus datos han sido almacenados." << endl;
        cout <<"\n";
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
    menuOpciones();
}

void guardarClientes() {
    ofstream archivo("CLIENTES.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < clientes.size(); ++i) {
            archivo << "Nombre: " << clientes[i].nombre << endl;
            archivo << "Apellido: " << clientes[i].apellido << endl;
            archivo << "Direcci�n: " << clientes[i].direccion << endl;
            archivo << "C�dula: " << clientes[i].cedula << endl;
            archivo << "Correo electr�nico: " << clientes[i].correo << endl;
            archivo << "---------------------------------------" << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void actualizarInformacionUsuario() {
    cargarClientes();

    int cedula;
    cout << "Ingrese la c�dula del usuario que desea actualizar: ";
    cin >> cedula;

    bool encontrado = false;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].cedula == cedula) {
            Cliente& cliente = clientes[i];
            int opcion;
            do {
                cout << "=== Actualizar Informaci�n del Cliente ===" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Apellido" << endl;
                cout << "3. Direcci�n" << endl;
                cout << "4. Correo electr�nico" << endl;
                cout << "5. Volver al men� anterior" << endl;
                cout << "Ingrese su seleccion: ";
                cin >> opcion;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (opcion) {
                    case 1:
                        cout << "Ingrese el nuevo nombre: ";
                        getline(cin >> ws, cliente.nombre);
                        break;
                    case 2:
                        cout << "Ingrese el nuevo apellido: ";
                        getline(cin, cliente.apellido);
                        break;
                    case 3:
                        cout << "Ingrese la nueva direcci�n: ";
                        getline(cin, cliente.direccion);
                        break;
                    case 4:
                        cout << "Ingrese el nuevo correo electr�nico: ";
                        getline(cin, cliente.correo);
                        break;
                    case 5:
                        cout << "Ingresar al menu de opciones." << endl;
                        break;
                    default:
                        cout << "Selecci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
                        break;
                }
            } while (opcion != 5);
            guardarClientes();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado." << endl;
    } else {
        guardarClientes();
        cout << "Informaci�n del cliente actualizada correctamente." << endl;
    }
}

void accederUsuario() {
    int intentos = 2;
    int cedula;
    bool acceso = false;

    while (intentos > 0) {
        cout << "Ingrese su n�mero de c�dula: ";
        cin >> cedula;

        cargarClientes();

        for (size_t i = 0; i < clientes.size(); ++i) {
            if (clientes[i].cedula == cedula) {
                cout << "Acceso como usuario frecuente exitoso.\n" << endl;
                acceso = true;
                menuOpciones();
                break;
            }
        }

        if (acceso) {
            break;
        } else {
            cout << "N�mero de c�dula incorrecto. Intentos restantes: " << intentos << endl;
            intentos--;
        }
    }

    if (!acceso) {
        cout << "No se pudo acceder como usuario frecuente. Ingrese como un nuevo usuario." << endl;
        registrarCliente();
    }
    menuOpciones();
}


void menuInicial() {
    int opcion;
    do {
    	cout << "=== Viajes Borojo ===\n" << endl;
        cout << "=== Men� Inicial ===" << endl;
        cout << "1. Crear un nuevo usuario\n2. Usuario Frecuente\n3. Actualizar informaci�n de usuario\n4. Finalizar programa" << endl;
        cout << "Ingrese su seleccion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                registrarCliente();
                break;
            case 2:
                accederUsuario();
                break;
            case 3:
                actualizarInformacionUsuario();
                break;
            case 4:
                cout << "Saliendo del programa. �Hasta luego!" << endl;
                exit(0);
                break;
            default:
                cout << "Selecci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
                break;
        }
    } while (opcion != 4);
}

int main() {
    srand(time(NULL));
    menuInicial(); 
    
    return 0;
}




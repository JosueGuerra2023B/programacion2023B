#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <limits>

using namespace std;

struct Cliente {
    string nombre;
    string apellido;
    string direccion;
    int cedula;
    string correo;
};

string intToString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

void registrarCliente() {
    Cliente nuevoCliente;
    cout << "Ingrese su nombre: ";
    getline(cin >> ws, nuevoCliente.nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, nuevoCliente.apellido);
    cout << "Ingrese su dirección: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese su correo electrónico: ";
    getline(cin, nuevoCliente.correo);

    bool cedulaValida = false;
    while (!cedulaValida) {
        cout << "Ingrese su número de cédula: ";
        cin >> nuevoCliente.cedula;

        // Verificación de que la cédula tenga exactamente 10 dígitos
        if (cin.fail() || nuevoCliente.cedula < 0 || nuevoCliente.cedula > 9999999999) {
            cout << "Cédula no válida. Debe contener exactamente 10 dígitos. Inserte nuevamente." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cedulaValida = true;
        }
    }

    ofstream archivo("CLIENTES.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nuevoCliente.nombre << endl;
        archivo << "Apellido: " << nuevoCliente.apellido << endl;
        archivo << "Dirección: " << nuevoCliente.direccion << endl;
        archivo << "Cédula: " << nuevoCliente.cedula << endl;
        archivo << "Correo electrónico: " << nuevoCliente.correo << endl;
        archivo << "---------------------------------------" << endl;
        archivo.close();
        cout << "Usuario creado. Sus datos han sido almacenados." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void clienteFrecuente() {
    int intentos = 2;
    int cedula;
    bool encontrado = false;

    while (intentos > 0 && !encontrado) {
        cout << "Ingrese su número de cédula: ";
        cin >> cedula;

        ifstream archivo("CLIENTES.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                if (linea.find("Cédula: " + intToString(cedula)) != string::npos) {
                    encontrado = true;
                    break;
                }
            }
            archivo.close();
        } else {
            cout << "Error al abrir el archivo." << endl;
            return;
        }

        if (!encontrado) {
            cout << "Cédula no encontrada. Le quedan " << intentos - 1 << " intentos." << endl;
            intentos--;
        }
    }

    if (encontrado) {
        cout << "Bienvenido/a a Viajes Borojo." << endl;
    } else {
        cout << "No se ha encontrado la cédula. Por favor, registre un nuevo usuario." << endl;
    }
}

struct Proforma {
    int id;
    string tipo;
};

vector<Proforma> proformas;

int generarID() {
    return rand() % 9000 + 1000; 
}

void escribirArchivo(Proforma& proforma) {
    ofstream archivo(("proforma_" + intToString(proforma.id) + ".txt").c_str());

    if (archivo.is_open()) {
        archivo << "Proforma de " << proforma.tipo << endl;
        archivo.close();
        cout << "Archivo de proforma creado correctamente: proforma_" << proforma.id << ".txt" << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void crearProforma() {
    Proforma nueva_proforma;
    nueva_proforma.id = generarID();
    
    cout << "¿Qué tipo de proforma desea crear?" << endl;
    cout << "1. Proforma de Viaje" << endl;
    cout << "2. Proforma de Regalo" << endl;

    int opcion;
    cout << "Ingrese su selección: "; 
    cin >> opcion;

    switch(opcion) {
        case 1:
            nueva_proforma.tipo = "Viaje";
            break;
        case 2:
            nueva_proforma.tipo = "Regalo";
            break;
        default:
            cout << "Opción inválida" << endl;
            return;
    }

    proformas.push_back(nueva_proforma);
    cout<<"\n";
    escribirArchivo(nueva_proforma);
}

void mostrarProformas() {
    if (proformas.empty()) {
        cout << "No hay proformas para mostrar." << endl;
        return;
    }

    for (int i = 0; i < proformas.size(); i++) {
        cout << "Proforma: " << proformas[i].id << " - Tipo: " << proformas[i].tipo << endl;
    }
    cout <<"\n";
}

void eliminarProforma() {
    if (proformas.empty()) {
        cout << "No hay proformas para eliminar." << endl;
        cout <<"\n";
        return;
    }

    int id;
    cout << "Ingrese el ID de la proforma que desea eliminar: ";
    cin >> id;

    for (int i = 0; i < proformas.size(); ++i) {
        if (proformas[i].id == id) {
            proformas.erase(proformas.begin() + i);
            if (remove(("proforma_" + intToString(id) + ".txt").c_str()) != 0) {
                cout << "Error al eliminar el archivo de la proforma." << endl;
            } else {
                cout << "Proforma con ID " << id << " eliminada correctamente." << endl;
                cout <<"\n";
            }
            return;
        }
    }

    cout << "No se encontró ninguna proforma con el ID proporcionado." << endl;
}

void abrirProforma() {
    int id;
    cout << "Ingrese el ID de la proforma que desea abrir: ";
    cin >> id;

    string comando = "notepad proforma_" + intToString(id) + ".txt";
    system(comando.c_str());
}

int main() {
    srand(time(NULL));
    int seleccion;
    do {
        cout << "=== Menú de Cliente ===" << endl;
        cout << "1. Cliente Nuevo" << endl;
        cout << "2. Cliente Frecuente" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> seleccion;

        switch (seleccion) {
            case 1:
                registrarCliente();
                break;
            case 2:
                clienteFrecuente();
                break;
            case 3:
                cout << "Saliendo del sistema." << endl;
                return 0;
            default:
                cout << "Opción no válida. Inténtelo nuevamente." << endl;
                break;
        }
    } while (seleccion != 3);

    do {
        cout << "=== Menú de Proformas ===" << endl;
        cout << "1. Crear una nueva proforma" << endl;
        cout << "2. Mostrar proformas creadas (solo ID)" << endl;
        cout << "3. Abrir una proforma por ID" << endl;
        cout << "4. Eliminar una proforma por ID" << endl;
        cout << "5. Volver al Menú de Cliente" << endl;
        cout << "Ingrese su opción: ";
        cin >> seleccion;

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
                cout << "Volviendo al Menú de Cliente." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo nuevamente." << endl;
                break;
        }
    } while (seleccion != 5);

    return 0;
}


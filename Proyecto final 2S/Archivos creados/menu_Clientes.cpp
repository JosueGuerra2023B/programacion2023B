#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // Incluimos esta cabecera para utilizar stringstream
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

int main() {
    int opcion;
    do {
        cout << "=== Menú de Clientes ===" << endl;
        cout << "1. Cliente Nuevo" << endl;
        cout << "2. Cliente Frecuente" << endl;
        cout << "3. Salir del Sistema" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarCliente();
                break;
            case 2:
                clienteFrecuente();
                break;
            case 3:
                cout << "Saliendo del sistema." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo nuevamente." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}


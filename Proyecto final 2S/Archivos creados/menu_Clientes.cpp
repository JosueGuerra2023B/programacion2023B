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
    cout << "Ingrese su direcci�n: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese su correo electr�nico: ";
    getline(cin, nuevoCliente.correo);

    bool cedulaValida = false;
    while (!cedulaValida) {
        cout << "Ingrese su n�mero de c�dula: ";
        cin >> nuevoCliente.cedula;

        // Verificaci�n de que la c�dula tenga exactamente 10 d�gitos
        if (cin.fail() || nuevoCliente.cedula < 0 || nuevoCliente.cedula > 9999999999) {
            cout << "C�dula no v�lida. Debe contener exactamente 10 d�gitos. Inserte nuevamente." << endl;
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
        archivo << "Direcci�n: " << nuevoCliente.direccion << endl;
        archivo << "C�dula: " << nuevoCliente.cedula << endl;
        archivo << "Correo electr�nico: " << nuevoCliente.correo << endl;
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
        cout << "Ingrese su n�mero de c�dula: ";
        cin >> cedula;

        ifstream archivo("CLIENTES.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                if (linea.find("C�dula: " + intToString(cedula)) != string::npos) {
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
            cout << "C�dula no encontrada. Le quedan " << intentos - 1 << " intentos." << endl;
            intentos--;
        }
    }

    if (encontrado) {
        cout << "Bienvenido/a a Viajes Borojo." << endl;
    } else {
        cout << "No se ha encontrado la c�dula. Por favor, registre un nuevo usuario." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "=== Men� de Clientes ===" << endl;
        cout << "1. Cliente Nuevo" << endl;
        cout << "2. Cliente Frecuente" << endl;
        cout << "3. Salir del Sistema" << endl;
        cout << "Ingrese su opci�n: ";
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
                cout << "Opci�n no v�lida. Int�ntelo nuevamente." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}


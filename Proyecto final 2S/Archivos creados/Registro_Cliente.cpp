#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Cliente {
    string nombre;
    string apellido;
    string direccion;
    int cedula; // Cambiado a tipo entero para almacenar la cédula como número
    string correo;
};

void registrarCliente() {
    Cliente nuevoCliente;
    cout << "Ingrese su nombre: ";
    getline(cin >> ws, nuevoCliente.nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, nuevoCliente.apellido);
    cout << "Ingrese su direccion: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese su correo electronico: ";
    getline(cin, nuevoCliente.correo);

    bool cedulaValida = false;
    while (!cedulaValida) {
        cout << "Ingrese su número de cédula : ";
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

int main() {
    cout << "=== Registro de Cliente ===" << endl;
    registrarCliente();
    return 0;
}


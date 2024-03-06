#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Cliente {
    string nombre;
    string apellido;
    string direccion;
    int cedula; // Cambiado a tipo entero para almacenar la c�dula como n�mero
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
        cout << "Ingrese su n�mero de c�dula : ";
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

int main() {
    cout << "=== Registro de Cliente ===" << endl;
    registrarCliente();
    return 0;
}


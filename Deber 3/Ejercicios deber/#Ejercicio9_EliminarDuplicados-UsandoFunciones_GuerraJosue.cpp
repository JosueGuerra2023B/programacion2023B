#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cout << "    ---// Bienvenido //---    " << endl;
    cout << "      Eliminación de duplicados " << endl;
    cout << " Inserte su nombre para comenzar: " << endl;
    string nombre;
    cin >> nombre;
    cout << "Ingrese la longitud del vector: ";
    cin >> n;

    int vector[n];
    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector[i];
    }

    cout << "\nVector ingresado inicialmente:" << endl;
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        cout << vector[i];
        if (i < n - 1) {
            cout << " , ";
        }
    }
    cout << " ]" << endl;

    sort(vector, vector + n);

    int nuevoTamano = 1;
    for (int i = 1; i < n; ++i) {
        if (vector[i] != vector[i - 1]) {
            vector[nuevoTamano++] = vector[i];
        }
    }

    cout << "\nVector sin elementos duplicados:" << endl;
    cout << "[ ";
    for (int i = 0; i < nuevoTamano; ++i) {
        cout << vector[i];
        if (i < nuevoTamano - 1) {
            cout << " , ";
        }
    }
    cout << " ]" << endl;

    return 0;
}



#include <iostream>
using namespace std;
int main() {
    int n;

    cout << "    ---// Bienvenido //---    " << endl;
    cout << "      Orden de vectores " << endl;
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
            cout << " - ";
        }
    }
    cout << " ]" << endl;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    cout << "\nVector ordenado en orden ascendente:" << endl;
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        cout << vector[i];
        if (i < n - 1) {
            cout << " - ";
        }
    }
    cout << " ]" << endl;

    return 0;
}

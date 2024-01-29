#include <iostream>

using namespace std;

int main() {
    cout << "     ---// Bienvenido //---    " << endl;
    cout << "   Verificar simetria de una matriz " << endl;
    cout << " Inserte su nombre para comenzar: " << endl;
    string nombre;
    cin >> nombre;
    int filas, columnas;
    do {
        cout << "Ingrese el numero de filas: ";
        cin >> filas;
        cout << "Ingrese el numero de columnas: ";
        cin >> columnas;

        if (filas == columnas) {
            int matriz[filas][columnas];
            cout << "\nLa matriz ingresada por " << nombre << " es simetrica." << endl;
            cout << "Ingrese los elementos de la matriz:" << endl;

            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    cout << "Matriz[" << i << "][" << j << "]: ";
                    cin >> matriz[i][j];
                }
            }
            cout << "\nLa matriz es:" << endl;
            for (int i = 0; i < filas; ++i) {
                cout << "[";
                for (int j = 0; j < columnas; ++j) {
                    cout << "  " << matriz[i][j] << " ";
                    if (j < columnas - 1) {
                        cout << " ";
                    }
                }
                cout << "]" << endl;
            }
        } else {
            cout << "\nLa matriz ingresada por " << nombre << " no es simetrica." << endl;
        }
    } while (filas != columnas);
    return 0;
}





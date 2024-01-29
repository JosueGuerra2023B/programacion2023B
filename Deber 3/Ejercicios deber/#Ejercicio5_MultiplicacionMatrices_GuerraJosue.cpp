#include <iostream>

using namespace std;

int main() {
    int filas, columnas;
    cout << "     ---// Bienvenido //---    " << endl;
    cout << "      Suma de dos matrices " << endl;
    cout << " Inserte su nombre para comenzar: " << endl;
    string nombre;
    cin >> nombre;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    int matriz1[filas][columnas];
    int matriz2[filas][columnas];

    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Matriz1[" << i << "][" << j << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Matriz2[" << i << "][" << j << "]: ";
            cin >> matriz2[i][j];
        }
    }

    cout << "\nLa Matriz 1  es:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n LaMatriz 2 es:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz2[i][j] << "\t";
        }
        cout << endl;
    }

    int resultado[filas][columnas];
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matriz1[i][j] * matriz2[i][j];
        }
    }

    cout << "\nLa matriz resultado es:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << resultado[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}


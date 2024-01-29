#include <iostream>
using namespace std;

void mostrarMatriz(int** matriz, int filas, int columnas) {
    cout << "Matriz ingresada:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}
void mostrarSumaFilaColumna(int** matriz, int filas, int columnas) {
    cout << "Suma de elementos por fila:" << endl;
    for (int i = 0; i < filas; ++i) {
        int sumaFila = 0;
        for (int j = 0; j < columnas; ++j) {
            sumaFila += matriz[i][j];
        }
        cout << "Fila " << i + 1 << ": " << sumaFila << endl;
    }
    cout << "Suma de elementos por columna:" << endl;
    for (int j = 0; j < columnas; ++j) {
        int sumaColumna = 0;
        for (int i = 0; i < filas; ++i) {
            sumaColumna += matriz[i][j];
        }
        cout << "Columna " << j + 1 << ": " << sumaColumna << endl;
    }
    int sumaTotal = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            sumaTotal += matriz[i][j];
        }
    }
    cout << "Suma total de todos los elementos: " << sumaTotal << endl;
}

int main() {
    int filas, columnas;

    cout << "Ingrese el número de filas: ";
    cin >> filas; 
	cout << "Ingrese el número de columnas: ";
	cin>> columnas;

    int** matriz = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }

    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    mostrarMatriz(matriz, filas, columnas);
    mostrarSumaFilaColumna(matriz, filas, columnas);
    return 0;
}




//Ejercicio de ejemplo 
//retorno de arreglos
#include <iostream>
using namespace std;

// Función que retorna un puntero a un arreglo
int* crearArreglo(int tamano) {
    // Se crea un arreglo estático en la función
    static int arreglo[100];  // Se elige un tamaño máximo arbitrario

    for (int i = 0; i < tamano; ++i) {
        arreglo[i] = i * 3;  
    }
    // Se retorna un puntero al primer elemento del arreglo
    return arreglo;
}

int main() {
    cout << "Ejemplo de retorno de arreglo con funciones en C++" << endl;

    int tamano;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamano;

    // Llama a la función y obtén el puntero al arreglo resultante
    int* punteroArreglo = crearArreglo(tamano);

    cout << "El arreglo retornado es: ";
    for (int i = 0; i < tamano; ++i) {
        cout << punteroArreglo[i] << " ";
    }

    return 0;
}




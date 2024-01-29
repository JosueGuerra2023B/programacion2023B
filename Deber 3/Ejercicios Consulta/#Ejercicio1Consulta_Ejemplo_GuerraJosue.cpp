//Ejercicio de ejemplo 
//retorno de arreglos
#include <iostream>
using namespace std;

// Funci�n que retorna un puntero a un arreglo
int* crearArreglo(int tamano) {
    // Se crea un arreglo est�tico en la funci�n
    static int arreglo[100];  // Se elige un tama�o m�ximo arbitrario

    for (int i = 0; i < tamano; ++i) {
        arreglo[i] = i * 3;  
    }
    // Se retorna un puntero al primer elemento del arreglo
    return arreglo;
}

int main() {
    cout << "Ejemplo de retorno de arreglo con funciones en C++" << endl;

    int tamano;
    cout << "Ingrese el tama�o del arreglo: ";
    cin >> tamano;

    // Llama a la funci�n y obt�n el puntero al arreglo resultante
    int* punteroArreglo = crearArreglo(tamano);

    cout << "El arreglo retornado es: ";
    for (int i = 0; i < tamano; ++i) {
        cout << punteroArreglo[i] << " ";
    }

    return 0;
}




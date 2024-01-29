//Ejercicio de ejemplo 
//retorno de arreglos usando vectores
#include <iostream>
#include <vector>

using namespace std;

// Funci�n que devuelve un vector (array din�mico)
vector<int> crearVector(int tamano) {
    vector<int> nuevoVector;

    for (int i = 0; i < tamano; ++i) {
        nuevoVector.push_back(i * 2);  
		// Agrega elementos al final del vector
    }

    return nuevoVector;
}

int main() {
    cout << "Ejemplo de retorno de array usando vector en C++" << endl;

    int tamano;
    cout << "Ingrese el tama�o del array: ";
    cin >> tamano;

    // Llama a la funci�n y obt�n el vector resultante
    vector<int> vectorResultado = crearVector(tamano);

    cout << "El array retornado es: ";
    for (size_t i = 0; i < vectorResultado.size(); ++i) {
        cout << vectorResultado[i] << " ";
    }

    return 0;
}




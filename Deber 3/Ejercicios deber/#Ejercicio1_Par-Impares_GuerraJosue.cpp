#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    cout << "    ---// Bienvenido //---    " << endl;
    cout << " Pares e impares en arreglos " << endl;
    cout << " Inserte su nombre para comenzar: " << endl;
    string nombre;
    cin >> nombre;
	const int MAX_NUMEROS = 100; 
    int pares[MAX_NUMEROS];
    int impares[MAX_NUMEROS];

    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    int indicePares = 0;
    int indiceImpares = 0;

    for (int i = 0; i < n; ++i) {
        int numero;
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero;

        if (numero % 2 == 0) {
            pares[indicePares] = numero;
            indicePares++;
        } else {
            impares[indiceImpares] = numero;
            indiceImpares++;
        }
    }    
    
	cout << "Numeros pares: ";
	cout << "[ ";
    for (int i = 0; i < indicePares; ++i) {
        cout << pares[i] << " - ";
    }
    cout << " ]" << endl;
    cout << endl;

    cout << "Numeros impares: ";
    cout << "[ ";
    for (int i = 0; i < indiceImpares; ++i) {
        cout << impares[i] << " ";
    }
    cout << " ]" << endl;
    cout << endl;
    return 0;
}


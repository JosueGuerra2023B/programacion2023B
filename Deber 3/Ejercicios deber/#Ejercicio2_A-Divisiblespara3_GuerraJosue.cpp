#include <iostream>
#include <vector>

using namespace std;

int main() {
	
    cout << "     ---// Bienvenido //---    " << endl;
    cout << "Arreglo son con divisibles para 3 " << endl;
    cout << " Inserte su nombre para comenzar: " << endl;
    string nombre;
    cin >> nombre;
    
	const int numero = 100; 
    int divisiblesPor3[numero];

    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    int divisibles = 0;

    for (int i = 0; i < n; ++i) {
        int numero;
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero;

        if (numero % 3 == 0) {

            divisiblesPor3[divisibles] = numero;
            divisibles++;
        }
    }

    cout << "Numeros divisibles por 3: ";
    for (int i = 0; i < divisibles; ++i) {
        cout << divisiblesPor3[i] << " ";
    }
    cout << endl;

    return 0;
}


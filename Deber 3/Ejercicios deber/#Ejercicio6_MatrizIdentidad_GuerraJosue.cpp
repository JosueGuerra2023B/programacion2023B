#include <iostream>

using namespace std;

int main() {
    cout << "     ---// Bienvenido //---    " << endl;
    cout << "        Matriz Identidad        " << endl;
    cout << " Inserte su nombre para comenzar: " << endl;
    string nombre;
    cin >> nombre;
    
	int dimension;
    cout << "Ingrese la dimension de la matriz : ";
    cin >> dimension;

    if (dimension <= 0) {
        cout << "La dimensión debe ser un número entero mayor que 0." << endl;
        return 1;  
    }

    cout << "La matriz identidad de dimension " << dimension << " es:" << endl;

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if (i == j) {
                cout << " 1 ";
            } else {
                cout << " 0 ";
            }

            if (j < dimension - 1) {
                cout << " "; 
            }
        }
        cout << endl;  
    }

    return 0;
}


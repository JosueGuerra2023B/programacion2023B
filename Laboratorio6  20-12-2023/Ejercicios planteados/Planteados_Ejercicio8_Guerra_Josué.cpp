#include <iostream>

using namespace std;

int main() {
    int numero, numero2, suma;
    cout << "Ingrese su nombre: " << endl;
    string nombre;
    cin >> nombre;

        for (int j = 1; ; j++) {
            suma = 0;
            cout << "Ingrese el número " << j << ": "<<endl;
            cout << "Al ingresar 0 el programa terminara" << endl;
            cin >> numero2;

            if (numero2 == 0) {
                cout <<nombre<<endl;
                cout << "         Vuelva Pronto" << endl;
				cout << " ________________________________ " << endl;
				cout << "|       |    Gracias     |       |" << endl;
				cout << "|   _   |    por usar    |   _   |" << endl;
				cout << "|  | |  |                |  | |  |" << endl;
				cout << "|  |_|  |                |  |_|  |" << endl;
				cout << "|       |    nuestro     |       |" << endl;
				cout << "|       |    Sistema     |       |" << endl;
				cout << "|_______|________________|_______|" << endl;
				cout << "Creado Por Josue Guerra";
                break;
            }

            for (int i = 1; i < numero2; i++) {
                if (numero2  %i == 0) {
                    suma += i;
                    cout << i << " + ";
        
                }
            }
            cout << "\b\b = " << numero2 << endl;

            if (suma == numero2) {
                cout << "El numero " << numero2 << " es un numero perfecto" << endl;
            } else {
                cout << "El numero " << numero2 << " no es un numero perfecto" << endl;
            }
        }
    return 0;
}



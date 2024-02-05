#include <iostream>

using namespace std;

// Función recursiva para mostrar el rango interno entre dos números
void mostrarRango(int menor, int mayor, bool ascendente) {
    if (ascendente) {
        if (menor <= mayor) {
            cout << menor << " ";
            mostrarRango(menor + 1, mayor, true);
        }
    } else {
        if (mayor >= menor) {
            cout << mayor << " ";
            mostrarRango(menor, mayor - 1, false);
        }
    }
}

char mostrarMenu() {
    cout << "\nSeleccione el orden del rango:" << endl;
    cout << "A: Ascendente" << endl;
    cout << "D: Descendente" << endl;
    cout << "S: Salir" << endl;

    char opcion;
    cout << "Ingrese la opción: ";
    cin >> opcion;

    return opcion;
}

int main() {
    int num1, num2;
    cout << "        -*-Bienvenido usuario-*-               " << endl;
    cout << "Programa que presenta el rango de dos números" << endl;
    do {
        cout << "Ingrese el primer número: ";
        cin >> num1;
        cout << "Ingrese el segundo número: ";
        cin >> num2;

        if (num1 < num2) {
            char opcion;
            do {
                opcion = mostrarMenu();
                switch (opcion) {
                    case 'A':
                        mostrarRango(num1, num2, true);
                        break;
                    case 'D':
                        mostrarRango(num1, num2, false);
                        break;
                    case 'S':
                    	cout<<" Gracias por usar nuestro sistema";
                        break;
                    default:
                        cout << "Opción no válida." << endl;
                        break;
                }
            } while (opcion != 'S');
        } else {
            cout << "Valores Incorrectos" << endl << "\n";
        }
    } while (num1 >= num2);

    return 0;
}


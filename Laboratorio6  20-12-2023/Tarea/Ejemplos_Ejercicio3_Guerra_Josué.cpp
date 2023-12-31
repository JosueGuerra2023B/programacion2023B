#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int num1, num2;
    
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;

    int resultado = num1 + num2;
    cout << "La suma de " << num1 << " y " << num2 << " es: " << resultado << endl;

    return 0;
}


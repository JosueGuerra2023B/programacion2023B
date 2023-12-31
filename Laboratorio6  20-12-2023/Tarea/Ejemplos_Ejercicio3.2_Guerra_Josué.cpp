#include <iostream>
#include <cstdlib>
#include <ctime>   
#include <cstdlib> 
#include <cstring> 

using namespace std;

int main() {
    // Genera números aleatorios 
    int num1 = rand();
    int num2 = rand();

    cout << "Número aleatorio 1: " << num1 << endl;
    cout << "Número aleatorio 2: " << num2 << endl;
    
    // Calculo de la suma
    int suma = num1 + num2;
    cout << "La suma de los números generados es: " << suma << endl;

    cout << "Ingrese un número como cadena: ";
    float val;
    cin >> val;
    double __cdecl atof (const char *_String);
    cout<<val<<endl;
    

    return 0;
}


#include <iostream>
#include <cstdlib>
#include <ctime>   
#include <cstdlib> 
#include <cstring> 

using namespace std;

int main() {
    // Genera n�meros aleatorios 
    int num1 = rand();
    int num2 = rand();

    cout << "N�mero aleatorio 1: " << num1 << endl;
    cout << "N�mero aleatorio 2: " << num2 << endl;
    
    // Calculo de la suma
    int suma = num1 + num2;
    cout << "La suma de los n�meros generados es: " << suma << endl;

    cout << "Ingrese un n�mero como cadena: ";
    float val;
    cin >> val;
    double __cdecl atof (const char *_String);
    cout<<val<<endl;
    

    return 0;
}


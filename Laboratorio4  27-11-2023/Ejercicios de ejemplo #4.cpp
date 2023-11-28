#include <iostream>
#include <cmath>  // Necesario para la función sqrt
using namespace std;

int main()
{
    // Ejercicio de CONVERSIÓN EXPLICITA
    // Ejercicios de ejemplo 
    // Ejemplo 1
    
    float resultado_sqrt;
    char caracter;
    int cateto1 = 15;
    int cateto2 = 16;
    double hipotenusa;

    hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
    hipotenusa = double(sqrt(pow(cateto1, 2) + pow(cateto2, 2)));
    hipotenusa = static_cast<double>(sqrt(pow(cateto1, 2) + pow(cateto2, 2)));

    int resultado_cast = static_cast<int>(caracter);

    cout << "La hipotenusa es: " << hipotenusa << endl;
    cout << resultado_cast;

    return 0;
}


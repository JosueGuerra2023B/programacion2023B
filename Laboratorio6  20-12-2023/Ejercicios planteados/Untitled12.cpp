#include <iostream>

using namespace std;

int main()
{
    cout << "Ingrese un número: ";
    int numero;
    cin >> numero;

    if (numero <= 0)
    {
        cout << "El número debe ser un entero positivo. Programa terminado." << endl;
    }

    int sumaFactores = 0;

    // Calcular la suma de los factores del número
    for (int i = 1; i <= numero; ++i)
    {
        if (numero == 0)
        {
            sumaFactores += i;
        }
    }

    // Verificar si el número es perfecto
    if (sumaFactores == numero)
    {
        cout << numero << " es un número perfecto." << endl;
    }
    else
    {
        cout << numero << " no es un número perfecto." << endl;
    }

    return 0;
}



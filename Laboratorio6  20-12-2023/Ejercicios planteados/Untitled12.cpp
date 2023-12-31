#include <iostream>

using namespace std;

int main()
{
    cout << "Ingrese un n�mero: ";
    int numero;
    cin >> numero;

    if (numero <= 0)
    {
        cout << "El n�mero debe ser un entero positivo. Programa terminado." << endl;
    }

    int sumaFactores = 0;

    // Calcular la suma de los factores del n�mero
    for (int i = 1; i <= numero; ++i)
    {
        if (numero == 0)
        {
            sumaFactores += i;
        }
    }

    // Verificar si el n�mero es perfecto
    if (sumaFactores == numero)
    {
        cout << numero << " es un n�mero perfecto." << endl;
    }
    else
    {
        cout << numero << " no es un n�mero perfecto." << endl;
    }

    return 0;
}



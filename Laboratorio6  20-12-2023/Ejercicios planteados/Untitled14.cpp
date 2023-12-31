#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int opcion;

    do
    {
        cout << "Menú:" << endl;
        cout << "1. Divisiones de un número" << endl;
        cout << "2. Suma de los primeros n impares" << endl;
        cout << "3. Impresión de los primeros n números primos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción (1-4): ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            // División de un número
            int numero;
            cout << "Ingrese un número: ";
            cin >> numero;

            cout << "Divisiones de " << numero << ": ";
            for (int i = 1; i <= numero; ++i)
            {
                if (numero % i == 0)
                {
                    cout << i << " ";
                }
            }
            cout << endl;
            break;
        }
        case 2:
        {
            // Suma de los primeros n impares
            int n;
            cout << "Ingrese el valor de n: ";
            cin >> n;

            int suma = 0;
            int impar = 1;

            while (n > 0)
            {
                suma += impar;
                impar += 2;
                --n;
            }

            cout << "La suma de los primeros n impares es: " << suma << endl;
            break;
        }
        case 3:
        {
            // Impresión de los primeros n números primos
            int n;
            cout << "Ingrese el valor de n: ";
            cin >> n;

            cout << "Los primeros " << n << " números primos son: ";
            int numero = 2; // Empezamos desde el primer número primo
            int contador = 0;

            while (contador < n)
            {
                bool esPrimo = true;

                for (int i = 2; i <= sqrt(numero); ++i)
                {
                    if (numero % i == 0)
                    {
                        esPrimo = false;
                        break;
                    }
                }

                if (esPrimo)
                {
                    cout << numero << " ";
                    ++contador;
                }

                ++numero;
            }

            cout << endl;
            break;
        }
        case 4:
            cout << "Programa terminado." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 4);

    return 0;
}


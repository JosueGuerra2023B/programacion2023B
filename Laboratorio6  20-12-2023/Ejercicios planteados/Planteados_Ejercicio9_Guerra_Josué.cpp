#include <iostream>

using namespace std;

int main()
{
	// Ejercicio 9: Arbolito de navidad
  //Pedir al usuario n n�mero
  //Se mostrara el arbolito segun el n�mero
  cout<<"Ejercicio 9: Arbolito navide�o"<<endl;
    cout << "Ingrese el n�mero de ramas del Arbolito de Navidad: ";
    int numRamas;
    cin >> numRamas;
    if (numRamas <= 0)
    {
        cout << "El n�mero debe ser diferente de 0." << endl;
    }
    for (int rama = 1; rama <= numRamas; ++rama)
    {
        for (int espacio = 0; espacio < numRamas - rama; ++espacio)
        {
            cout << " ";
        }
        for (int asterisco = 0; asterisco < 2 * rama - 1; ++asterisco)
        {
            cout << "*";
        }

        cout << endl;
    }

    int espacioTronco = numRamas - 1;
    for (int tronco = 0; tronco < numRamas - 1; ++tronco)
    {
        cout << " ";
    }
    cout << "| |" << endl;

    return 0;
}




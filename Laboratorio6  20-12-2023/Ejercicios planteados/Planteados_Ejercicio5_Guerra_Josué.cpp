#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Ejercicio 5: Suma de las n potencias de 2
  //Pedir al usuario n números para realizar la suma
  //Se realiza el calculo de las n potencias
  
	cout<<"Ejercicio 5: Calculo de la n potencia"<<endl;
    int n;

    cout<<"Potencias de  2^1 + 2^2 + ... + 2^n: "<<endl;
	cout<<"Ingrese un número para calcular la n potencia de 2"<<endl;
    cin >> n;

    if (n < 1)
    {
        cout << "El número debe ser mayor o igual a 1." << endl;
    }
    else
    {
        int resultado = 0;
        cout<<"Su formula es: "<<endl;

        for (int i = 1; i <= n; ++i)
        {
        	cout<<" 2^"<<i;
        	if (i<n)
			{
        		cout<<"+";
			}
        	
            resultado += pow(2, i);
        }
        cout<<endl;
        cout << "El resultado de la suma es: " << resultado << endl;
    }

    return 0;
}


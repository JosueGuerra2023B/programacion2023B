#include <iostream>

using namespace std;

int main()
{
    // Ejercicio 4: calculo de factorial
  //Pedir al usuario un número
  //Realizar el calculo factorial 
  
	int num;
    cout<<" Ejercicio 4: Calculo de factorial"<<endl;
	cout<< "Ingrese un número para calcular su factorial: "<<endl;
    cin >> num;

    if (num < 0)
    {
        cout << "El factorial no no puede ser negativo." << endl;
    }
    else
    {
        int factorial = 1;
        
        cout << "Fórmula del factorial: " << num << "! = ";
        
        for (int i = 1; i <=num; ++i)
        {
        	cout<<i;
        	if (i < num)
        	{
        		cout<< " * ";
        	}
        }
		cout <<endl;

        for (int i = 1; i <= num; ++i)
        {
            factorial *= i;
        }
        cout << "El factorial de " << num << " es: " << factorial << endl;
    
	}
    return 0;
}


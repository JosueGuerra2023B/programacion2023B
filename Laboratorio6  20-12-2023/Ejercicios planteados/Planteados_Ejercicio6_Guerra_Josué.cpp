#include <iostream>

using namespace std;

int main()
{
	// Ejercicio 6: Suma de la serie
  //Pedir al usuario n números para realizar la suma
  //Calcula el resultado de: 1-2+3-4+5-6...n
  
	cout<<"Ejercicio 6: Suma de la serie"<<endl;
    int n;
    
    do{
    	cout<< "Serie de enteros 1 -2 +3 -4 +5... +n -n: "<<endl;
		cout<< "Ingrese hasta que numero desea calcular: "<<endl;
		cin >> n;
		
		if (n < 1)
		{
			cout << "El número debe ser mayor o igual a 1." << endl;
		}
	}while (n<1);
	
	int resultado = 0;
	int i = 1;		
	int signo = 1;
	cout << "Fórmula de la serie: "<<endl;
	
	do
	{
		cout << (signo == 1 ? "" : "-") << i;
		if (i < n)
		{
			cout << (signo == 1 ? " " : " +" );
		}
		resultado += signo * i;
		signo *= -1; 
		i++;
	} while (i <= n);
			
			cout << endl;
			cout << "El resultado de la serie es: " << resultado << endl;
			
    return 0;
}


#include  <iostream>
#include <cmath>

using namespace std;

#define PI 3.1416; //Se define una constante
#define a 12;      //Se define una constante 2

int main()
{
	cout<<" Ejercicio de suma resta y multiplicación usando el valor de PI "<<endl;
	cout<<" El valor de PI es de 3.14.16 "<<endl;
	cout<<" La operación a realizar es, pi * a + 5 - 2  "<<endl;
	
	double pi = PI;
	double solucion; 
	
	solucion = pi * a + 5 - 2;
	
	cout<< "La solución del ejercicio es de: " <<endl;
	cout<<solucion;
	
	return 0;
}


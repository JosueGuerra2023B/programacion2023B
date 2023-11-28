#include  <iostream>
#include <cmath>

using namespace std;

int main()
{
	const float PI = 3.1416; //Se define una constante
	const float e = 2.71828; //Se define otra constante
	float b;
	float c;
	
	
	cout<<" Bienvenido al sistema de cálculo "<<endl;
	cout<<" Ejercicio usando el valor de PI y Euler(e) "<<endl;
	cout<<" El valor de PI es de 3.1416 "<<endl;
	cout<<" El valor de e es de 2.71828 "<<endl;
	
	cout<< " Porfavor coloque un número ";
	cin>>b;
	cout<< " Porfavor coloque otro número ";
	cin>>c;
	
	double pi = PI;
	double solucion; 
	
	solucion = e*sqrt(pi * b + c - 2);
	
	cout<< "La solución del ejercicio es de: " <<endl;
	cout<<solucion;
	
	return 0;
}


#include <iostream>
#include <math.h>
#define PI=

using namespace std;

int main ()
{
     
	//Ejercicio 5
	//intercambair valores entre variables
	int x, y, aux;
	cout <<"Ingrese el valor de x: ";
	cin>>x;
	
	cout <<"Ingrese el valor de y: ";
	cin>>y;

	x=5;
	y=8;
	
	aux=x;
	x=y;
	y=aux;
	 
	cout<< "\n el nuevo valor de x es: "<< x <<endl;
	cout<<"\n el nuevo valor de y es: "<< y <<endl;
	
	return 0;
}
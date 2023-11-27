#include <iostream>
#include <math.h>
#define PI=

using namespace std;

int main ()
{

	//Ejercio 6
	float x, y, resultado=0;
	cout <<"Ingrese el valor de x: "; 
	cin>>x;
	
	cout<<"Ingrese el valor de y: "; 
	cin>>y;
	
	resultado= (sqrt(x))/((pow(y,2))-1);
	cout.precision(2);
	cout<<"El resultado de la expresi�n es: "<<resultado;
	
	return 0;
}
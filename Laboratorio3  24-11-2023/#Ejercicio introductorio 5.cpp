#include <iostream>
#include <math.h>
#define PI=

using namespace std;

int main ()
{

	//Ejercicio 5
	//trabajar con expresiones 
    
	float a, b, c, d, resultado=0;
	cout<<"Ingrese el valor de a: "; 
	cin>>a;
	cout<<"Ingrese el valor de b: "; 
	cin>>b;
	cout<<"Ingrese el valor de c: "; 
	cin>>c;
	cout<<"Ingrese el valor de d: "; 
	cin>>d;
	
	//Operaci�n 
	resultado=a + (b/(c + d));
	cout.precision(2);
	cout<<"El resultado de la rexpresi�nn es: "<<endl;
	cout<<resultado;

	return 0;
}

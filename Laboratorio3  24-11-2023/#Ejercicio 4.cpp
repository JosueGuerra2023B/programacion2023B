#include <iostream>
#include <math.h>
#define PI=

using namespace std;

int main ()
{
	
	//Ejercicio 4
	//Vamos a operar 2.0 
	float a, b, c, d, e, f, resultado=0;
	cout<<"Ingrese el valor de a: "; 
	cin>>a;
	
	cout<<"Ingrese el valor de b: "; 
	cin>>b;
	
	cout<<"Ingrese el valor de c: "; 
	cin>>c;
	
	cout<<"Ingrese el valor de d: "; 
	cin>>d;
	
	cout<<"Ingrese el valor de e: "; 
	cin>>e;
	
	cout<<"Ingrese el valor de f: "; 
	cin>>f;
	
	//operaci�n
	resultado=(a+(b/c))/(d+(e/f));
	cout.precision(3);
	cout<<"El resultado de la operaci�n es: "<<endl;
	cout<<resultado;
	
    return 0;
	
}
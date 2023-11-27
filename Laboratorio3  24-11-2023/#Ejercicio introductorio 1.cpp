#include <iostream>
#include <math.h>
#define PI=

using namespace std;

int main ()
{
    //Ejercicio 1
	float n1, n2, suma=0, resta=0, mult=0, div=0;

	cout<<"Ingrese el n�mero 1: ";
	cin>>n1;
	cout<<"Ingrese el n�mero 2: ";
	cin>>n2;
	
	suma= n1 + n2;
	resta= n1 - n2;
	mult= n1 * n2;
	div= n1 / n2; //por ahora no vamos a comparar la 
	//division por cero 
	
	cout<<"La suma es: "<<suma<<endl;
	cout<<"La resta es: "<<resta<<endl;
	cout<<"La multiplicaci�n es: "<<mult<<endl;
	cout<<"La divisi�n es: "<<div<<endl;
	
	return 0;
}
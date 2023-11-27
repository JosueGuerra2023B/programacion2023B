#include <iostream>
#include <cmath>

using namespace std;

int main ()
{

float a, b, c, d, resultado1, resultado2;
	cout<<"Ingrese el valor de a: "; 
	cin>>a;
	
	cout<<"Ingrese el valor de b: "; 
	cin>>b;
	
	cout<<"Ingrese el valor de c: "; 
	cin>>c;
	
	//Operaciï¿½n 
	float discriminante = b * b - 4 * a * c;
	
	resultado1=(-b - sqrt(b * b - 4 * a * c)) / (2*a);
	
	
	resultado2=(-b + sqrt(discriminante)) / (2*a);
	
	cout<<"El resultado de la rexpresiónn es: "<<endl;
	cout<<resultado1<<endl;
	cout<<"El resultado de la rexpresiónn es: "<<endl;
	cout<<resultado2;
	
	return 0;
		
}

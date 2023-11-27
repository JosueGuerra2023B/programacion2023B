#include <iostream>
#include <math.h>
#define PI=

using namespace std;

int main ()
{

	//Ejercicio 3
	//Entrada de n�meros
	int edad; 
	float altura;	
	char sex[10];
	
	cout<<"Ingrese su edad: ";
	cin>>edad;

	cout<<"Ingrese su genero Masculino o femenino: ";
	cin>>sex;
	
	cout<<"Ingrese su Altura: ";
	cin>>altura;
	
	cout<<"Su edad es: "<<edad<<endl;
	cout<<"Su genero es: "<<sex<<endl;
	cout<<"Su altura es: "<<altura<<endl;

	return 0;
}
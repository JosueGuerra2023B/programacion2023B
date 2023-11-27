#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
	
	//Ejercicio 7
	//Calculo de Hipotenusa 

    float cat1, cat2, hip, resultado1=0, resultado2=0;
    cout<<" Calculo de una hipotenusa con los catetos dados"<<endl;
    cout<<" Usando teorema de Pitágoras"<<endl;
    
	cout<<"Ingrese el valor del primer cateto: "; 
	cin>>cat1;
	cout<<"Ingrese el valor del segundo cateto: "; 
	cin>>cat2;
	
	//Operaciï¿½n 
	float discriminante = cat1 * cat1 + cat2 * cat2;
	
	resultado1=(sqrt(cat1 * cat1 + cat2 * cat2));
	
	
	resultado2=(sqrt(discriminante));
	
	cout<<"El resultado de la Hipotenusa es: "<<endl;
	cout<<resultado1<<endl;
	
    return 0;

}

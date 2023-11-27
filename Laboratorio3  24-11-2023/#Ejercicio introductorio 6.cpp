#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
	
	//Ejercicio 6
	//Notas finales 

    float pra, te, pa, resultado=0, resultado2=0;
    cout<<"Ingrese la notas de correspondientes sobre 10: "<<endl;
    cout<<"Ingrese la nota de practicas (Equivale al 30%): "; 
	cin>>pra;
	cout<<"Ingrese la nota de teoria (Equivale al 60%): "; 
	cin>>te;
	cout<<"Ingrese el valor de participacion (Equivale al 10%): "; 
	cin>>pa;
	
	//Notas
	resultado = (pra * 0.30) + (te * 0.30) + (pa * 0.30); 
	cout.precision(2);
	resultado2 = resultado * 2;
	cout.precision(2);
	
	cout<<"Su nota final es de: "<<endl;
	cout<<resultado<<endl;
	cout<<"Su nota final sobre 20 es de : "<<endl;
	cout<<resultado2;

    return 0;

}

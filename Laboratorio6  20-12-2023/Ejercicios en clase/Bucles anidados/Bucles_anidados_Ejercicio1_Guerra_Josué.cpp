#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main ()
{
	//Ejercicio 1 de ejemplo
	cout<<"Ejercicio 1: "<<endl;
	for (int i = 1;i<= 4; i ++){
		for (int j = 1; j<= 3; j++){
			cout<<" * ";
		}
	}
	
	//Ejercicio 2 tabla de multiplicar
	// 1*1=1
	// 1*2=2
	// 1*3=3
	cout<<"\n";
	cout<<"Ejercicio 2"<<endl;
	int i, j; //Declarar dentro dle for es una buena pr?ctica
	
	//Controla el numero de veces que se repite
	for(i = 1; i<=9; i++){ 
	    cout<<"tabla de multiplicar del "<<i<<endl;
		for(j = 1;j<=10;j++){
			cout<<i<<" x "<<j<<" = "<<i*j<<endl;
			
		}
		cout<<endl<<endl;
		//sirve para poder pausar el sistema 
		//y que solo con una tecla se pueda continuar
		system (" pause ");
		
		//Limpia la pantalla 
		system (" cls ");
	
}
	return 0;
}


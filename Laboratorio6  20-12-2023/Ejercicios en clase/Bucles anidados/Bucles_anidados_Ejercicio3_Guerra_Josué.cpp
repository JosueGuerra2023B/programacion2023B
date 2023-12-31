#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main ()
{
	//Ejercicio 3 Cronometro
		//Contorlar el tiempo 
		//Hacer que se duerma durante un determinado periodo
		//de tiempo
		//timepo en milisegundos
		
		int h,min,seg,x;
		x =1000;
		for(h=0; h<24; h++){
			for(min=0; min<60; min++){
				for(seg=0; seg<60; seg++){
					cout<<h<<" : "<<min<<" : "<<seg<< "\r" ;
					//Duerma un segundo cada 
					Sleep(x);
				}
			}
		}
		system ("pause");
		
		//lr sirve para qeu se remplaze encima, 
	
	return 0;
}


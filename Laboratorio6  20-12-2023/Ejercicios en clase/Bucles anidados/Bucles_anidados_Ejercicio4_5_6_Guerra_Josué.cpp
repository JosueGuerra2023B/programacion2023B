#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main ()
{
	cout<<"Ejercicio 4, 5, 6"<<endl;
	cout<<" ";
	//Ejercicio 4 FILAS Y Columnas de un rectangulo 
		cout<<" Filas y columnas de un rectangulo"<<endl;
		int a, b;
		int c, d;
		cout<<"inserte el numero de filas "<<endl;
		cin>>a; 
		cout<<"inserte el numero de columnas "<<endl;
		cin>>b;
		 
		for (int c = 0;c < a ; c ++){
			cout<<endl;
		for (int d = 0;d < b; d++){
			cout<<" * ";
		}
	}
	
	//Ejercio 5 Filas y columnas de rectangulo 
	//Solo Imprimira el borde del rectángulo 
	cout<<"\n";
	cout<<" ";
	cout<<"Impresión de rectangulo solo el borde"<<endl;
	int m, j;
	int f, l;
		
		cout<<"inserte el numero de filas "<<endl;
		cin>>m; 
		cout<<"inserte el numero de columnas "<<endl;
		cin>>j;
		 
		for (int f = 0 ;f < m ; f++)
		{
			for (int l = 0;l < j ; l++)
			{
				if (f == 0 || f == m -1 || l == 0 ||  l == j-1  )
				{
					cout<<"*";
				}else
				{
					cout<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	//Ejercicio 6 Impresión solo del centro de un cuadrado
	//Solo se imprime el centro del caudarado
	//Deben ser sus lados iguales
	 cout<<"Impresión del centro un cuadrado"<<endl; 
	 int filas, columnas;

    do
    {
        cout<<"inserte el numero de filas "<<endl;
		cin>>filas; 
		cout<<"inserte el numero de columnas "<<endl;
		cin>>columnas;
        if (filas != columnas)
        {
            cout << "Los números deben ser iguales. Intente nuevamente." << endl;
        }

    } while (filas != columnas);

    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            if (i == j || i == filas - 1 - j)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
	
	return 0;
}


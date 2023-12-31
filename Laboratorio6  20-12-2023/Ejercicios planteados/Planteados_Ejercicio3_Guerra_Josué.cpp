#include <iostream>

using namespace std;

int main ()
{ 

  // Ejercicio 3: Promedio de la suma de n numeros
  //Pedir al usuario n números para realizar la suma
  //Despues se hace el calculo del promedio
  cout<<"Ejercicio 3: Promedio de la suma de numeros"<<endl;
  do
  {
  	cout << "Introduzca cuantos numeros quiere sumar: ";
	int contador;
	cin >> contador;
	  
	if (contador <=0)
	{
	  	cout << "El numero a sumar debe ser mayor a 0"<<endl;
		cout << "Inserte nuevamente la cantidad : ";
		cin>>contador;
		
	}
	
	float promedio, cont = contador, operador = 0; 
	int num = 1, suma;
			  
	while (contador > 0)
	{
		cout << "Dame el numero "<<num<< " :";
		cin >> suma;
		operador = operador + suma;
		contador--;
		num++;
	}
	cout << "La suma de los numeros es: " << operador << endl;
	promedio = operador / cont;
	cout<<operador<< " / " <<cont<<" = "<< promedio;
	cout <<"El promedio de la suma es: "<<promedio;
	
}while (false);
return 0;
}



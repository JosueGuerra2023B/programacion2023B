#include <iostream>

using namespace std;

int main ()
{ 

  // Ejercicio 4: Sumar n numeros
  //Pedir al usuario n números para realizar la suma
  
  cout << "Indtroduzca cuantos numeros quiere sumar: ";
  int contador;
  cin >> contador;
  
  if (contador > 0)
  {
  	int operador = 0;
  	int num = 1;
  		
  	while (contador > 0)
	  {
  		cout << "Dame el numero "<<num<< " :";
  		int suma;
  		cin >> suma;
  		operador = operador + suma;
  		contador--;
  		num++;
  	}
  	cout << "La suma de los numeros es: " << operador << endl;
  }else {
  	cout << "Error";
  }
  
  return 0;
}


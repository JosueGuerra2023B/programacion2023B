#include <iostream>

using namespace std;

int main ()
{ 
  // Ejercicio 2
 cout<<"Ejercicio 2: Sumar n numeros e imprimir procedimiento"<<endl;
     
  cout << "Indtroduzca cuantos numeros quiere sumar: ";
  int contador;
  cin >> contador;
  
  if (contador > 0)
  {
  	int operador = 0, i = 1, sum = 0;
  		
  	while (contador > 0)
	  {
  		cout << "Dame el número " << i <<" : "<< endl;
  		int val;
  		cin >> val;
  		operador = sum ;
  		sum = sum + val;
  		cout << operador << " + " << val << " = " << sum << endl;
		contador--;
  		i++;
  	}
  	cout << "La suma de los numeros es: " << sum << endl;
  }else {
  	cout << "Error";
  }

return 0;

}


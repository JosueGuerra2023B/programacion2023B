#include <iostream>
using namespace std;
int main ()
{ 
  // Ejercicio 8: Número perfecto
  //Solicitar al usuario n cantidad de números.
  //Ver cual de ellos es perfecto 
  
 cout<<"Ejercicio 8: Número perfecto"<<endl;
 cout<<" Ejemplo: 6 =1+2+3."<<endl;
 
 do
 {
 	cout << "Introduzca cuantos numeros quiere sumar: ";
	 int n;
	 cin >> n;
	 
	 if (n <=0)
	 {
	 	cout<<"Inserte un número mayor a 0"<<endl;
	 	cin>>n;
	 }
			   
	int num = 1;		  
	while (n > 0)
	{
		cout << "Dame el numero "<<num<< " :";
		int n2;
		cin >> n2;
		
		int div = 0;
		
		for (int i =1; i <=n2/2; ++i)
		{
			if (n2 % i == 0)
			{
				div +=i;
			}
			
		}
		if (div == n2)
		{
			cout<<n2<< " Es un numero perfecto."<<endl;
			cout<<"\n";
			
		}else
		{
			cout<<n2<< " No es un numero perfecto."<<endl;
			cout<<"\n"; 
		}
		n--;
		num++;
	}
  }while(false);
  return 0;
}

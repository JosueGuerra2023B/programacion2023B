#include <iostream>

using namespace std;

int main ()
{ 
  // Ejercicio 3: Pedir al usuario un numero para 
  //imprimir de forma tanto ascendente como descendente

  int numero;
  cout << "Ingrese un numerto entero: ";
  cin >> numero;

  int i = 0;
  cout << "---Forma ascendente---" << endl;
  while (i <= numero){
    cout << i << endl;
    i = i + 1;
  }
  cout<<"\n";

  int j = numero;
  cout << "---Forma descendente---" << endl;
  while (j >= 0){
    cout << j << endl;
    j--;
  }
  
  return 0;
}


# include <iostream>
using namespace std;
int main()
{
// Ejercicio1: Imprimir pares e impares.

   int i, opcion, par = 0, impar = 1;
   cout << "Ingrese un numero entero: ";
   cin >> i;

   cout << "Ingrese el numero de la opcion que desea" << endl;
   cout << "1. Pares" << endl ;
   cout << "2. Impares"<< endl;
   cin >> opcion;
   cout<<"\n";
   switch (opcion)
   {
   case 1:
    do {
        par = par + 2;
        cout << par << endl;
    }while (par < i);
    break;
    
   case 2:
    do {
        cout << impar << endl;
        impar = impar + 2;
    }while (impar <= i);
    break;
    
   default:
    cout << "Seleccion invalida...";
    break;
   }
   return 0;
}


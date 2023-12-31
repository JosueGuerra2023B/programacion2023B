#include <iostream>

using namespace std;

int main ()
{ 
    
    // Operadores 
    int x = 10;
    int y = ++x;
    int z = x+2;

    cout<<" x = "<< x <<endl;
    cout<<" y = "<< y <<endl;
    cout<<" z = "<< z <<endl;
    cout<<"\n";
   
    int v = 120;   //Asignamos a x 120
    int b = ++x;   //++x significa preincremento, significa que primera incrementa en 1 el valor de x y luego asigno el balor a y, y = 121 y x = 121
    int n = x--;   // x -- significa posdecremento, lo que significa que primero asigna el valor actual de x a z y luego decremente en 1 el valor de x
    // entonces x = 121, z = 121 y luego decremento a x, x = 120 y z = 121
    
    cout <<" v = "<< x <<endl;
    cout <<" b = "<< y <<endl;
    cout <<" n = "<< z <<endl;
    cout<<"\n";
    
    int m = 120;
    int l = x++;
    int k = --x;

    cout <<" m = "<< x <<endl;
    cout <<" l = "<< y <<endl;
    cout <<" k = "<< z <<endl;
  
   
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    // Ejercicio de precedencia
    // Ejercicios de ejemplo 
    //Ejemplo 1

    float a=2, b=9, c=15, d=4;

    cout << (2+9)*15 <<endl;
    cout << a + b * c / d <<endl;
    cout << (a + b) * c / d <<endl;
    cout << (a + b) * (c / d) <<endl;
    cout <<a* ((( c + 2 )+ 3) + d )<<endl;
    
    cout<<"Ejemplo 2"<<endl;
    //Ejemplo2
    float z=5, m=9, v=8, n=12;

    cout << (5+9)*12 <<endl;
    cout <<  z + m * n / v <<endl;
    cout << (m + z) * n / v <<endl;
    cout << (z + m) * (v / n) <<endl;
    cout << m * ((( v + 2 )+ 3) + z )<<endl;
     
    return 0;

}
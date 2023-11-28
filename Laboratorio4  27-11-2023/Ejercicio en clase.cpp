#include <iostream>
using namespace std;

int main()
{
    //EJERCICIOS GUIADOS EN CLASE 
    //Ejercicio de precendencia
    
    float x=3, y=2, z=12, a=5, b=4;
    
    cout << (3+2)*5 <<endl;
    cout << x + y* z / a <<endl;
    cout << (x + y) * z / a <<endl;
    cout << (x + y) * (z / a) <<endl;
    cout <<a* ((( b + 2 )+ 3) + z );
    

    //millon lineas más abajo
    
    cout<<"Ingresa un número: ";
    int num1;             //Es preferible declarar variables lo más cerca
    cin>> num1;           //Si se puede declarar para no subir tanto 
    
    //millon lineas más abajo
    
    cout<<"Ingresa un número: ";
    int num123; 
    cin>> num123;
    

    //conversion implicita

    int r =48.1;         // El compilador solo lee el entero
    cout<<r<<endl;
    int s =-28.1213;
    cout<<s<<endl;

    float num = 1.999999; // Perdida de precisión
    double num2 = 1.999999; //Almacena más bits, suficientes bits para evitar la perdida de precisión
    cout<<num<<endl<<num2;

    bool b = 15.1;          // 1 es verdadero 
    cout<< b<<endl; 

    bool a = 0;
    cout<< a;

    //Conversion explicita
    //Forzar a la conversion
    int longitud =18342;
    int altitud = 1123;
    double pendiente;
    
    pendiente = static_cast<double>(altitud) / longitud;
    pendiente = double(altitud) / longitud;  // Estilo C++ antiguo
    pendiente = (double)altitud / longitud;  // Estilo C
    cout<< " La pendiente es: "<<pendiente<<endl; 
    
 
 
    return 0;
}
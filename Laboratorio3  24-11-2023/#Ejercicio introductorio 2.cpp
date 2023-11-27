 #include <iostream>
#include <math.h>
#define PI=

using namespace std;

int main ()
{

	// Ejercicio 2
    // Salida de producto
	float nom, prod, prod_iva, prod_fin, iva= 0.12;
	cout<<"Ingrese el nombre del producto: ";
	cin>>nom;
	cout<<"Ingrese el precio del producto: ";
	cin>>prod;
	
	prod_iva= prod * iva;
	prod_fin= prod + prod_iva;
	
	cout<<"El iva es de: "<<iva<<endl;
	cout<<"El precio del producto es: "<<prod_fin;
	
	return 0;
}

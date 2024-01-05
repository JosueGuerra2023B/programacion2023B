#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int n = 0;
double n1 = 0, n2 = 0, n3 = 0;

void op() 
{
	cout<<"-/---/ Calculadora /---/-"<<endl;
	cout <<"1. Suma" << endl;
    cout <<"2. Resta" << endl;
    cout <<"3. Modulo" << endl;
    cout <<"4. Division" << endl;
    cout <<"5. Multiplicacion" << endl;
    cout <<"0  Salir" << endl;
    cout << "\nIngrese el tipo de operacion a realizar: ";
    cin >> n;
}
void num()
{
    for (int i = 1; i <= 3; ++i) {
        cout << "Ingrese el numero " << i << " : ";
        double val;
        cin >> val;
        
        switch (i) {
            case 1:
                n1 = val;
                break;
            case 2:
                n2 = val;
                break;
            case 3:
                n3 = val;
                break;
        }
    }
}

void roperacion(double resultado, const char* operacion)
{
	cout<<" El resultado de "<<operacion<< " es: "<<resultado<<endl;
	cout<<"\n"<<endl;
}
void suma()
{
	num();
	roperacion(n1 + n2 + n3, "Suma");
}
void resta()
{
	num();
	roperacion(n1 - n2 - n3, "Resta");
}
void modulo()
{
	cout<<"El ejercicio solo toma""\n\los 2 primeros para caclcular"<<endl;
	num();
	roperacion(fmod(n1, n2), "Modulo");
}
void division()
{
	do{
		num();
		if (n2 == 0)
		{
			cout<<"No es posible la division para 0"<<endl;
		}else{
			roperacion((n1 / n2) / n3 , "Division");
		}
	}while (n3 == 0);
}
void multiplicacion()
{
	num();
	roperacion(n1 * n2 * n3, "Multipliacion");
}
 
int main ()
{
	do{
		op();
		switch (n){
			case 0:
				cout<<"/*-+ Programa finalizado +-*/"<<endl;
				system("pause");
				break;
			case 1:
				suma();
				break;
			case 2:
				resta();
				break;
			case 3:
				modulo();
				break;
			case 4:
				division();
				break;
			case 5:
				multiplicacion();
				break;
			default:
				cout<< "\nOpcion no encontrada\n"<<endl;
				cout<< "Ingrese nuevmanete cualquiera de las opciones"<<endl;
				break;					
		}
	}while (n != 0);
	return 0;
}

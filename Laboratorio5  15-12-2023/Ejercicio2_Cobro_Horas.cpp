#include <iostream>

using namespace std;

int main() 
{
	string op;
	int h;
	
	cout<<" --//--//--// Estacionamiento Delux --//--//--//-- "<<endl;
    cout<<" \n";
	
    do{
    	cout << "Ingrese la cantidad de horas que ha utilizado el estacionamiento: "<<endl;
		cin >> h;
		
		const double h1_2 = 5.00;
		const double h3_a_5 = 4.00;
		const double h6_a_10 = 3.00;
		const double h11 = 2.00;
		double costoTotal = 0.0;
		
		if (h > 0) 
		{
			if (h >= 2) 
			{
				costoTotal += 2 * h1_2;
				h -= 2;
			}else {
				cout<< "\n"<<endl;
			}
			
			if (h >= 3) 
			{
				costoTotal += 3 * h3_a_5;
				h -= 3;
			}else {
				cout<< "\n"<<endl;
			}
			
			if (h >= 5) 
			{
				costoTotal += 5 * h6_a_10;
				h -= 5;
			}else {
				cout<< "\n"<<endl;
			}
			if (h > 0) 
			{
				costoTotal += h * h11;
			}else {
				cout<< "\n"<<endl;
			}
			
		}
		cout << "El costo total del estacionamiento es: $" << costoTotal << endl;
		cout << " Desea insertar un periodo: (presione 1.)" << endl;
        cout << " Si desea salir: (presione 2.)" << endl;

        cin >> op;
        
	}while (op == "1");

    if (op == "2")
    {
        cout << "         Vuelva Pronto" << endl;
        cout << " ________________________________ " << endl;
        cout << "|       |    Gracias     |       |" << endl;
        cout << "|   _   |    por usar    |   _   |" << endl;
        cout << "|  | |  |                |  | |  |" << endl;
        cout << "|  |_|  |                |  |_|  |" << endl;
        cout << "|       |    nuestro     |       |" << endl;
        cout << "|       |    Sistema     |       |" << endl;
        cout << "|_______|________________|_______|" << endl;
    }
    cout << "Creado Por Josue Guerra";

    return 0;
}


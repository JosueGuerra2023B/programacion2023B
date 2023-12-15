#include <iostream>

using namespace std;

int main()
{
    cout<<" --//--//--// Compra un regalo segun tu saldo --//--//--//-- "<<endl;
    cout<<" \n";
	string op;

    do
    {
    
        cout << "            \\--\\-- En detallitos cariñositos --//--//"<<endl;
        cout<<" \n";
		cout << " Las opciones que tenemos para ofrecerte segun tu presupuesto son: "<<endl;
		cout << "                       --  Tarjetas   --                       "<<endl;
		cout << "                       --   Flores    --                       "<<endl;
		cout << "                       --   Anillo    --                       "<<endl;
		cout << "                       -- Chocolates  --                       "<<endl;
		cout<<" \n";
		cout << "Inserte su nombre" << endl;
        string nom;
        cin >> nom;

        double val;
        do
        {
            cout << "Ingrese su presupuesto para el regalo: " << endl;
            cout<< "$ "; 
            cin >> val;

            if (val <= 0)
            {
                cout << "El presupuesto debe ser mayor que 0. Inténtelo nuevamente." << endl;
            }

        } while (val <= 0);

        double fin;

        if (val <= 10)
        {
            cout << "Genial "<<nom<< " Puedes comprar una tarjeta: "<<endl; 
        }
        else if (val >= 11 && val <= 100)
        {
        	cout << "Genial "<<nom<< " Puedes comprar Chocolates y tarjeta: "<<endl; 
        }
        else if (val >= 101 && val <= 250)
        {
        	cout << "Genial "<<nom<< " Puedes comprar Flores, chocolates y una tarjeta: "<<endl; 
        }
        else if (val > 251)
        {
        	cout << "Genial "<<nom<< " Puedes comprar Un Anillo, flores, chocolates y una tarjeta: "<<endl; 
        }
        else
        {
        	cout<<" \n";
        }

        cout << " Desea insertar un nuevo presupuesto: (presione 1.)" << endl;
        cout << " Si desea salir: (presione 2.)" << endl;

        cin >> op;

    } while (op == "1");

    if (op == "2")
    {
    	cout << " Has comprado un bonito regalo para esa persona "<<endl;
        cout << "           Vuelve Pronto" << endl;
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


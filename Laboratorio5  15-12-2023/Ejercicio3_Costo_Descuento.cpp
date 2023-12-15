#include <iostream>

using namespace std;

int main()
{
    cout<<" --//--//--// Bienvenido al sistema de costo y descuento --//--//--//-- "<<endl;
    cout<<" \n";
	string op;

    do
    {
        cout << "Inserte el nombre del artIculo a comprar" << endl;
        string art;
        cin >> art;

        double val;
        do
        {
            cout << "Ingrese el valor del artIculo: " << endl;
            cin >> val;

            if (val <= 0)
            {
                cout << "El valor del artIculo debe ser mayor que 0. Inténtelo nuevamente." << endl;
            }

        } while (val <= 0);

        double fin;

        if (val < 100)
        {
            fin = val - (val * 0.10);
            cout << "El costo inicial es de: " << val << endl;
            cout << "Aplicando un descuento del 10%" << endl;
            cout << "El precio final es de: " << fin << endl;
        }
        else if (val > 100 && val < 200)
        {
            fin = val - (val * 0.12);
            cout << "El costo inicial es de: " << val << endl;
            cout << "Aplicando un descuento del 12%" << endl;
            cout << "El precio final es de: " << fin << endl;
        }
        else if (val >= 200)
        {
            fin = val - (val * 0.15);
            cout << "El costo inicial es de: " << val << endl;
            cout << "Aplicando un descuento del 15%" << endl;
            cout << "El precio final es de: " << fin << endl;
        }
        else
        {
            cout << "El costo inicial es de: " << val << endl;
            cout << "Sin descuento aplicado" << endl;
            cout << "El precio final es de: " << val << endl;
        }

        cout << "Si desea añadir otro artículo: (presione 1.)" << endl;
        cout << "Para salir: (presione 2.)" << endl;

        cin >> op;

    } while (op == "1");

    if (op == "2")
    {
        cout << "Vuelva Pronto" << endl;
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




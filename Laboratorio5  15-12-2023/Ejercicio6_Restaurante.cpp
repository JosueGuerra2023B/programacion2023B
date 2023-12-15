#include <iostream>

using namespace std;

int main() 
{
    double a, b, c, tot, totalVentas = 0;
    int op;

    do {
        cout << "Bienvenidos al Naufrago Satisfecho" << endl;
        cout << "Te ofrecemos 3 tipos de hamburguesas" << endl;

        cout << "/////***/////***/////***/////***/////" << endl;
        cout << "|1. (S), Sencillas $20|" << endl;
        cout << "|2. (D), Dobles $25|" << endl;
        cout << "|3. (T), Triples $28|" << endl;

        cout << "Escoge la opcion que vas a comprar: ";
        cin >> a;

        while (a < 1 || a > 3) 
        {
            cout << "Opcion no valida. Por favor, elige una opcion del 1 al 3." << endl;
            cout << "Escoge la opción que vas a comprar: ";
            cin >> a;
        }

        cout << "Ingrese el numero de hamburguesas que desea: ";
        cin >> b;

        cout << "Pago en: "; 
        cout << "Efectivo (1): "; 
        cout << "Tarjeta (2): ";
        cin >> c;

        while (c != 1 && c != 2) 
        {
            cout << "Opcion no valida. Por favor, elige 1 para efectivo o 2 para tarjeta." << endl;
            cout << "Pago en efectivo (1) o tarjeta (2): ";
            cin >> c;
        }

        switch (static_cast<int>(a)) 
        {
            case 1:
                switch (static_cast<int>(c)) 
                {
                    case 1:
                        tot = b * 20;
                        break;
                    case 2:
                        tot = b * 20 + (b * 20 * 0.05);
                        break;
                }
                break;
            case 2:
                switch (static_cast<int>(c)) 
                {
                    case 1:
                        tot = b * 25;
                        break;
                    case 2:
                        tot = b * 25 + (b * 25 * 0.05);
                        break;
                }
                break;
            case 3:
                switch (static_cast<int>(c)) 
                {
                    case 1:
                        tot = b * 28;
                        break;
                    case 2:
                        tot = b * 28 + (b * 28 * 0.05);
                        break;
                }
                break;
        }

        totalVentas += tot;  // Acumular el total de la venta

        cout << "El total a pagar es: $" << tot << endl;
        cout << "Si desea seguir pidiendo presione 1, si desea salir presione 2: ";
        cin >> op;

    } while (op == 1);

    if (op == 2) 
    {
        cout << "El total de su compra es: $" << totalVentas << endl;
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


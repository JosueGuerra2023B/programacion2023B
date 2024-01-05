#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <windows.h>

using namespace std;

double m = 0, v = 0;
int numPerdidas = 0;
string nombre;

void inicio()
{
	cout<<"    ---// Bienvenido //---    "<<endl;
	cout<<" Juego de la carta intermedia"<<endl;
	cout<<" Inserte su nombre para comenzar: "<<endl;
    cin>>nombre;
}
void pedirMonto()
{
    cout << "Ingrese el monto total a jugar: "<<endl;
    cin >> m;
}

void valorApostar()
{
    while (true)
    {
        cout << "Ingrese el valor a apostar (menos del 30% de su dinero en bolsa): ";
        cin >> v;
        if (v <= m * 0.3)
            break;
        else
            cout << "La cantidad ingresada no puede sobrepasar el 30% de su monto actual." << endl;
    }
}

int cartaAleatoria(set<int> &cartasUsadas)
{
    int carta;
    do
    {
        carta = rand() % 10 + 1;
    } while (cartasUsadas.count(carta) > 0);

    cartasUsadas.insert(carta);
    return carta;
}

bool cartaIntermedia(int a, int b, int c)
{
    return (a < c && c < b) || (b < c && c < a);
}

void mostrarApuestas(double apuestaJugador, double apuestaComputadora)
{
    cout << "Apuesta jugador: " << apuestaJugador << endl;
    cout << "Apuesta computadora: " << apuestaComputadora << endl;
    cout<<"\n";
}

void mostrarResultado(double bolsa, double monto)
{
    cout << "Bolsa: " << bolsa << " Monto restante: " << monto << endl;
    cout<<"\n";
}

int main()
{
	srand(time(0));
    double bolsa = 0;

    inicio();
	pedirMonto();

    do
    {
        int x, y, z;
        set<int> cartasUsadas;

        valorApostar();
        m -= v;

        x = cartaAleatoria(cartasUsadas);
        y = cartaAleatoria(cartasUsadas);
        z = cartaAleatoria(cartasUsadas);

        cout << "Cartas en la mesa: " << x << " " << y << endl;

        if (v > 0)
        {
            cout << "Desea seguir jugando? (Si/No): "<<endl;
            string respuesta;
            cin >> respuesta;
            cout<<"\n";

            if (respuesta == "No" || respuesta == "no")
            {
                mostrarApuestas(v * 0.95, 0);
                bolsa += v * 0.05;
                v -= v * 0.05;
            }
            else
            {
                mostrarApuestas(v, v * 2);
            }
        }

        cout << "Carta siguiente: " << z << endl;
        Sleep(3000);

        if (cartaIntermedia(x, y, z))
        {
            cout << "¡Has ganado!" << endl;
            bolsa += v * 2;
            numPerdidas = 0;
        }
        else
        {
            cout << "La casa gana." << endl;
            numPerdidas++;

            if (m < m * 0.03 || numPerdidas >= 3)
            {
                cout <<" Has perdido el juego "<<nombre<< endl;
                break;
            }
        }

        mostrarResultado(bolsa, m);

    } while (true);

    return 0;
}

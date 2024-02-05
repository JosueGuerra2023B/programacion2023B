#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para lanzar los dados
int lanzarDados(int &dado1, int &dado2) {
    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;
    return dado1 + dado2;
}

// Función principal
void determinarResultado(int apuestaJugador, int apuestaCasa) {
    int dado1, dado2;
    int suma;
    int punto = 0;
    int lanzamiento = 0;
    int lanzamientosExitosos = 0;

    do {
        if (lanzamiento == 0) {
            cout << "Primer lanzamiento:" << endl;
        } else {
            cout << "Lanzamiento " << lanzamiento << ":" << endl;
        }

        cout << "Presione 1 para lanzar los dados: ";
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            suma = lanzarDados(dado1, dado2);
            cout << dado1 << " + " << dado2 << " = " << suma << endl;

            if (lanzamiento == 0) {
                if (suma == 7 || suma == 11) {
                    cout << "¡Has ganado! Ganaste $" << apuestaCasa << endl;
                    break;
                } else if (suma == 2 || suma == 3 || suma == 12) {
                    cout << "¡Craps! Has perdido. La casa Gana" << endl;
                    break;
                } else {
                    punto = suma;
                    cout << "Punto establecido: " << punto << endl;
                }
            } else {
                if (suma == punto) {
                    lanzamientosExitosos++;

                    if (lanzamientosExitosos >= 2 && (suma == 7 || suma == 11)) {
                        cout << "¡Has ganado! Ganaste el 40% de la apuesta de la casa: $" << 0.4 * apuestaCasa << endl;
                        break;
                    }
                } else if (lanzamiento == punto) {
                	cout << " LLegaste al limite de tus intentos, del punto establecido"<<endl;
                    cout << "¡Craps! Has perdido. La casa Gana" << endl;
                    break;
                }
            }

            lanzamiento++;
        } else {
            cout << "Opción no válida." << endl;
        }
    } while (true);
}

int main() {
    srand(time(0));  

    cout << "          --Bienvenido al juego de Craps--               " << endl;

    char opcionSalida;
    do {
        int apuestaJugador, apuestaCasa;

        do {
            cout << "Ingrese el monto que quiere apostar (entre $10 y $100): ";
            cin >> apuestaJugador;

            if (apuestaJugador < 10 || apuestaJugador > 100) {
                cout << "Monto no válido. Debe ser entre $10 y $100. Intente nuevamente." << endl;
            }

        } while (apuestaJugador < 10 || apuestaJugador > 100);

        apuestaCasa = 2 * apuestaJugador;

        determinarResultado(apuestaJugador, apuestaCasa);

        cout << "¿Quieres jugar de nuevo? (S (si) |/| N (no)): ";
        cin >> opcionSalida;

        if (opcionSalida == 'N' || opcionSalida == 'n') {
            break;
        }

    } while (true);

    return 0;
}



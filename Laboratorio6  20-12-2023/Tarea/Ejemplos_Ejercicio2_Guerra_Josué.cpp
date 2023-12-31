#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int intValue = 12345;
    double doubleValue = 1234.56789;

    //Se usa setw y setfill para formatear la salida
    cout << setw(10) << setfill('0') << intValue << endl;

    // Uso de setprecision y fixed para formatear la salida de un número de punto flotante
    cout << fixed << setprecision(2) << doubleValue << endl;

    return 0;
}



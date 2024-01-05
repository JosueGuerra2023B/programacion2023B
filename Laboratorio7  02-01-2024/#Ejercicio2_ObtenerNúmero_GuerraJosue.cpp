#include <iostream>
#include <cmath>

using namespace std;

int ParteEntera(double numero) {
    return static_cast<int>(numero);
}
int Centenas(double numero) {
    return abs(numero) / 100;
}
int Decenas(double numero) {
    return static_cast<int>(abs(numero) / 10) % 10;
}
int Unidades(double numero) {
    return static_cast<int>(abs(numero)) % 10;
}
double ParteDecimal(double numero) {
    return abs(numero - static_cast<int>(numero));
}
int Decimas(double numero) {
    return abs(ParteDecimal(numero) * 1000) / 100;
}
int Centesimas(double numero) {
    return static_cast<int>(abs(static_cast<int>(ParteDecimal(numero) * 1000) / 10) % 10);
}

int Milesimas(double numero) {
    return static_cast<int>(abs(static_cast<int>(ParteDecimal(numero) * 1000) % 10));
}

int main() {
	cout<<"             -- Bienvenido --            "<<endl;
	cout<<"El programa indicara el numero por partes"<<endl;
    double numero_a_separar;
    cout << "Ingrese un numero: ";
    cin >> numero_a_separar;
    cout<<"\n";

    cout << "Parte entera: " << ParteEntera(numero_a_separar) << endl;
    cout << Centenas(numero_a_separar) << (Centenas(numero_a_separar) == 1 ? " Centena" : " Centenas") << endl;
    cout << Decenas(numero_a_separar) << (Decenas(numero_a_separar) == 1 ? " Decena" : " Decenas") << endl;
    cout << Unidades(numero_a_separar) << (Unidades(numero_a_separar) == 1 ? " Unidad" : " Unidades") << endl;
    cout<<"\n";

    cout << "Parte decimal: " << ParteDecimal(numero_a_separar) << endl;
    cout << Decimas(numero_a_separar) << (Decimas(numero_a_separar) == 1 ? " Decima" : " Decimas") << endl;
    cout << Centesimas(numero_a_separar) << (Centesimas(numero_a_separar) == 1 ? " Centesima" : " Centesimas") << endl;
    cout << Milesimas(numero_a_separar) << (Milesimas(numero_a_separar) == 1 ? " Milesima" : " Milesimas") << endl;

    return 0;
}


#include <iostream>
using namespace std;

int mayor(int x, int y, int z) {
    if (x > y && x > z) {
        return x;
    } else if (y > x && y > z) {
        return y;
    } else {
        return z;
    }
}
int medio(int x, int y, int z) {
    if ((x > y && x < z) || (x > z && x < y)) {
        return x;
    } else if ((y > x && y < z) || (y > z && y < x)) {
        return y;
    } else {
        return z;
    }
}
int menor(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else {
        return z;
    }
}
void num(int &n1, int &n2, int &n3)
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

int main() {
    int a = 0, b = 0, c = 0;

    cout<<"             -- Bienvenido --            "<<endl;
	cout<<"El programa indicara el numero mayor de 3"<<endl;
	cout << "\n";
    num(a ,b, c);
    cout<<"\n";
    cout << "El mayor de los numeros " << a << " | " << b << " | " << c << " es: " << mayor(a, b, c) << endl;
    cout << "Con el siguiente orden de mayor a menor:" << endl;
    cout << mayor(a, b, c) << " > " << medio(a, b, c) << " > " << menor(a, b, c) << " ";

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
	cout<<"Ejercicio 1: Rango de menor a mayor"<<endl;
    int num1, num2;

    do
    {
        cout << "Ingrese el primer numero: " << endl;
        cin >> num1;

        cout << "Ingrese el segundo numero: " << endl;
        cin >> num2;

        if (num1 > num2)
        {
            cout << "El primer numero debe ser menor o igual al segundo."<<endl;  
			cout << "Ingrese los valores nuevamente" << endl;
        }
    } while (num1 > num2);

    cout << "Los valores entre " << num1 << " y " << num2 << " son:" << endl;
    for (int i = num1 + 1; i <= num2 - 1; ++i)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}


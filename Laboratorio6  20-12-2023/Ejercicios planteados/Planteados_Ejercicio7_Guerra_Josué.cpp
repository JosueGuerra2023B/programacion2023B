#include <iostream>

using namespace std;

int main()
{
   // Ejercicio 7: Serie de fibonacci
  //Pedir al usuario n números
  //Se mostrara hasta ese número o el anterior si es el caso 
  cout<<"Ejercicio 7: Serie de fibonacci"<<endl;
  
    int n;
    cout<<"\n";

    do
    {
    	cout<<" Para mostrar la serie de Fibonacci hasta n valor "<<endl;
        cout<<" Ingrese un número: "<<endl;
        cin >> n;

        if (n < 0)
        {
            cout << "Ingrese el número correcto" << endl;
        }

    } while (n < 0);

    int a = 0, b = 1, c;

    cout << "Serie de Fibonacci hasta " << n << ": ";

    while (a <= n)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }

    cout << endl;

    return 0;
}


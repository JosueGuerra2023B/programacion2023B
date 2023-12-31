# include <iostream>
using namespace std;

int main()
{
	// For
   //Estructura
   // for (exp1; expresion logica; exp2){
   //exp1- inicializador el interador
   //exp2- iterador avance
       // conjunto de instrucciones
   //}
  // Ejercicio 2: Usar for para imprimir las potencias de 3 y 5 de forma inversa

    cout<<"Potencias en forma inversa"<<endl; 
	cout<< " Potencias de 3 y 5"<<endl;
	cout << "Ingrese la cantidad de potencias que desea imprimir: "<<endl;
    int potencias;
	cin >> potencias;

    cout << "Potencias de 3 en orden inverso:" << endl;
    for (int exponente = potencias - 1; exponente >= 0; --exponente)
    {
        int resultado = 1;
        for (int i = 0; i < exponente; ++i)
        {
            resultado *= 3;
        }
        cout << resultado << " ";
    }
    cout << "\n\nPotencias de 5 en orden inverso:" << endl;
    for (int exponente = potencias - 1; exponente >= 0; --exponente)
    {
        int resultado = 1;
        for (int i = 0; i < exponente; ++i)
        {
            resultado *= 5;
        }
        cout << resultado << " ";
    }

   return 0;
   }
   

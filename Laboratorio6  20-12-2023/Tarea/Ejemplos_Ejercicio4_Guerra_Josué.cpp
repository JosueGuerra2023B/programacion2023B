#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE) ;
	cout << "Ingresa una frase: "<<endl;
    string frase;
    getline(cin, frase); 
    int longitud = frase.length();
    
    cout << "La frase tiene " << longitud << " caracteres." << endl;

return 0;
}

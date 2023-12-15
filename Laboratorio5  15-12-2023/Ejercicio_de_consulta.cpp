# include <iostream>
# include <iomanip>

using namespace std;
int main ()
{
	//IF NOTAS
	//Ejercicio de ejemplo 
	//Josué Guerra
	float nota1, nota2, nota3;

	cout << "Ingresa tu nota de programacion: ";
	cin >> nota1;
	cout << "Ingrese tu nota de redes: ";
	cin >> nota2;
	cout << "Ingresa tu nota de sistemas operativos: ";
	cin >> nota3;
	
	float notas;
	notas = (nota1 + nota2 + nota3)/3;
	cout << fixed << setprecision(2);
	/*
	if (notas <= 20)
	{
		cout << "Usted esta aprobado" << endl;
	}else {if (notas <= 14)
	{
		cout << "Usted se quedo a supletorios";
	}
	else{cout << "Usted perdio las materias";
	}
	}
	*/

	cout<<notas <<" " <<((notas >= 14 && notas <= 20 )? "Usted aprobo ": " Usted se quedo a supletorios");

		 return 0;
}


#include <iostream>
#include <string>

using namespace std;

int main() {
    double op1, op2, op3, op4, resultado, plan;
    string op;

    do {
        cout << "Bienvenido al sistema digital de la póliza Internacional" << endl;
        cout << "Plan (A) cobertura amplia $1200" << endl;
        cout << "Plan (B) daños y terceros $950" << endl;
        cout << "Escoja el plan que desea adquirir (A) o (B): ";
        cin >> op;

        while (op != "A" && op != "B") {
            cout << "Escoja correctamente cualquiera de las dos OPCIONES (A o B)" << endl;
            cout << "Escoja el plan que desea adquirir (A) o (B): ";
            cin >> op;
        }

        if (op == "A") {
            plan = 1200;
        } else if (op == "B") {
            plan = 950;
        }

        int a, b, c, d;

        do {
            cout << "Consume bebidas alcohólicas - 1 si | 2 no: ";
            cin >> a;
            if (a != 1 && a != 2) {
                cout << "Por favor, elija la opción 1 o 2" << endl;
            }
        } while (a != 1 && a != 2);

        do {
            cout << "Usa lentes - 1 si | 2 no: ";
            cin >> b;
            if (b != 1 && b != 2) {
                cout << "Por favor, elija la opción 1 o 2" << endl;
            }
        } while (b != 1 && b != 2);

        do {
            cout << "Padece alguna enfermedad (Deficiencia cardíaca, diabetes) - 1 si | 2 no: ";
            cin >> c;
            if (c != 1 && c != 2) {
                cout << "Por favor, elija la opción 1 o 2" << endl;
            }
        } while (c != 1 && c != 2);

        do {
            cout << "Tiene más de 40 años - 1 si | 2 no: ";
            cin >> d;
            if (d != 1 && d != 2) {
                cout << "Por favor, elija la opción 1 o 2" << endl;
            }
        } while (d != 1 && d != 2);

        if (a == 1) {
            op1 = plan  * 0.10;
        } else {
            op1 = 0;
        }

        if (b == 1) {
            op2 = plan * 0.05;
        } else {
            op2 = 0;
        }

        if (c == 1) {
            op3 = plan * 0.05;
        } else {
            op3 = 0;
        }

        if (d == 1) {
            op4 = plan * 0.20 ;
        }else if(d == 2)
		{
			op4 = plan * 0.10 ;
        	
        }else {
            op4 = 0;
        }

        resultado = op1 + op2 + op3 + op4 + plan;

        cout << "El costo de su plan es de: $" << resultado << endl;
        cout << "Si desea solicitar nuevamente un plan, presione 1. Para salir, presione 2: ";
        cin >> op;

    } while (op == "1");

    if (op == "2") 
    {
        cout << "Vuelva Pronto" << endl;
        cout << " ________________________________ " << endl;
        cout << "|       |    Gracias     |       |" << endl;
        cout << "|   _   |    por usar    |   _   |" << endl;
        cout << "|  | |  |                |  | |  |" << endl;
        cout << "|  |_|  |                |  |_|  |" << endl;
        cout << "|       |    nuestro     |       |" << endl;
        cout << "|       |    Sistema     |       |" << endl;
        cout << "|_______|________________|_______|" << endl;
    }
    cout << "Creado Por Josue Guerra";

    return 0;
}



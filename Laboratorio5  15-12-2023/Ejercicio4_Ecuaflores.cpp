#include <iostream>
using namespace std;

const float rosa = 0.75;
const float clavel = 0.50;
const float girasol = 1.00;

const float plastico = 0.75;
const float carton = 0.50;

const float terrestre = 95.00;
const float aereo = 125.00;
const float maritimo = 100.00;

const float ganancia = 0.65;
const float bonchesMinimos = 8;

int arregloTipoA[] = {5, 2, 4};
int arregloTipoB[] = {10, 4, 7};
int arregloTipoC[] = {8, 5, 3};

void detarr(int op) 
{
    cout << "Detalle del Tipo ";
    switch (op) 
    {
        case 1:
            cout << "A:" << endl;
            cout << "   - 5 rosas rojas" << endl;
            cout << "   - 2 girasoles" << endl;
            cout << "   - 4 claveles" << endl;
            break;
        case 2:
            cout << "B:" << endl;
            cout << "   - 10 rosas rojas" << endl;
            cout << "   - 4 girasoles" << endl;
            cout << "   - 7 claveles" << endl;
            break;
        case 3:
            cout << "C:" << endl;
            cout << "   - 8 rosas rojas" << endl;
            cout << "   - 5 girasoles" << endl;
            cout << "   - 3 claveles" << endl;
            break;
        default:
            cout << "Tipo no válido" << endl;
    }   
}

double costarre(int* arreglo) 
{
    return arreglo[0] * rosa + arreglo[1] * girasol + arreglo[2] * clavel;
}

double costenvo(char envo) 
{
    return (envo == 'P') ? plastico : carton;
}

double Sumaenvo(char envo, double costarre)
{
    switch (envo)
    {
        case 'P':
            return costarre + 0.75;
        case 'C':
            return costarre + 0.50;
        default:
            return costarre;
    }
}

double costen(char metodoEnvio)
{
    switch (metodoEnvio)
    {
        case '1':
            return terrestre;
        case '2':
            return aereo;
        case '3':
            return maritimo;
        default:
            return 0.0;
    }
}

double calgan(double costoTotal)
{
    return costoTotal * ganancia;
}

void mostrarDetallesOperacion(int bonches, char envo, char metodoEnvio, int op) 
{
    cout << "\nDetalles de la operación:\n";
    cout << "   Cantidad de Bonches: " << bonches << endl;
    cout << "   Material de Envoltura: " << ((envo == 'P') ? "Plastico" : "Carton") << endl;
    cout << "   Método de Envío: ";
    switch (metodoEnvio) 
    {
        case '1':
            cout << "Terrestre";
            break;
        case '2':
            cout << "Aereo";
            break;
        case '3':
            cout << "Maritimo";
            break;
        default:
            cout << "No especificado";
    }
    cout << endl;
}

void mostrarDetallesCostos(double costoArreglo, double costoEnvoltura, double costoen, double costoTotal, int bonches) 
{
    cout << fixed;
    cout.precision(2);
    cout << "   Costo Arreglo: $" << costoArreglo << endl;
    cout << "   Costo Envoltura por bonche: $" << costoEnvoltura << endl;
    
    cout << "   Costo Envío: $" << costoen << endl;
    cout << "   Costo Total: $" << costoTotal << endl;
    cout << "   Recuerde que por cada bonche" << endl;
    cout << "   vienen 5 arreglos de un mismo tipo" << endl;
}

void mostrarDetallesGanancia(double ganancia) 
{
    cout << "   Ganancia (" << ganancia << "%): $" << ganancia << endl;
    cout << " \n"<<endl;
    cout << " -*-*-*-*/ Gracias por usar nuestro Sistema / *-*-*-*-"<<endl;
    cout<<" Creado por Josué Guerra ";
}

int main() 
{
    int op;
    do 
    {
        cout << " -/-/-/-/-/- Bienvenido a \"Ecuaflor\" -/-/-/-/-/- " << endl;
        cout << " Seleccione el tipo de arreglo a comprar: " << endl; 
        cout << " (1: Tipo A =  5 Rosas rojas, 2 Girasoles, 4 Claveles) " << endl;
        cout << " (2: Tipo B = 10 Rosas rojas, 4 Girasoles, 7 Claveles) " << endl;
        cout << " (3: Tipo C =  8 Rosas rojas, 5 Girasoles, 3 Claveles) " << endl;
        cin >> op;
        if (op < 1 || op > 3) 
        {
            cout << "Opción incorrecta. Inténtelo de nuevo." << endl;
        }
    } while (op < 1 || op > 3);

    int bonches;
    do
    {
        cout << " Ingrese la cantidad de bonches (mayor a 8): " << endl;
        cin >> bonches;
    } while (bonches <= bonchesMinimos);   
    
    char envo;
    do 
    {
        cout << " Seleccione el material de envoltura: " << endl; 
		cout << " (P: Plastico --- $0.75) " << endl; 
		cout << " (C: Carton   --- $0.50): " << endl;
        cin >> envo;
        envo = toupper(envo);
    } while (envo != 'P' && envo != 'C');
    
    char metodoEnvio;
    do 
    {
        cout << "Seleccione el metodo de envio: " << endl; 
        cout << " (1: Terrestre --- $95.00) " << endl; 
		cout << " (2: Aereo     --- $125.00) " << endl;
		cout << " (3: Maritimo  --- $100.00) " << endl;
        cin >> metodoEnvio;
        metodoEnvio = toupper(metodoEnvio);
    } while (metodoEnvio != '1' && metodoEnvio != '2' && metodoEnvio != '3');
    
    int* arregloSeleccionado;
    switch (op) 
    {
        case 1:
            arregloSeleccionado = arregloTipoA;
            break;
        case 2:
            arregloSeleccionado = arregloTipoB;
            break;
        case 3:
            arregloSeleccionado = arregloTipoC;
            break;
    }

    detarr(op);
    
    double costoArreglo = costarre(arregloSeleccionado);
    double costoEnvoltura = Sumaenvo(envo, costoArreglo);
    double costoen = costen(metodoEnvio);
    
    double costoTotal = ((bonches * 5) * costoEnvoltura) + costoen;
    double ganancia = calgan(costoTotal);
    
    mostrarDetallesOperacion(bonches, envo, metodoEnvio, op);
    mostrarDetallesCostos(costoArreglo, costoEnvoltura, costoen, costoTotal, bonches);
    mostrarDetallesGanancia(ganancia);

    return 0;
}


# include <iostream>
# include <string>

using namespace std;

int main (){
    // Proforma para viaje

    cout << "---Seleccion de Paquetes Turisticos---" << endl << "1. Luna de Miel" << endl << "2. Paquete Aventura" << endl << "3. Paquete Cultural" << endl << "4. Paquete Familiar" << endl;
    int seleccion;
    cout << "Ingrese su seleccion: "; cin >> seleccion;
    while (seleccion < 1 || seleccion > 4){
        cout << "Seleccion no valida" << endl << "Ingrese su seleccion: "; cin >> seleccion;
    }

    cout << "---Seleccion de Destinos---" << endl << "1. Tokyo" << endl << "2. Kyoto" << endl << "3. Dinamarca" << endl << "4. Francia" << endl;
    int seleccionDestino;
    cout << "Ingrese su seleccion: "; cin >> seleccionDestino;
    while (seleccionDestino < 1 || seleccionDestino > 4){
        cout << "Seleccion no valida" << endl << "Ingrese su seleccion: "; cin >> seleccionDestino;
    }

    cout << "---Registro de fechas---" << endl;
    cout << "Ingrese la fecha de inicio del viaje: "; string inicio; cin >> inicio;
    cout << "Ingrese la fecha de fin del viaje: "; string fin; cin >> fin;

    cout << "---Resgistro personas---" << endl;
    int numeroPersonas = 0;
    int personas;
    if (seleccion == 1){
        numeroPersonas = 2;
        cout << "Recuerde dos personas ya estan incluidas (pareja)" << endl;
        cout << "Ingrese el numero de personas que se incluiran en el viaje:"; cin >> personas;

        numeroPersonas += personas;
    }
    else if (seleccion == 2) {
        cout << "Ingrese el numero de personas que iran al viaje: "; cin >> personas;
        numeroPersonas += personas;
    }
    else if (seleccion == 3) {
        cout << "Ingrese el numero de personas que iran al viaje: "; cin >> personas;
        numeroPersonas += personas;
    }
    else if (seleccion == 4) {
        cout << "Ingrese el numero de personas que iran al viaje: "; cin >> personas;
        numeroPersonas += personas;
    }

    cout << "---Registro Alojamiento---" << endl << "1. Hotel" << endl << "2. Cabaña" << endl << "3. Resort" << endl;
    int seleccionAlojamiento;
    cout << "Ingrese su seleccion: "; cin >> seleccionAlojamiento;
    while (seleccionAlojamiento < 1 || seleccionAlojamiento > 3){
        cout << "Seleccion no valida" << endl << "Ingrese su seleccion: "; cin >> seleccionAlojamiento;
    }

    cout << "---Registro Transporte---" << endl << "1. Avion" << endl << "2. Crucero" << endl;
    int seleccionTransporte;
    cout << "Ingrese su seleccion: "; cin >> seleccionTransporte;
    while (seleccionTransporte < 1 || seleccionTransporte > 2){
        cout << "Seleccion no valida" << endl << "Ingrese su seleccion: "; cin >> seleccionTransporte;
    }

    cout << "---Registro Actividades Extra---" << endl << "1. Expedicion" << endl << "2. Cena" << endl << "3. Campamento" << endl;
    int seleccionActividades;
    cout << "Si no desea registrar ninguna actividad ingrese 0" << endl << "Ingrese su seleecion: "; cin >> seleccionActividades;
    while (seleccionActividades != 0 && seleccionActividades != 1 && seleccionActividades != 2 && seleccionActividades != 3){
        cout << "Seleccion invalida" << endl << "Ingrese su seleccion: "; cin >> seleccionTransporte;
    }

    cout << "----Valor del viaje---" << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream> 
#include <limits>
#include <stdio.h>
#include <wchar.h>
#include <locale>

using namespace std;

struct Proforma {
    int id;
    string tipo;
    string regalo;
    int cantidad[99];
    string producto[99];
    int aux1=0;
};

vector<Proforma> proformas;

int generarID() {
    return rand() % 9000 + 1000;
}

string intToString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

int stringToInt(const string& str) {
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

struct Cliente {
    string nombre;
    string apellido;
    string direccion;
    int cedula; // Cambiado a tipo entero para almacenar la cédula como número
    string correo;
};

struct Viaje {
	string paquetes;
    string destino;
    string fechaInicio;
    string fechaFinal;
    string alojamiento; 
    string transporte;
    string extras;
    string comentarios;
};

int aux1;
string atletismo="A";
int botellas=5;
int zapatos=12;
int cantidad1;
int cantidad2;
string natacion="N";
string camping="C";
string fisico="F";

vector<Cliente> clientes;

void escribirArchivo(Proforma& proforma) {
    string id_str = intToString(proforma.id);
    ofstream archivo(("proforma_" + id_str + ".txt").c_str());

    if (archivo.is_open()) {
    	Viaje nuevoViaje;
        archivo << "Proforma de " << proforma.tipo << endl;
        archivo << "Destino: " << nuevoViaje.destino << endl;
        archivo << "Fecha de Inicio: " << nuevoViaje.fechaInicio << endl;
        archivo << "Fecha de Final: " << nuevoViaje.fechaFinal << endl;
        archivo << "Alojamiento: " << nuevoViaje.alojamiento << endl;
        archivo << "Transporte: " << nuevoViaje.transporte << endl;
        archivo << "Extras: " << nuevoViaje.extras << endl;
        archivo << "Comentario: " << nuevoViaje.comentarios << endl;
        archivo.close();
        cout << "Archivo de proforma creado correctamente: proforma_" << id_str << ".txt" << endl;
        cout <<"\n";
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void escribirArchivo2(Proforma& proforma) {
	int i=0;
    ofstream archivo(("proforma_" + intToString(proforma.id) + ".txt").c_str());

    if (archivo.is_open()) {
        archivo << "Proforma de " << proforma.tipo << endl;
        for(int i=0;i<1;i++){
		archivo<< "Productos comprados"<<endl;
		archivo<<proforma.producto[i]<<" "<<"Cantidad: "<<proforma.cantidad[i]<<endl;
	   }
        archivo.close();
        cout << "Archivo de proforma creado correctamente: proforma_" << proforma.id << ".txt" << endl;
        cout <<"\n";
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}


void abrirProforma() {
    int id;
    cout << "Ingrese el ID de la proforma que desea abrir: ";
    cin >> id;

    string id_str = intToString(id);
    string comando = "notepad proforma_" + id_str + ".txt";
    system(comando.c_str());
}
void registrosViaje() {
    Viaje nuevoViaje;
    int opcion;
    
	cout<<endl;
    cout << "      Destinos del Viaje    " << endl;
    cout << "1. Salinas \n2. Montañita  \n3. Galápagos \n4. Paris \n5. Kioto \n6. Italia " << endl;
    cout << "Seleccione el destino del viaje: ";
    cin >> opcion;
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    switch (opcion) {
        case 1:
            nuevoViaje.destino = "Salinas";
            break;
        case 2:
            nuevoViaje.destino = "Montañita";
            break;
        case 3:
            nuevoViaje.destino = "Galápagos";
            break;
        case 4:
            nuevoViaje.destino = "Paris";
            break;
        case 5:
        	nuevoViaje.destino = "Kioto";
        	break;
        case 6:
        	nuevoViaje.destino = "Italia";
        	break;
        default:
            cout << "Opción inválida. Se asignará un destino por defecto." << endl;
            nuevoViaje.destino = "Destino no especificado";
    }
    cout<<endl;
    cout << "      Alojamiento del Viaje    " << endl;
	cout << "1. Hotel \n2. Resort \n3. Cabaña  \n4. Habitaciones" << endl;
    cout << "Seleccione el destino del viaje: ";
    cin >> opcion;
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    switch (opcion) {
        case 1:
            nuevoViaje.alojamiento = "Hotel";
            break;
        case 2:
            nuevoViaje.alojamiento = "Resort";
            break;
        case 3:
            nuevoViaje.alojamiento = "Cabaña";
            break;
        case 4:
            nuevoViaje.alojamiento = "Habitaciones";
            break;
        default:
            cout << "Opción inválida. Se asignará un alojamiento por defecto." << endl;
            nuevoViaje.alojamiento = "Alojamiento no especificado";
    }
    cout<<endl;
    
    cout << "      Transporte del Viaje    " << endl;
	cout << "1. Autobús \n2. Avión + Taxi  \n3. Carro privado" << endl;
    cout << "Seleccione el destino del viaje: ";
    cin >> opcion;
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    switch (opcion) {
        case 1:
            nuevoViaje.transporte = "Autobús";
            break;
        case 2:
            nuevoViaje.transporte = "Avión + Taxi";
            break;
        case 3:
            nuevoViaje.transporte = "Carro privado";
            break;
        default:
            cout << "Opción inválida. Se asignará un transporte por defecto." << endl;
            nuevoViaje.transporte = "Tranporte no especificado";
    }
    cout<<endl;
    
    cout << "      Extras del Viaje    " << endl;
	cout << "1. Excursiones \n2. Eventos  \n3. Atención VIP" << endl;
    cout << "Seleccione el destino del viaje: ";
    cin >> opcion;
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    switch (opcion) {
        case 1:
            nuevoViaje.extras = "Excursiones";
            break;
        case 2:
            nuevoViaje.extras = "Eventos";
            break;
        case 3:
            nuevoViaje.extras = "Atencion VIP";
            break;
        default:
            cout << "Opción inválida. Se asignará un extra por defecto." << endl;
            nuevoViaje.extras = "Extra no especificado";\
    }
    cout<<endl;
    
    cout << "Ingrese la fecha de inicio del viaje: ";
    getline(cin, nuevoViaje.fechaInicio);
    cout << "Ingrese la fecha final del viaje: ";
    getline(cin, nuevoViaje.fechaFinal);
    
    cout << "Escriba el comentario adicional: ";
    getline(cin, nuevoViaje.comentarios);      		
}

void crearProforma() {
    Proforma nueva_proforma;
    nueva_proforma.id = generarID();

    cout << "¿Qué tipo de proforma desea crear?" << endl;
    cout << "1. Proforma de Viaje" << endl;
    cout << "2. Proforma de Regalo" << endl;

    int opcion;
    cout << "-----------------------"<<endl;
	cout << "Ingrese su selección: ";
    cin >> opcion;
    string inicio, fin; 
    cout << "------------------------"<<endl;
    cout<<"\n";

    switch(opcion) {
        case 1:
            nueva_proforma.tipo = "Viaje";
            cout<<"      Paquete Turistico    "<<endl;
            cout<<"Seleccione el paquete que desea: \n1. Paquete Luna de Miel \n2. Paquete Aventura \n3. Paquete Cultural \n4. Paquete Familiar"<<endl;
            int opcion2;
            cout << "-------------------"<<endl;
            cout<<"Ingrese su eleccion: ";
            cin>>opcion2;
            cout << "--------------------"<<endl;
            cout<<"\n";
            switch (opcion2){
            	case 1:
            		registrosViaje();
            		break;
            	case 2:
            		registrosViaje();
            		break;
            	case 3:
            		registrosViaje();
            		break;
            	case 4:
            		registrosViaje();
            		break;
            	default:
            		cout<<"Opción inválida" << endl;
            		return;
			}
            break;
        case 2:
            do{
			
            	nueva_proforma.tipo = "Regalo";
            	cout<<"Bienvenido al apartado de regalo"<<endl;
            	cout<<"Disponemos de las siguientes categorias de regalos: "<<endl;
            	cout<<"Atletismo "<<"(ID "<<atletismo<<")"<<endl;
            	cout<<"Natacion "<<"(ID "<<natacion<<")"<<endl;
            	cout<<"Camping "<<"(ID "<<camping<<")"<<endl;
            	cout<<"Fisico Culturismo"<<"(ID "<<fisico<<")"<<endl;
            	cout << "--------------------------------------------------"<<endl;
            	cout<<"Ingrese la opcion que desee: (Ingrese 0 para salir): ";
            	string deseo;
            	cin>>deseo;
            	cout << "--------------------------------------------------"<<endl;
            	if (deseo==atletismo){
            		int salir;
            		int i=0;
					do{
						cout<<"\nAtletismo Productos"<<endl;
            			cout<<"1) Zapatos"<<"(en stock"<<zapatos<<" pares)"<<endl;
            			cout<<"2) Botellas de agua"<<"(en stock "<<botellas<<")"<<endl;
            			cout << "----------------------"<<endl;
            			cout<<"Seleccione su regalo: ";
            			int regalo;
            			cin>>regalo;
            			cout << "-----------------------"<<endl;
				
            			if (regalo==1){
            				
            				i=0;
            				if (zapatos!=0){
            					
            		 			nueva_proforma.producto[i]="Zapatos";
            		 			cout<<"Ingrese la cantidad de zapatos que desea: ";
            		 			cin>>nueva_proforma.cantidad[i];
            		 			nueva_proforma.aux1=nueva_proforma.aux1+nueva_proforma.cantidad[i];
            		 			zapatos=zapatos-nueva_proforma.cantidad[i];
            				}else{
            					
            					cout<<"No disponemos"<<endl;
							}
               			}
          
						if (regalo==2){
							i=1;
							if(botellas!=0){
					 			nueva_proforma.producto[i]="Botellas";
					 			cout<<"Ingrese la cantidad de botellas que desea: ";
					 			cin>>nueva_proforma.cantidad[i];
            		 			botellas=botellas-nueva_proforma.cantidad[i];
					 			nueva_proforma.aux1=nueva_proforma.aux1+nueva_proforma.cantidad[i];	
							}else{
					 			cout<<"No disponemos"<<endl;	
					   		}
				    	}
            			cout<<"Desea seguir comprando en esta seccion(Escoja 3 para salir)";
            			cin>>salir;
					}while(salir!=3);
					if(deseo==natacion){
						
						cout<<"Natacion"<<endl;
						cout<<"Productos"<<endl;
					}
					if(deseo==camping){
						cout<<"Camping"<<endl;
						cout<<"Productos";
					}
					if (deseo==fisico){
						cout<<"Fisico culturismo"<<endl;
						cout<<"Productos"<<endl;
					}
       			}
   			}while(opcion==0);
			
            break;
        default:
            cout << "Opción inválida" << endl;
            return;
    }

    proformas.push_back(nueva_proforma);
    cout << "\n";
    escribirArchivo(nueva_proforma);
}


void mostrarProformas() {
    if (proformas.empty()) {
        cout << "No hay proformas para mostrar." << endl;
        return;
    }

    for (size_t i = 0; i < proformas.size(); i++) {
        cout << "Proforma: " << proformas[i].id << " - Tipo: " << proformas[i].tipo << endl;
    }
    cout << "\n";
}

void eliminarProforma() {
    if (proformas.empty()) {
        cout << "No hay proformas para eliminar." << endl;
        cout <<"\n";
        return;
    }

    int id;
    cout << "Ingrese el ID de la proforma que desea eliminar: ";
    cin >> id;
    cout << "Esta seguro de querer eliminar está proforma"<<endl;
    cout << "-------------------------"<<endl;
	cout << "1. Si"<<endl<<"2. No"<<endl;
    int opcion;
    cin >> opcion;
    cout << "-------------------------"<<endl;
    if (opcion == 1) {
        for (int i = 0; i < proformas.size(); ++i) {
            if (proformas[i].id == id) {
                proformas.erase(proformas.begin() + i);
                if (remove(("proforma_" + intToString(id) + ".txt").c_str()) != 0) {
                    cout << "Error al eliminar el archivo de la proforma." << endl;
                } else {
                    cout << "Proforma con ID " << id << " eliminada correctamente." << endl;
                    cout <<"\n";
                }
                return;
            }
        }
        cout << "No se encontró ninguna proforma con el ID proporcionado." << endl;
    } else {
        cout << "No se pudo eliminar la proforma." << endl;
        cout << "No autorizado por el usuario." << endl;
    }
}

void menuOpciones(){
	int seleccion;
    do {
        cout << "=== Viajes BOROJO ===" << endl;
        cout << " Le da la bienvenida";
        cout << "\n";
        cout << "1. Crear una nueva proforma" << endl << "2. Mostrar proformas creadas (solo ID)" << endl << "3. Abrir una proforma por ID" << endl << "4. Eliminar una proforma por ID" << endl  << "5. Finalizar Programa" << endl;
        cout << "------------------------"<<endl;
		cout << "Ingresa tu seleccion: ";
        cin >> seleccion;
        cout << "------------------------"<<endl;
        cout <<"\n";

        switch (seleccion) {
            case 1:
                crearProforma();
                break;
            case 2:
                mostrarProformas();
                break;
            case 3:
                abrirProforma();
                break;
            case 4:
                eliminarProforma();
                break;
            case 5:
                cout << "Gracias por tu visita :D";
                exit(0);
                break;
            default:
                cout << "Selección no válida." << endl;
                break;
        }

    } while (seleccion != 6);
}

void cargarClientes() {
    ifstream archivo("CLIENTES.txt");
    if (archivo.is_open()) {
        string linea;
        Cliente cliente;
        while (getline(archivo, linea)) {
            if (linea.find("Nombre: ") != string::npos) {
                cliente.nombre = linea.substr(8);
            } else if (linea.find("Apellido: ") != string::npos) {
                cliente.apellido = linea.substr(10);
            } else if (linea.find("Dirección: ") != string::npos) {
                cliente.direccion = linea.substr(11);
            } else if (linea.find("Cédula: ") != string::npos) {
                cliente.cedula = stringToInt(linea.substr(8));
            } else if (linea.find("Correo electrónico: ") != string::npos) {
                cliente.correo = linea.substr(21);
                clientes.push_back(cliente);
            }
        }
        archivo.close();
    }
}
void registrarCliente() {
    cargarClientes(); 

    Cliente nuevoCliente;
    cout << "=== Registro de Cliente ===" << endl;
    cout << "Ingrese su número de cédula: ";
    
    bool cedulaValida = false;
    while (!cedulaValida) {
        cin >> nuevoCliente.cedula;

        // Verificación de que la cédula tenga exactamente 10 dígitos
        if (cin.fail() || nuevoCliente.cedula < 0 || nuevoCliente.cedula > 9999999999) {
            cout << "Cédula no válida. Debe contener exactamente 10 dígitos. Inserte nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cedulaValida = true;
        }
    }

    bool cedulaExiste = false;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].cedula == nuevoCliente.cedula) {
            cedulaExiste = true;
            break;
        }
    }

    if (cedulaExiste) {
        cout << "La cédula ya está registrada." << endl;
        cout << "Acceda como ususario frecuente\n" << endl;
        return;
    }

    cout << "Ingrese su nombre: ";
    getline(cin >> ws, nuevoCliente.nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, nuevoCliente.apellido);
    cout << "Ingrese su dirección: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese su correo electrónico: ";
    getline(cin, nuevoCliente.correo);

    ofstream archivo("CLIENTES.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nuevoCliente.nombre << endl;
        archivo << "Apellido: " << nuevoCliente.apellido << endl;
        archivo << "Dirección: " << nuevoCliente.direccion << endl;
        archivo << "Cédula: " << nuevoCliente.cedula << endl;
        archivo << "Correo electrónico: " << nuevoCliente.correo << endl;
        archivo << "---------------------------------------" << endl;
        archivo.close();
        cout << "Usuario creado. Sus datos han sido almacenados." << endl;
        cout <<"\n";
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
    menuOpciones();
}

void guardarClientes() {
    ofstream archivo("CLIENTES.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < clientes.size(); ++i) {
            archivo << "Nombre: " << clientes[i].nombre << endl;
            archivo << "Apellido: " << clientes[i].apellido << endl;
            archivo << "Dirección: " << clientes[i].direccion << endl;
            archivo << "Cédula: " << clientes[i].cedula << endl;
            archivo << "Correo electrónico: " << clientes[i].correo << endl;
            archivo << "---------------------------------------" << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void actualizarInformacionUsuario() {
    cargarClientes();

    int cedula;
    cout << "Ingrese la cédula del usuario que desea actualizar: ";
    cin >> cedula;

    bool encontrado = false;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].cedula == cedula) {
            Cliente& cliente = clientes[i];
            int opcion;
            do {
                cout << "=== Actualizar Información del Cliente ===" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Apellido" << endl;
                cout << "3. Dirección" << endl;
                cout << "4. Correo electrónico" << endl;
                cout << "5. Volver al menú anterior" << endl;
                cout << "------------------------"<<endl;
                cout << "Ingrese su seleccion: ";
                cin >> opcion;
                cout << "-------------------------"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (opcion) {
                    case 1:
                        cout << "Ingrese el nuevo nombre: ";
                        getline(cin >> ws, cliente.nombre);
                        break;
                    case 2:
                        cout << "Ingrese el nuevo apellido: ";
                        getline(cin, cliente.apellido);
                        break;
                    case 3:
                        cout << "Ingrese la nueva dirección: ";
                        getline(cin, cliente.direccion);
                        break;
                    case 4:
                        cout << "Ingrese el nuevo correo electrónico: ";
                        getline(cin, cliente.correo);
                        break;
                    case 5:
                        cout << "Ingresar al menu de opciones." << endl;
                        break;
                    default:
                        cout << "Selección no válida. Por favor, ingrese una opción válida." << endl;
                        break;
                }
            } while (opcion != 5);
            guardarClientes();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado." << endl;
    } else {
        guardarClientes();
        cout << "Información del cliente actualizada correctamente." << endl;
    }
}

void accederUsuario() {
    int intentos = 2;
    int cedula;
    bool acceso = false;

    while (intentos > 0) {
        cout << "Ingrese su número de cédula: ";
        cin >> cedula;

        cargarClientes();

        for (size_t i = 0; i < clientes.size(); ++i) {
            if (clientes[i].cedula == cedula) {
                cout << "Acceso como usuario frecuente exitoso.\n" << endl;
                acceso = true;
                menuOpciones();
                break;
            }
        }

        if (acceso) {
            break;
        } else {
            cout << "Número de cédula incorrecto. Intentos restantes: " << intentos << endl;
            intentos--;
        }
    }

    if (!acceso) {
        cout << "No se pudo acceder como usuario frecuente. Ingrese como un nuevo usuario." << endl;
        registrarCliente();
    }
    menuOpciones();
}


void menuInicial() {
    int opcion;
    do {
    	cout << "=== Viajes Borojo ===\n" << endl;
        cout << "=== Menú Inicial ===" << endl;
        cout << "1. Crear un nuevo usuario\n2. Usuario Frecuente\n3. Actualizar información de usuario\n4. Finalizar programa" << endl;
        cout << "------------------------"<<endl;
		cout << "Ingrese su seleccion: ";
        cin >> opcion;
        cout << "------------------------"<<endl;
        cout << endl;

        switch (opcion) {
            case 1:
                registrarCliente();
                break;
            case 2:
                accederUsuario();
                break;
            case 3:
                actualizarInformacionUsuario();
                break;
            case 4:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                exit(0);
                break;
            default:
                cout << "Selección no válida. Por favor, ingrese una opción válida." << endl;
                break;
        }
    } while (opcion != 4);
}

int main() {
	setlocale(LC_ALL, "");
    srand(time(NULL));
    menuInicial(); 
    
    return 0;
}




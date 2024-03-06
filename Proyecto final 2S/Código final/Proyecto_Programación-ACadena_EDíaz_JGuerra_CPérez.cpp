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
string nombreProducto;
int cantidad;

struct Proforma {
    int id;
    string tipo;
    string regalo;
    int cantidad[99];
    string producto[99];
    float costo;
    float resultado;
    string paquetes;
    string destino;
    string alojamiento; 
    string transporte;
    string extras;
    string comentarios;
    int cantidadExtras;
    int cantidadPaquetes;
    int cantidadDestino;
    int cantidadTransporte;
    int cantidadAlojamiento;
    int porcentajeAumento;
    float precioTotal;
    float precio;
    int personas;
 	int dia;
    int mes;
    int anio;
    string fechaInicio;
    string fechaFinal;
};


struct Producto {
    string nombre;
    int stock;
};


bool creacionStock(const string& nombre_archivo) {

  ifstream archivo("stock.txt");

  if (archivo.is_open()) {
  	     
    return false;
  }
	ofstream archivo_nuevo("stock.txt");
	if(archivo_nuevo.is_open()){
		 archivo_nuevo<<"Botellas"<<" "<<5<<endl;
	 	 archivo_nuevo<<"Zapatos"<<" "<<12<<endl;
	 	 archivo_nuevo<<"Cuerdas"<<" "<<20<<endl;
	 	 archivo_nuevo<<"Tobilleras"<<" "<<23<<endl;
	 	 archivo_nuevo<<"Gafas"<<" "<<10<<endl;
	 	 archivo_nuevo<<"Trajes"<<" "<<3<<endl;
	 	 archivo_nuevo<<"Toallas"<<" "<<15<<endl;
	 	 archivo_nuevo<<"PATODELUXE"<<" "<<1<<endl;
	 	 archivo_nuevo<<"Carpas"<<" "<<12<<endl;
	 	 archivo_nuevo<<"Sacos"<<" "<<10<<endl;
	 	 archivo_nuevo<<"Kit"<<" "<<3<<endl;
	 	 archivo_nuevo<<"Linternas"<<" "<<10<<endl;
	 	 archivo_nuevo<<"Suplementos"<<" "<<10<<endl;
	 	 archivo_nuevo<<"Mancuernas"<<" "<<10<<endl;
	 	 archivo_nuevo<<"Subscripcion"<<" "<<10<<endl;
	 	 archivo_nuevo<<"Kitencasa"<<" "<<10<<endl;
	 	 
		return true;
	}

}

void actualizarStock(const string& nombreProducto, int cantidad,int stock) {
    ifstream archivoEntrada("stock.txt");
    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    vector<Producto> productos;
    Producto producto;
    bool encontrado = false;

    while (archivoEntrada >> producto.nombre >> producto.stock) {
        if (producto.nombre == nombreProducto) {
            encontrado = true;
            if (producto.stock >= cantidad) {
                producto.stock -= cantidad;
            } else {
                cout << "No hay suficiente stock disponible." << endl;
                return;
            }
        }
        productos.push_back(producto);
    }

    archivoEntrada.close();

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
        return;
    }

    ofstream archivoSalida("stock.txt");
    if (!archivoSalida) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

   
    vector<Producto>::iterator it = productos.begin();
    while (it != productos.end()) {
        archivoSalida << it->nombre << " " << it->stock << endl;
        ++it;
    }

    cout << "Compra realizada con �xito. Stock actualizado." << endl;
}



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
    long long cedula;
     // Cambiado a tipo entero para almacenar la c�dula como n�mero
    string correo;
    
};


string atletismo="A";
string natacion="N";
string camping="C";
string fisico="F";

vector<Cliente> clientes;


void escribirArchivo1(Proforma& proforma) {
    ofstream archivo(("proforma_" + intToString(proforma.id) + ".txt").c_str());
    if (archivo.is_open()) {
    	Proforma fechaInicio, fechaFinal;
    	int i=0;
        archivo << "Proforma de " << proforma.tipo << endl;
        for (int i = 0; i < 1; i++) { // Solo para el primer elemento, adaptar seg�n necesidad
            archivo << "Paquete: " << proforma.paquetes << " Cantidad: " << proforma.cantidadPaquetes << endl;
            archivo << "Destino: " << proforma.destino << " Cantidad: " << proforma.cantidadDestino << endl;
            archivo << "Fecha de Inicio: " << proforma.fechaInicio << endl;
			archivo << "Fecha de Final: " << proforma.fechaFinal << endl;
            archivo << "Alojamiento: " << proforma.alojamiento << " Cantidad: " << proforma.cantidadAlojamiento << endl;
            archivo << "Transporte: " << proforma.transporte << " Cantidad: " << proforma.cantidadTransporte << endl;
            archivo << "Extras: " << proforma.extras << " Cantidad: " << proforma.cantidadExtras << endl;
            archivo << "Comentario: " << proforma.comentarios << endl;
            archivo << "Precio Total: " << proforma.precioTotal << endl;
        }
        archivo.close();
        cout << "Archivo de proforma creado correctamente: proforma_" << proforma.id << ".txt" << endl;
        cout << "\n";
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
		archivo<<proforma.producto[i]<<endl<<"cantidad: "<<proforma.cantidad[i]<<endl;
		archivo<<"TOTAL: "<<proforma.resultado;
	   }
        archivo.close();
        cout << "Archivo de proforma creado correctamente: proforma_" << proforma.id << ".txt" << endl;
        cout <<"\n";
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

Proforma convertirStringAProforma(const string& fecha) {
    Proforma proforma;
    istringstream ss(fecha);
    ss >> proforma.dia >> proforma.mes >> proforma.anio;
    return proforma;
}

int diferenciaDias(const string& fechaInicio, const string& fechaFinal) {
    Proforma inicio = convertirStringAProforma(fechaInicio);
    Proforma final = convertirStringAProforma(fechaFinal);
    int inicioDias = inicio.anio * 365 + inicio.mes * 30 + inicio.dia;
    int finalDias = final.anio * 365 + final.mes * 30 + final.dia;
    return finalDias - inicioDias;
}

void abrirProforma() {
    int id;
    cout << "Ingrese el ID de la proforma que desea abrir: ";
    cin >> id;

    string id_str = intToString(id);
    string comando = "notepad proforma_" + id_str + ".txt";
    system(comando.c_str());
}
void registrosViaje1(){
    Proforma nueva_proforma;
    nueva_proforma.id = generarID();
    int i=0;
    nueva_proforma.tipo="Viaje";
    cout<<"      Paquete Turistico    "<<endl;
    cout<<"Seleccione el paquete que desea: \n1. Paquete Luna de Miel $1800 \n2. Paquete Aventura $1500 \n3. Paquete Cultural $1350 \n4. Paquete Familiar $2000"<<endl;
    int opcion;
    cout<<"Ingrese su eleccion: ";
    cin>>opcion;
    cin.ignore();

    switch (opcion) {
        case 1:
            nueva_proforma.paquetes = "Luna de Miel ";
            nueva_proforma.cantidadPaquetes=2*1800;
            break;
        case 2:
            nueva_proforma.paquetes = "Aventura";
            cout<<"Cuantas personas van a viajar: ";
            cin>>nueva_proforma.personas;
            nueva_proforma.cantidadPaquetes = nueva_proforma.personas*1500;
            break;
        case 3:
            nueva_proforma.paquetes = "Cultural";
            cout<<"Cuantas personas van a viajar: ";
            cin>>nueva_proforma.personas;
            nueva_proforma.cantidadPaquetes = nueva_proforma.personas*1350;
            break;
        case 4:
            nueva_proforma.paquetes= "Familiar";
            cout<<"Cuantas personas van a viajar: ";
            cin>>nueva_proforma.personas;
            nueva_proforma.cantidadPaquetes = nueva_proforma.personas*2000;
            break;
        default:
            cout << "Opci�n inv�lida. Se asignar� un destino por defecto." << endl;
            nueva_proforma.paquetes = "Destino no especificado";
            nueva_proforma.cantidadPaquetes= 0;
    }
    cout<<endl;
    cout << "      Destinos del Viaje    " << endl;
    cout << "1. Salinas $45 \n2. Monta�ita $55  \n3. Gal�pagos $370 \n4. Paris $1200 \n5. Kyoto $1950 \n6. Italia $1100 " << endl;
    cout << "Seleccione el destino del viaje: ";
    cin >> opcion;
    cin.ignore(); 
    switch (opcion) {
        case 1:
            nueva_proforma.destino = "Salinas";
            nueva_proforma.cantidadDestino =45;
            cout<<endl;
            cout << "      Transporte del Viaje    " << endl;
			cout << "1. Autob�s $60 \n2. Carro privado $40" << endl;
    		cout << "Seleccione el destino del viaje: ";
    		cin >> opcion;
   			cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    		switch (opcion) {
        		case 1:
            		nueva_proforma.transporte = "Autob�s";
            		nueva_proforma.cantidadTransporte=60;
            	break;
        		case 2:
            		nueva_proforma.transporte = "Carro privado";
            		nueva_proforma.cantidadTransporte=40;
				break;
			default:
            		cout << "Opci�n inv�lida. Se asignar� un alojamiento por defecto." << endl;
            		nueva_proforma.transporte = "Alojamiento no especificado";
            		nueva_proforma.cantidadTransporte=0;
				break;
			}
			break;
        case 2:
            nueva_proforma.destino = "Monta�ita";
            nueva_proforma.cantidadDestino=55;
            cout<<endl;
            cout << "      Transporte del Viaje    " << endl;
			cout << "1. Autob�s $60 \n2. Carro privado $40" << endl;
    		cout << "Seleccione el destino del viaje: ";
    		cin >> opcion;
   			cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    		switch (opcion) {
    			case 1:
        			nueva_proforma.transporte = "Autob�s";
            		nueva_proforma.cantidadTransporte=60;
            		break;
				case 2:
        			nueva_proforma.transporte = "Carro privado";
            		nueva_proforma.cantidadTransporte=40;
            		break;
				default:
					cout << "Opci�n inv�lida. Se asignar� un alojamiento por defecto." << endl;
            		nueva_proforma.transporte = "Alojamiento no especificado";
            		nueva_proforma.cantidadTransporte=0;
            		break;
            	}
            break;
		case 3:				
            nueva_proforma.destino= "Gal�pagos";
            nueva_proforma.cantidadDestino=370;
            cout<<endl;
           	cout << "      Transporte del Viaje    " << endl;
			cout << "1. Avi�n + Taxi $265 " << endl;
    		cout << "Seleccione el destino del viaje: ";
    		cin >> opcion;
   			cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    		switch (opcion) {
    			case 1:
        			nueva_proforma.transporte= "Avi�n + Taxi";
            		nueva_proforma.cantidadTransporte=265;
            		break;
				default:
					cout << "Opci�n inv�lida. Se asignar� un alojamiento por defecto." << endl;
            		nueva_proforma.transporte= "Alojamiento no especificado";
            		nueva_proforma.cantidadTransporte=0;
            		break;
            	}
            break;
        case 4:
            nueva_proforma.destino= "Paris";
            nueva_proforma.cantidadDestino=1200;
            cout<<endl;
            cout << "      Transporte del Viaje    " << endl;
			cout << "1. Avi�n + Taxi $265 " << endl;
    		cout << "Seleccione el destino del viaje: ";
    		cin >> opcion;
   			cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    		switch (opcion) {
    			case 1:
        			nueva_proforma.transporte= "Avi�n + Taxi";
            		nueva_proforma.cantidadTransporte=265;
            		break;
				default:
					cout << "Opci�n inv�lida. Se asignar� un alojamiento por defecto." << endl;
            		nueva_proforma.transporte= "Alojamiento no especificado";
            		nueva_proforma.cantidadTransporte=0;
            		break;
            	}
            break;
        case 5:
        	nueva_proforma.destino= "Kyoto";
        	nueva_proforma.cantidadDestino=1950;
        	cout<<endl;
        	cout << "      Transporte del Viaje    " << endl;
			cout << "1. Avi�n + Taxi $265 " << endl;
    		cout << "Seleccione el destino del viaje: ";
    		cin >> opcion;
   			cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    		switch (opcion) {
    			case 1:
        			nueva_proforma.transporte= "Avi�n + Taxi";
            		nueva_proforma.cantidadTransporte=265;
            		break;
				default:
					cout << "Opci�n inv�lida. Se asignar� un alojamiento por defecto." << endl;
            		nueva_proforma.transporte= "Alojamiento no especificado";
            		nueva_proforma.cantidadTransporte=0;
            		break;
            	}
            break;
        case 6:
        	nueva_proforma.destino= "Italia";
        	nueva_proforma.cantidadDestino=1100;
        	cout<<endl;
        	cout << "      Transporte del Viaje    " << endl;
			cout << "1. Avi�n + Taxi $265 " << endl;
    		cout << "Seleccione el destino del viaje: ";
    		cin >> opcion;
   			cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    		switch (opcion) {
    			case 1:
        			nueva_proforma.transporte= "Avi�n + Taxi";
            		nueva_proforma.cantidadTransporte=265;
            		break;
				default:
					cout << "Opci�n inv�lida. Se asignar� un alojamiento por defecto." << endl;
            		nueva_proforma.transporte= "Alojamiento no especificado";
            		nueva_proforma.cantidadTransporte=0;
            		break;
            	}
            break;
        default:
            cout << "Opci�n inv�lida. Se asignar� un destino por defecto." << endl;
            nueva_proforma.destino= "Destino no especificado";
            nueva_proforma.cantidadDestino= 0;
    }
    cout<<endl;
    
    Proforma fechaInicio, fechaFinal;
    cout<<"Ingrese la fecha separada por espacios"<<endl;
    cout << "Ingrese la fecha de inicio del viaje (DD MM AAAA): ";
    getline(cin, nueva_proforma.fechaInicio);
    cout<<endl;
    cout<<"Ingrese la fecha separada por espacios"<<endl;
    cout << "Ingrese la fecha final del viaje (DD MM AAAA): ";
 	getline(cin, nueva_proforma.fechaFinal);

    // Calcular la diferencia en d�as
    int diasViaje = diferenciaDias(nueva_proforma.fechaInicio, nueva_proforma.fechaFinal);

    // Determinar el porcentaje de aumento seg�n la duraci�n del viaje
    double porcentajeAumento = 0;
	if (diasViaje > 32) {
    	porcentajeAumento = 0.12; // 12% de aumento para m�s de un mes 
	} else if (diasViaje >= 16 && diasViaje <= 30) {
    	porcentajeAumento = 0.10; // 10% de aumento para m�s de 15 d�as y menos de un mes 
	} else if (diasViaje <= 15) {
    	porcentajeAumento = 0.05; // 5% de aumento para 15 d�as o menos
	}

    
	
    
	cout<<endl;
    cout << "      Alojamiento del Viaje    " << endl;
	cout << "1. Hotel $70 \n2. Resort $100 \n3. Caba�a $90 \n4. Habitaciones $30" << endl;
    cout << "Seleccione el destino del viaje: ";
    cin >> opcion;
    cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    switch (opcion) {
        case 1:
            nueva_proforma.alojamiento= "Hotel";
            nueva_proforma.cantidadAlojamiento=70;
            break;
        case 2:
            nueva_proforma.alojamiento = "Resort";
            nueva_proforma.cantidadAlojamiento=100;
            break;
        case 3:
            nueva_proforma.alojamiento = "Caba�a";
            nueva_proforma.cantidadAlojamiento=90;
            break;
        case 4:
            nueva_proforma.alojamiento= "Habitaciones";
            nueva_proforma.cantidadAlojamiento=30;
			break;
        default:
            cout << "Opci�n inv�lida. Se asignar� un alojamiento por defecto." << endl;
            nueva_proforma.alojamiento= "Alojamiento no especificado";
            nueva_proforma.cantidadAlojamiento=0;
    }
    cout<<endl;
    
    cout << "      Extras del Viaje    " << endl;
	cout << "1. Excursiones \n2. Eventos  \n3. Atenci�n VIP" << endl;
    cout << "Seleccione el destino del viaje: ";
    cin >> opcion;
    cin.ignore(); // Ignorar el salto de l�nea pendiente en el buffer
    switch (opcion) {
        case 1:
            nueva_proforma.extras= "Excursiones";
            nueva_proforma.cantidadExtras=30;
            break;
        case 2:
            nueva_proforma.extras= "Eventos";
            nueva_proforma.cantidadExtras=45;
            break;
        case 3:
            nueva_proforma.extras = "Atencion VIP";
            nueva_proforma.cantidadExtras=60;
            break;
        default:
            cout << "Opci�n inv�lida. Se asignar� un extra por defecto." << endl;
            nueva_proforma.extras= "Extra no especificado";
            nueva_proforma.cantidadExtras=0;
    }
    cout<<endl;
    
    cout << "Escriba el comentario adicional: ";
    getline(cin, nueva_proforma.comentarios);
	cout<<endl;  
	
	nueva_proforma.precio = nueva_proforma.cantidadAlojamiento + nueva_proforma.cantidadPaquetes+ nueva_proforma.cantidadTransporte + nueva_proforma.cantidadDestino + nueva_proforma.cantidadExtras;   		
	nueva_proforma.precioTotal = nueva_proforma.precio + (nueva_proforma.precio * porcentajeAumento);
	cout<<"El precio sin aumento a pagar es de:"<<nueva_proforma.precio<<endl;		
	cout<<"El precio total a pagar es de:"<<nueva_proforma.precioTotal<<endl;		
	
	proformas.push_back(nueva_proforma);
    cout << "\n";
    escribirArchivo1(nueva_proforma);					
}

void crearProforma() {
    Proforma nueva_proforma;
    nueva_proforma.id = generarID();

    cout << "�Qu� tipo de proforma desea crear?" << endl;
    cout << "1. Proforma de Viaje" << endl;
    cout << "2. Proforma de Regalo" << endl;

    int opcion;
    cout << "-----------------------"<<endl;
	cout << "Ingrese su selecci�n: ";
    cin >> opcion;
    string inicio, fin; 
    cout << "------------------------"<<endl;
    cout<<"\n";

    switch(opcion) {
        case 1:
            nueva_proforma.tipo = "Viaje";
            nueva_proforma.paquetes="lalalala";
            registrosViaje1();
            
            break;
        case 2:
           string nuevoProducto;
        	int cantidad;
        	int stock;
            nueva_proforma.tipo = "Regalo";
            cout<<"Bienvenido al apartado de regalo"<<endl;
            cout<<"Disponemos de las siguientes categorias de regalos: "<<endl;
            cout<<"Atletismo "<<"(ID "<<atletismo<<")"<<endl;
            cout<<"Natacion "<<"(ID "<<natacion<<")"<<endl;
            cout<<"Camping "<<"(ID "<<camping<<")"<<endl;
            cout<<"Fisico Culturismo"<<"(ID "<<fisico<<")"<<endl;
            cout<<"Ingrese la opcion que desee: (Ingrese 0 para salir)";
            string deseo;
            cin>>deseo;
            if (deseo==atletismo){
            	int salir;
            	int i=0;
            	int costo;
            	cout<<"***ATLETISMO***"<<endl;
            	cout<<"Disponemos de: "<<endl;
            	cout<<"Estos productos tienen un 15% de descuento por esta temporada"<<endl;
            	cout<<"1) Zapatos $60"<<endl<<"2) Termos $15"<<endl<<"3) Cuerdas $12"<<endl<<"4) Tobilleras $19.99"<<endl;
            	cout<<"Seleccione su regalo (Digite el numero): ";
            	int regalo;
            	cin>>regalo;
				
            	if (regalo==1){
            		 i=0;
            			nombreProducto="Zapatos";
            			nueva_proforma.producto[i]="Zapatos";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=60-(60*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
					
            	}
            	
				if (regalo==2){
            		 i=0;
            			nombreProducto="Botellas";
            			nueva_proforma.producto[i]="Botellas";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=15-(15*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
            		
				if (regalo==3){
            		 i=0;
            			nombreProducto="Cuerdas";
            			nueva_proforma.producto[i]="Cuerdas";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=12-(12*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
            	
            	if (regalo==4){
            		 i=0;
            			nombreProducto="Tobilleras";
            			nueva_proforma.producto[i]="Tobilleras";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=20-(20*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
}
		     if (deseo==camping){
            	int salir;
            	int i=0;
            	int costo;
            	cout<<"***Camping***"<<endl;
            	cout<<"Disponemos de: "<<endl;
            	cout<<"Estos productos tienen un 15% de descuento por esta temporada"<<endl;
            	cout<<"1) Carpas $94.99"<<endl<<"2) Sacos de dormir $24"<<endl<<"3) Kit de supervivencia $29.50"<<endl<<"4) Linternas $4.99"<<endl;
            	cout<<"Seleccione su regalo (Digite el numero): ";
            	int regalo;
            	cin>>regalo;
				
            	if (regalo==1){
            		 i=0;
            			nombreProducto="Carpas";
            			nueva_proforma.producto[i]="Carpas";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=94.99-(94.99*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
					
            	}
            	
				if (regalo==2){
            		 i=0;
            			nombreProducto="Sacos";
            			nueva_proforma.producto[i]="Sacos de dormir";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=27-(27*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
            		
				if (regalo==3){
            		 i=0;
            			nombreProducto="Kit";
            			nueva_proforma.producto[i]="kit";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=29.50-(29.50*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
            	
            	if (regalo==4){
            		 i=0;
            			nombreProducto="Linternas";
            			nueva_proforma.producto[i]="Linternas";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=4.99-(4.99*0.15);
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
}
				if (deseo==natacion){
            		int salir;
            		int i=0;
            		int costo;
            		cout<<"***NATACION***"<<endl;
            		cout<<"Disponemos de: "<<endl;
            		cout<<"1) Gafas $9.65"<<endl<<"2) Traje de ba�o completos $25.90"<<endl<<"3) Toallas $5.70"<<endl<<"4) �PATO DELUXE! $99.99"<<endl;
            		cout<<"Seleccione su regalo (Digite el numero): ";
            		int regalo;
            		cin>>regalo;
				
            		if (regalo==1){
            		 i=0;
            			nombreProducto="Gafas";
            			nueva_proforma.producto[i]="Gafas";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=9.65;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
					
            		}
            	
					if (regalo==2){
            		 i=0;
            			nombreProducto="Trajes";
            			nueva_proforma.producto[i]="Trajes";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=25.90;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            		}
            		
					if (regalo==3){
            		 i=0;
            			nombreProducto="Toallas";
            			nueva_proforma.producto[i]="Toallas";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=5.70;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            		}		
            	
            		if (regalo==4){
            		 i=0;
            			nombreProducto="PATODELUXE";
            			nueva_proforma.producto[i]="PATO DELUXE";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=99.99;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
}
				if (deseo==fisico){
            		int salir;
            		int i=0;
            		int costo;
            		cout<<"***Fisico Culturismo***"<<endl;
            		cout<<"Disponemos de: "<<endl;
            		cout<<"1) Suplementos $81"<<endl<<"2) Mancuernas $24"<<endl<<"3) Subscripcion a nuestro GYM por 3 meses $45"<<endl<<"4) Kit de ejercicio en casa $375"<<endl;
            		cout<<"Seleccione su regalo (Digite el numero): ";
            		int regalo;
            		cin>>regalo;
				
            		if (regalo==1){
            		 i=0;
            			nombreProducto="Suplementos";
            			nueva_proforma.producto[i]="Suplementos";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=81;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
					
            		}
            	
					if (regalo==2){
            		 i=0;
            			nombreProducto="Mancuernas";
            			nueva_proforma.producto[i]="Mancuernas";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=24;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            		}
            		
					if (regalo==3){
            		 i=0;
            			nombreProducto="Subscripcion";
            			nueva_proforma.producto[i]="Subscripcion";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=45;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            		}		
            	
            		if (regalo==4){
            		 i=0;
            			nombreProducto="Kitencasa";
            			nueva_proforma.producto[i]="Kit de ejercicio en casa";
            			cout << "Ingrese la cantidad que desea comprar: ";
    					cin >> cantidad;
    					nueva_proforma.cantidad[i]=cantidad;
						nueva_proforma.costo=375;
						nueva_proforma.resultado=nueva_proforma.costo*cantidad;
    					actualizarStock(nombreProducto, cantidad,stock);
						
            	}
}
proformas.push_back(nueva_proforma);
    cout << "\n";
    escribirArchivo2(nueva_proforma);
}
		
    

    
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
    cout << "Esta seguro de querer eliminar est� proforma"<<endl;
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
        cout << "No se encontr� ninguna proforma con el ID proporcionado." << endl;
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
        cout << "1. Crear una nueva proforma" << endl << "2. Enlistar proformas creadas (solo ID)" << endl << "3. Abrir una proforma por ID" << endl << "4. Eliminar una proforma por ID" << endl  << "5. Finalizar Programa" << endl;
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
                cout << "Selecci�n no v�lida." << endl;
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
            } else if (linea.find("Direcci�n: ") != string::npos) {
                cliente.direccion = linea.substr(11);
            } else if (linea.find("C�dula: ") != string::npos) {
                cliente.cedula = stringToInt(linea.substr(8));
            } else if (linea.find("Correo electr�nico: ") != string::npos) {
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
    cout << "Ingrese su n�mero de c�dula: ";
    
    bool cedulaValida = false;
    while (!cedulaValida) {
        cin >> nuevoCliente.cedula;

        // Verificaci�n de que la c�dula tenga exactamente 10 d�gitos
        if (cin.fail() || nuevoCliente.cedula < 0 || nuevoCliente.cedula > 9999999999 || intToString(nuevoCliente.cedula).length() != 10 ) {
            cout << "C�dula no v�lida. Debe contener exactamente 10 d�gitos."<<endl<< "Inserte nuevamente: ";
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
        cout << "La c�dula ya est� registrada." << endl;
        cout << "Acceda como ususario frecuente\n" << endl;
        return;
    }

    cout << "Ingrese su nombre: ";
    getline(cin >> ws, nuevoCliente.nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, nuevoCliente.apellido);
    cout << "Ingrese su direcci�n: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese su correo electr�nico: ";
    getline(cin, nuevoCliente.correo);

    ofstream archivo("CLIENTES.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nuevoCliente.nombre << endl;
        archivo << "Apellido: " << nuevoCliente.apellido << endl;
        archivo << "Direcci�n: " << nuevoCliente.direccion << endl;
        archivo << "C�dula: " << nuevoCliente.cedula << endl;
        archivo << "Correo electr�nico: " << nuevoCliente.correo << endl;
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
            archivo << "Direcci�n: " << clientes[i].direccion << endl;
            archivo << "C�dula: " << clientes[i].cedula << endl;
            archivo << "Correo electr�nico: " << clientes[i].correo << endl;
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
    cout << "Ingrese la c�dula del usuario que desea actualizar: ";
    cin >> cedula;

    bool encontrado = false;
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].cedula == cedula) {
            Cliente& cliente = clientes[i];
            int opcion;
            do {
                cout << "=== Actualizar Informaci�n del Cliente ===" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Apellido" << endl;
                cout << "3. Direcci�n" << endl;
                cout << "4. Correo electr�nico" << endl;
                cout << "5. Volver al men� anterior" << endl;
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
                        cout << "Ingrese la nueva direcci�n: ";
                        getline(cin, cliente.direccion);
                        break;
                    case 4:
                        cout << "Ingrese el nuevo correo electr�nico: ";
                        getline(cin, cliente.correo);
                        break;
                    case 5:
                        cout << "Ingresar al menu de opciones." << endl;
                        break;
                    default:
                        cout << "Selecci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
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
        cout << "Informaci�n del cliente actualizada correctamente." << endl;
    }
}

void accederUsuario() {
    int intentos = 2;
    int cedula;
    bool acceso = false;

    while (intentos > 0) {
        cout << "Ingrese su n�mero de c�dula: ";
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
            cout << "N�mero de c�dula incorrecto. Intentos restantes: " << intentos << endl;
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
        cout << "=== Men� Inicial ===" << endl;
        cout << "1. Crear un nuevo usuario\n2. Usuario Frecuente\n3. Actualizar informaci�n de usuario\n4. Finalizar programa" << endl;
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
                cout << "Saliendo del programa. �Hasta luego!" << endl;
                exit(0);
                break;
            default:
                cout << "Selecci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
                break;
        }
    } while (opcion != 4);
}

int main() {
	string nombre="stock.txt";
	if (creacionStock(nombre)){
		cout<<" ";
		
	}else{
		cout<<" ";
		
	}
	setlocale(LC_ALL, "");
    srand(time(NULL));
    menuInicial(); 
    
    return 0;
}




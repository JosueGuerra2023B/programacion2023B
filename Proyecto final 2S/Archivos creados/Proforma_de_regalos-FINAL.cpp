#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <limits>

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

int aux1;
string atletismo="A";
string natacion="N";
string camping="C";
string fisico="F";

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

    cout << "Compra realizada con éxito. Stock actualizado." << endl;
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


struct Cliente {
    string nombre;
    string apellido;
    string direccion;
    int cedula; // Cambiado a tipo entero para almacenar la cédula como número
    string correo;
};

void registrarCliente() {
    Cliente nuevoCliente;
    cout << "=== Registro de Cliente ===" << endl;
    cout << "Ingrese su nombre: ";
    getline(cin >> ws, nuevoCliente.nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, nuevoCliente.apellido);
    cout << "Ingrese su direccion: ";
    getline(cin, nuevoCliente.direccion);
    cout << "Ingrese su correo electronico: ";
    getline(cin, nuevoCliente.correo);

    bool cedulaValida = false;
    while (!cedulaValida) {
        cout << "Ingrese su numero de cedula: ";
        cin >> nuevoCliente.cedula;

        // Verificación de que la cédula tenga exactamente 10 dígitos
        if (cin.fail() || nuevoCliente.cedula < 0 || nuevoCliente.cedula > 9999999999) {
            cout << "Cédula no válida. Debe contener exactamente 10 dígitos. Intente nuevamente." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cedulaValida = true;
        }
    }

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
}

void escribirArchivo(Proforma& proforma) {
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

void crearProforma() {
    Proforma nueva_proforma;
    nueva_proforma.id = generarID();
    string nuevoProducto;
    int cantidad;

    cout << "¿Qué tipo de proforma desea crear?" << endl;
    cout << "1. Proforma de Viaje" << endl;
    cout << "2. Proforma de Regalo" << endl;
	
    int opcion;
    cout << "Ingrese su selección: ";
    cin >> opcion;
    

    switch(opcion) {
        case 1:
            nueva_proforma.tipo = "Viaje";
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
            		cout<<"1) Gafas $9.65"<<endl<<"2) Traje de baño completos $25.90"<<endl<<"3) Toallas $5.70"<<endl<<"4) ¡PATO DELUXE! $99.99"<<endl;
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

    for (int i = 0; i < proformas.size(); i++) {
        cout << "Proforma: " << proformas[i].id << " - Tipo: " << proformas[i].tipo << endl;
    }
    cout << "\n";
}

void eliminarProforma() {
    if (proformas.empty()) {
        cout << "No hay proformas para eliminar." << endl;
        cout << "\n";
        return;
    }

    int id;
    cout << "Ingrese el ID de la proforma que desea eliminar: ";
    cin >> id;

    for (int i = 0; i < proformas.size(); ++i) {
        if (proformas[i].id == id) {
            proformas.erase(proformas.begin() + i);
            if (remove(("proforma_" + intToString(id) + ".txt").c_str()) != 0) {
                cout << "Error al eliminar el archivo de la proforma." << endl;
            } else {
                cout << "Proforma con ID " << id << " eliminada correctamente." << endl;
                cout << "\n";
            }
            return;
        }
    }

    cout << "No se encontró ninguna proforma con el ID proporcionado." << endl;
}

void abrirProforma() {
    int id;
    cout << "Ingrese el ID de la proforma que desea abrir: ";
    cin >> id;

    string comando = "notepad proforma_" + intToString(id) + ".txt";
    system(comando.c_str());
}

int main() {
    srand(time(NULL));
    string nombre="stock.txt";
	if (creacionStock(nombre)){
		cout<<" ";
		
	}else{
		cout<<" ";
		
	}


    int seleccion;
    do {
        cout << "--- Viajes BOROJO ---" << endl;
        cout << " Le da la bienvenida";
        cout << "\n";
        cout << "1. Crear una nueva proforma" << endl << "2. Mostrar proformas creadas (solo ID)" << endl << "3. Abrir una proforma por ID" << endl << "4. Eliminar una proforma por ID" << endl << "5. Salir" << endl;
        cout << "Ingresa tu seleccion: ";
        cin >> seleccion;
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
                cout << "Selección no valida." << endl;
                break;
        }

    } while (seleccion != 5);

    return 0;
}

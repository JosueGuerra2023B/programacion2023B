#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
const char *nombreArchivo="personas.txt";
const int MAXPERSONAS=100;
struct Persona{
	string nombre;
	int edad;
};
void mostrarPersona(const Persona personas[], int cantidad){
	cout<<"LISTA DE PERSONAS:\n";
	for (int i=0; i<cantidad; i++){
		cout<<"Nombre: "<<personas[i].nombre;
		cout<<"Edad: "<<personas[i].edad;
	}	
}

void crearPersona(Persona personas[], int& cantidad){
	if (cantidad<MAXPERSONAS){
		
		Persona nuevaPersona;
		cout<<"Ingrese el nombre de la nueva persona: ";
		getline(cin, nuevaPersona.nombre);
		cout<<"Ingrese la edad de la nueva persona: ";
		cin>>nuevaPersona.edad;
		cin.ignore();
		personas[cantidad]=nuevaPersona;
		cantidad++;
		cout<<"La persona se ha creado CORRECTAMENTE"<<endl;
	}else{
		cout<<"Limite alcanzado, !NO PUEDES CREAR MÁS PERSONAS!";
	}
}

void actualizarPerona(Persona personas[],int cantidad){
	string nombreBuscar;
	cout<<"Ingrese el nombre de la persona a actualizar: ";
	getline(cin, nombreBuscar);
	for (int i=0; i<cantidad; i++){
		if (nombreBuscar == personas[i].nombre){
			cout<<"Ingrese la nueva de la persona " <<personas[i].nombre<<"  : ";
			cin>>personas[i].edad;
			cin.ignore();
			cout<<"La edad se actualizo de manera correcta";
		}else{
			cout<<" Esa persona no existe ";
		}
	}
}

void EliminarPersona(Persona personas[], int& cantidad){
	string nombreEliminar;
	cout<<"Ingrese el nombre de la persona a eliminar: ";
	getline(cin, nombreEliminar);
	for(int i=0; i<cantidad; i++){
		if(nombreEliminar == personas[i].nombre){
			for(int j=i; j<cantidad-1; j++){
				personas[j]=personas[j+1];
			}
			cantidad--;
			cout<<"La persona se ha eliminado de manera correcta";
		}else{
			cout<<"Esa persona no existe";
		}
	}	
}

//uso de archivos en mi programa
void guardarPersonaArchivo (const Persona personas[], int cantidad){
	ofstream archivo(nombreArchivo);
	if(archivo.is_open()){
		for (int i = 0; i<cantidad; i++){
			archivo<<personas[i].nombre<<", "<<personas[i].edad<<endl;
		}
		archivo.close();
	}else{
		cerr<<"Error al abrir el archivo";
	}
}

void cargarPersonasArchivo(Persona personas[], int& cantidad){
	ifstream archivo(nombreArchivo);
	if (archivo.is_open()){
		cantidad=0;
		string nombre;
		int edad;
		while(getline(archivo, nombre, ',')){
			cin>>edad;
			personas[cantidad].nombre =nombre;
			personas[cantidad].edad = edad;
			cantidad++;
		}
	}else{
		cerr<<"Error al leer el archivo";
	}
}

int main (){
	Persona personas[MAXPERSONAS];
	int cantidadPersonas=0;
	
	//Dibujar el menu 
	int opcion;
	do{
		cout<<"  --MENU PRINCIPAL--   "<<endl;
		cout<<"1. Visualizar Personas"<<endl;
		cout<<"2. Crear Persona"<<endl;
		cout<<"3-Actualizar persona"<<endl;
		cout<<"4. Eliminar Persona"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Ingrese la opción que desea realizar: "<<endl;
		cin>>opcion;
		cin.ignore();
		cout<<endl;
		switch(opcion){
			case 1:
				mostrarPersona(personas, cantidadPersonas);
				break;
			case 2:
				crearPersona(personas, cantidadPersonas);
				break;
			case 3:
				actualizarPerona(personas, cantidadPersonas);
				break;
			case 4:
				EliminarPersona(personas, cantidadPersonas);
				break;
			case 5:
				cout<<"ADIOS...!";
				break;
			default:
				cout<<"Ingrese una opción valida";
		}
		
	}while(opcion !=5);
	
	guardarPersonaArchivo(personas, cantidadPersonas);
return 0;
}

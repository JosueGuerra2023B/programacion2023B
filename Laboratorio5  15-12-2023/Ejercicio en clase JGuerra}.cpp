#include <iostream>
using namespace std;
int main()
{
    
    
    //if notas
    double not1, not2, not3;
    double tot;
    cout<< "Ingrese su nota de Algoritmos sobre 20: ";
    cin>> not1;
    cout<< "Ingrese su nota de Algoritmos sobre 20: ";
    cin>> not1;
    cout<< "Ingrese su nota de Algoritmos sobre 20: ";
    cin>> not1;
    
    tot = (not1+not2+not3)/3;
    
    if (not1 + not2 + not3 > 40 ){
    	cout<< " La nota m�xima es solo sobre 40";
    	}else if (tot >= 28){
    		cout<< "Usted aprobo con una nota de: "<<tot<<endl;
    	}else{ if (tot < 27.99){
    		cout<< "Usted reprobo con una nota de: "<<tot<<endl;
    	}	
    	}
    	
    	
    	//switch-case
    	//vamos a realizar el if para
    	//ver la diferencia
    	//dado un mes del a�o decir cuantos d�as tiene
    	
    	/*
		cout<< "Dime un mes.. con n�mero (1, 2, 3....12)";
    	int mes;
    	
    	//*
    	cin>> mes;
    	/*
    	if (mes > 0 && mes < 13){
		if (mes ==1 || mes ==3 || mes ==5 || mes ==7 || mes ==8 || mes ==10 || mes ==12){
			cout<< "El mes tiene 31 d�as";
			}else if (mes ==2){
    			cout<< " El mes tiene 28 o 29 d�as";
    		}else if (mes ==4 || mes ==6 || mes ==9 || mes ==10){
    		cout<< "El mes tiene 30 d�as";
    		}else
    		cout<<"Imposible";
    	}*/
    	
    	/*
    	switch(mes){
    		case 1:
    		case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				cout<< "El mes tiene 31 d�as";
				break;
				case 4:
				case 6:
				case 9:
				case 11:
				cout<< "El mes tiene 30 d�as";
				break;
				case 2:
				cout<<"El mes tiene 28 o 29 d�as";
				break;
				default:
				 	cout<<"Opci�n no valida";
				*/		
		/*
		//Menu de calculadora
		//Uso de Switch
		 int op;
		 cout<< "Ingrese la operaci�n que desea hacer";
		 cout<< "1. Suma,  2. Resta,  3. Multiplicaci�n,  4. Divisi�n, 5. Salir";
		 cin>>op;
		 
		 cout<< "Ingrese los valores a operar: ";
		 double val1, val2;
		 cout<< "1er valor: ";
		 cin>> val1;
		 cout<< "2do valor: ";
		 cin>> val2;
		 
		 switch(op){
		 	case 1:
		 		float suma;
		 		suma = val1 +val2;
		 		cout<< "El resultado de la suma es: "<<suma<<endl;
		 		break;
		 	case 2:
		 		float resta;
		 		resta = val1 - val2;
		 		cout<< "El resultado de la resta es: "<<resta<<endl;
		 		break;
		 	case 3:
		 		float multi;
		 		multi = val1 * val2;
		 		cout<< "El resultado de la multiplicaci�n es: "<<multi<<endl;
		 		break;
		 	case 4:
		 		float div;
		 		if (val2 == 0){
		 			cout<< "No se puede hacer la divisi�n para 0";	
		 		}else{
				 float div;
				 div = val1 / val2;
				 cout<< "El resultado de la divisi�n es: "<<div<<endl;
		 		}
				 break;
				 default:
				 	cout<<"Opci�n no valida";	
		 }*/
		 
		 /*
		 //Determinar si es bisiesto o no 
		 
		 int a_o;
		 cout<< "Ingrese un a�o: ";
		 cin>> a_o;
		 
		 if (a_o % 4 ==0 ){
		 	cout<< "El a�o"<<a_o<< " es Bisiesto"<<endl; 
		 }else{
		 	cout<< "El a�o"<<a_o<< " normal"<<endl;
		 }
		 */
    return 0;

}

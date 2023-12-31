# include <iostream>
using namespace std;

int main()
{

    // do-while
    //estructura
    //do{
        //instrucciones
        //secuencia de codigo
    //}while (epresion logica);
    
    cout<<" Impresión de números del 1 al 10"<<endl;
    cout<<"forma ascendete"<<endl;
    int i;
    i = 1;

    do {
        cout << i << endl;
        i++;
    }while(i <= 10);
    cout<<"\n";
   
   cout<<"Forma descendete"<<endl;
    int j;
    j = 10;

    do {
        cout << j << endl;
        j--;
    }while(j >= 1);
    
 return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;
int a; 
/*void fun(int b){
	//a=3;
	b=a*b;
}*/
int fun(int b){
	a=3;
	b=a*b;
	return b;
}

int main (){
	a=2;
	cout<<fun(a)<<endl;
	cout<<a<<endl;

	
return 0;
}

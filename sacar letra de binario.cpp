#include <iostream>
#include <cmath>
using namespace std ;
int valorcaracter (string linea){
	int valor=0;
	for (int i = 0 , base = 128; linea[i] != '\0';i++,base/= 2){
		if(linea[i]=='1'){
			valor+= base;
			
		}
	}
	return valor-1;
}
int lineaEnMiles(string linea){
	return pow(10,(linea.length()/8)-1);
}

int valorlinea(string line){
	string linea;
	for(int i = 0 , bloque= 1; lin[i])
}

int main(){
	cout<< lineaEnMiles("00110001001100100011001100110100");
}



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
	return valor-48;
}
int lineaEnMiles(string linea){
	return pow(10,(linea.length()/8)-1);
}

int valorlinea(string line){
	int valorline=0;
	string linea;
	int base =lineaEnMiles(line);
	for(int i = 0 , bloque= 1; line[i]!= '\0' ; i++){
		linea+= line[i];
		if(bloque== 8){
			valorline+= valorcaracter(linea)*base;
			linea.clear();
			bloque=1;
			base=base/10;
			
			
		}else{
			bloque++;
		}
	}return valorline;
}

int main(){
	cout<< valorlinea("001100100011000100110001001100010011000100110001001100010011001000110010");
}

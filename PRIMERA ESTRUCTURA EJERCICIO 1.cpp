#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
using namespace std;
string charToBinary(char c) {
    return bitset<8>(c).to_string();
}
string codibloq(string linea,int metodo){
	if (metodo== 1) {// Regla 1 M1
        for(int i = 0 ;linea[i] != '\0'; i++){
        	if(linea[i]== '0'){
        		linea[i]='1';
			}else if (linea[i]== '1'){
        		linea[i]='0';
		}
    } // regla 2 M1
	}else if (metodo== 2) {
        for (int i = 0; linea[i] != '\0'; i++) {
			if (i % 2 == 1) {
            	if(linea[i]== '0'){
        		linea[i]='1';
				}else if (linea[i]== '1'){
        		linea[i]='0';
				}
        	}
   		}
    }else {// Regla 3 M1
    	for (int i = 0; linea[i] != '\0'; i++) {
			if (i % 3 == 1) {
            	if(linea[i]== '0'){
        		linea[i]='1';
				}else if (linea[i]== '1'){
        		linea[i]='0'; 
				}
        	}
   		}
    }return linea;	
}


int main(){
	int x,contc=0,contu=0;
	string linea;// getline
	string linea2;// caracter a caracter de la linea getlines
	ifstream archivo;// SINTAXIS PARA DECLARA VARIABLE PARA ARCHIVOS
	archivo.open("data.txt");//ABRIMOS EL ARCHIVO
	cout<<"Ingres La Semilla Mi Pez ";
	cin>> x;
	
	while(archivo.good()){
		getline(archivo,linea);//LEEMOS EL ARCHIVO POR LINEA
		for(int i = 0, bloque = 1; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CCARACTYER A CARACTER
			cout<<linea[i];
			if(linea[i]==48){
				contc++;
			}else{
				contu++;
			}
			if(bloque==x){
				cout<<"\t"<<contc<<"  "<<contu<<"\n";
				bloque=1;
				contc=0;
				contu=0;
			}else{
				bloque++;
			}
		}cout<<'\t'<<contc<<"  "<<contu<<'\n';contc=0;contu=0;
		
	}
	archivo.close();
  return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
using namespace std;
string charToBinary(char c) {
    return bitset<8>(c).to_string();
}
int main(){
	int x;
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
			if(bloque==x){
				cout<<"\n";
				bloque=1;
			}else{
				bloque++;
			}
		}cout<<"\n";
	}
	archivo.close();

  

  return 0;
}
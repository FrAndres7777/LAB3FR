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
	string linea;
	string linea2;// GUARDAMOS TODO EN LINEA 2 PARA LUEGO SOBREESCRIBIR
	ifstream archivo;// SINTAXIS PARA DECLARA VARIABLE PARA ARCHIVOS
	archivo.open("data.txt");//ABRIMOS EL ARCHIVO
	while(archivo.good()){
		getline(archivo,linea);//LEEMOS EL ARCHIVO POR LINEA
		for(int i = 0; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CCARACTYER A CARACTER
			linea2 = linea2+ charToBinary(linea[i]);
		}linea2= linea2 + '\n';
	}
	archivo.close();

  ofstream archivo_salida("data.txt"); // abrir el archivo en modo de escritura
  archivo_salida << linea2; // escribir la variable linea2 en el archivo
  archivo_salida.close(); // cerrar el archivo

  return 0;
}
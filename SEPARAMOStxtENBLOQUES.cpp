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
	cout<<archivo;
	archivo.close();

  return 0;
}
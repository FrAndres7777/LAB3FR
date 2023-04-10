#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

using namespace std;
// funcion regla
int Regla(int ceross, int unoss) {
    if (ceross == unoss) {
        return 1;
    } else if (ceross > unoss) {
        return 2;
    } else {
        return 3;
    }
}

// Función para convertir un caracter a su representación binaria
string charToBinary(char c) {
    return bitset<8>(c).to_string();
}


// Función para convertir una cadena de caracteres a su representación binaria
string stringToBinary(const string& str) {
    string binaryStr;
    for (char c : str) {
        binaryStr += charToBinary(c);
    }
    return binaryStr;
}

// Función para leer un archivo línea por línea y convertirlas a binario
void convertirArchivoABinario(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo) {
        string linea;
        string lineaBinaria;
        while (getline(archivo, linea)) {
            lineaBinaria += stringToBinary(linea);
            lineaBinaria+= '\n';
        }
        archivo.close();
        ofstream archivo(nombreArchivo);
        archivo<<lineaBinaria;
        archivo.close();
        
    } else {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
    }
}




// 
void codix(string name,int semi){
	char str[256];
    ifstream fin;
    fin.open(name);
    ofstream fout;
    fout.open("archiv.txt");
    if (fin.is_open()) cout<<"Abierto"<<endl;
    else cout<<"No abierto"<<endl;
    //Para LEEER POR LINEA
    cout<<"Por Linea: "<<endl;
    string hi;
    int ceros=0,regla=1;
	int cont=0,unos=0;
	int bloque=1;
	char list[semi];
    while(fin.good()){
        char temp= fin.get();
        list[cont]= temp;
        cont++;
        if(temp=='0'){
        	ceros++;
		}else if (temp=='1'){
			unos++;
		}
		if(bloque==4){
			bloque=1;cont=0;
			for(int i = semi;i >0; i=i){
				i--;
				fout<<list[i];
			}
			for(int ii =0;ii <semi; ii++){
				list[ii]='\0';
			}
		}else{
			bloque++;
		}	
		    
    }
    cout<<ceros<<" "<<unos;
	fin.close();
	fout.close();
}



void codix1(string name,int semi){
	char str[256];
    ifstream fin;
    fin.open(name);
    ofstream fout;
    fout.open("archiv.txt");
    if (fin.is_open()) cout<<"Abierto"<<endl;
    else cout<<"No abierto"<<endl;
    //Para LEEER POR LINEA
    cout<<"Por Linea: "<<endl;
    string hi;
    int ceros=0,regla=1;
	int cont=0,unos=0;
	int bloque=1,i2 = 0,i3=1;
	char list[semi];
    while(fin.good()){
    	bloque++;
        char temp= fin.get();
        list[bloque-1]= temp;
        cont++;
        if(temp=='0'){
        	ceros++;
		}else if (temp=='1'){
			unos++;
		}
		//
		if(regla==1){
			if(temp='1'){
				fout<<0;
			}else{
				fout<<1;
			}
		}else if(regla ==2){
			if (i2 % 2 == 1 or i2 ==1 ) {
		           	if(temp== '0'){
		        		fout<<1;
					}else if (temp== '1'){
		        		fout<<0;
						}
		        	}else{
		        		fout<<temp;
					}
   		
			}else{
				if(i3 %3==0){
	            	if(temp== '0'){
	        			fout<<1;
					}else if (temp== '1'){
	        			fout<<0; 
					}
   				}else{
   					fout<<temp;
				   }
			}
		
		
		
		//
		if(bloque==semi){
			bloque=0;
			regla=Regla(ceros,unos);
			ceros=0;unos=0;
			
		
		}i2++,i3++;
		    
    }
	fin.close();
	fout.close();
}
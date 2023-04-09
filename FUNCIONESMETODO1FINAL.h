#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
using namespace std;

// string a BINARIO
string charToBinary(char c) {
    return bitset<8>(c).to_string();
}
// funcion recorrer string  y pasar string a binario
string  lineabin(string linea){
	string linea2;
	for(int i = 0; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CCARACTYER A CARACTER
			linea2 = linea2+ charToBinary(linea[i]);
		}return linea2;
}

// CODIFICACION Metodo 1 Por Bloques(se ingresa el string (linea de bloque no importa el tamaño) y la regla 1,2,3)
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
    	for (int i = 2; linea[i] != '\0'; i+=3) {
            	if(linea[i]== '0'){
        		linea[i]='1';
				}else if (linea[i]== '1'){
        		linea[i]='0'; 
				}
   		}
    }return linea;	
}

// FUNCION PARA ELEGIR REGLA
int Regla(int ceross, int unoss) {
    if (ceross == unoss) {
        return 1;
    } else if (ceross > unoss) {
        return 2;
    } else {
        return 3;
    }
}

// FUNCION PARA PASAR ARCHIVO A BINARIO
void archivo_TO_binario(string nombre_archivo){//recibe nombre del archivo para pasar a binario se guardara en el mismo
	string linea;
	string linea2;// GUARDAMOS TODO EN LINEA 2 PARA LUEGO SOBREESCRIBIR
	ifstream archivo;// SINTAXIS PARA DECLARA VARIABLE PARA ARCHIVOS
	archivo.open(nombre_archivo);//ABRIMOS EL ARCHIVO
	if (!archivo.is_open()) {
    	cout<< "Error al abrir el archivo\n";
    	return ;
	}
	while(archivo.good()){
		getline(archivo,linea);//LEEMOS EL ARCHIVO POR LINEA
		for(int i = 0; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CCARACTYER A CARACTER
			linea2 = linea2+ charToBinary(linea[i]);
		}linea2= linea2 + '\n';
	}
	archivo.close();

  ofstream archivo_salida(nombre_archivo); // abrir el archivo en modo de escritura
  archivo_salida << linea2; // escribir la variable linea2 en el archivo
  archivo_salida.close(); // cerrar el archivo
}

//FUNCION ABRIR ARCHIVO  QUE YA ESTA EN BINARIO PARA CODIFICARLO
void codificarArchivo(string archivo_entrada,string archivo_sal,int semi){// se puede ingresar el mismo archivo para entrada y salida
	int x=semi,contc=0,contu=0,regla=1;// x es la semilla
	string linea;// getline
	string linea2,lineaprincipal;// caracter a caracter de la linea getlines
	ifstream archivo;// SINTAXIS PARA DECLARA VARIABLE PARA ARCHIVOS
	archivo.open(archivo_entrada);//ABRIMOS EL ARCHIVO
	if (!archivo.is_open()) {
    	cout<< "Error al abrir el archivo\n";
    	return ;
	}
 
	while(archivo.good()){
		getline(archivo,linea);//LEEMOS EL ARCHIVO POR LINEA
		for(int i = 0, bloque = 1; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CCARACTYER A CARACTER
			linea2 += linea[i];
			if(linea[i]==48){
				contc++;
			}else{
				contu++;
			}
			if(bloque==x){
				linea2 =codibloq(linea2,regla);
				lineaprincipal = lineaprincipal + linea2;
				linea2.clear();
				regla =Regla(contc,contu);
				bloque=1;
				contc=0;
				contu=0;
			}else{
				bloque++;
			}
		}
		contc=0;contu=0;
		linea2 =codibloq(linea2,regla);
		lineaprincipal = lineaprincipal + linea2 + '\n';
		linea2.clear();
		
	}
	archivo.close();
	ofstream archivo_salida(archivo_sal); // abrir el archivo en modo de escritura
	archivo_salida << lineaprincipal;
	archivo_salida.close(); // cerrar el archivo
}

// funcion desencriptar linea
string desencriptar_linea(string linea, int semilla){
	int contcd=0,contud=0,regla=1;
	string linea2,lineaprincipal;
	for(int i = 0, bloque = 1; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CCARACTYER A CARACTER
		linea2 += linea[i];
		if(bloque==semilla){
			linea2 =codibloq(linea2,regla);
			for(int j = 0 ; linea2[j]!= '\0'; j++){
				if(linea2[j]=='0'){
					contcd++;
				}else{
					contud++;
				}	
			}
			lineaprincipal = lineaprincipal + linea2;
			linea2.clear();
			regla =Regla(contcd,contud);
			bloque=1;
			contcd=0;
			contud=0;
		}else{
			bloque++;
		}
		
	}
	return lineaprincipal;
}
//	FUNCION DESENCRIPTAR ARCHIVO
void desencriptarArchivo(string archivo_entrada,string archivo_sal,int semi){// se puede ingresar el mismo archivo para entrada y salida
	int x= semi,contcd=0,contud=0,regla=1;// x es la semilla
	string linea;// getline
	string linea2,lineaprincipal;// caracter a caracter de la linea getlines
	ifstream archivo;// SINTAXIS PARA DECLARA VARIABLE PARA ARCHIVOS
	archivo.open(archivo_entrada);//ABRIMOS EL ARCHIVO
	if (!archivo.is_open()) {
    	cout<< "Error al abrir el archivo\n";
    	return ;
	}
	while(archivo.good()){
		getline(archivo,linea);//LEEMOS EL ARCHIVO POR LINEA
		for(int i = 0, bloque = 1; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CCARACTYER A CARACTER
			linea2 += linea[i];
			if(bloque==x){
				linea2 =codibloq(linea2,regla);
				for(int j = 0 ; linea2[j]!= '\0'; j++){
					if(linea2[j]=='0'){
						contcd++;
					}else{
						contud++;
					}	
				}
			lineaprincipal = lineaprincipal+linea2;
			linea2.clear();
			regla =Regla(contcd,contud);
			bloque=1;
			contcd=0;
			contud=0;
		}else{
			bloque++;
		}
	}
		contcd=0;contud=0;
		linea2 =codibloq(linea2,regla);
		lineaprincipal = lineaprincipal+linea2;
		linea2.clear();
		
	}
	archivo.close();
	ofstream archivo_salida(archivo_sal); // abrir el archivo en modo de escritura
	archivo_salida<<lineaprincipal;
	archivo_salida.close(); // cerrar el archivo
}

// funciones metodo 2

//invertir palabra
string invertirpal(string cadena) {
    string invertida = "";
    for (int i = cadena.length() - 1; i >= 0; i--) {
        invertida += cadena[i];
    }
    return invertida;
}


//FUNCION ABRIR ARCHIVO  QUE YA ESTA EN BINARIO PARA CODIFICARLO
void codificarArchivoM2(string archivo_entrada,string archivo_sal,int semi){// se puede ingresar el mismo archivo para entrada y salida
	int x;// x es la semilla
	string linea;// getline
	string linea2,lineatodo="";// caracter a caracter de la linea getlines
	ifstream archivo;// SINTAXIS PARA DECLARA VARIABLE PARA ARCHIVOS
	archivo.open(archivo_entrada);//ABRIMOS EL ARCHIVO
	if (!archivo.is_open()) {
    	cout<< "Error al abrir el archivo\n";
    	return ;
	}
	x=semi;
	while(archivo.good()){
		getline(archivo,linea);//LEEMOS EL ARCHIVO POR LINEA
		for(int i = 0, bloque = 1; linea[i] != '\0'; i++){//RECORREMO0S LA LINEA CARACTER A CARACTER
			linea2 += linea[i];
			if(bloque==x){
				linea2 = invertirpal(linea2);
				lineatodo = lineatodo+ linea2; // escribir la variable linea2 en el archivo
				linea2.clear();
				bloque=1;
			}else{
				bloque++;
			}
		}
		linea2 = invertirpal(linea2);
		lineatodo = lineatodo+ linea2 ; // escribir la variable linea2 en el archivo
		lineatodo = lineatodo+ '\n';
		linea2.clear();
		
	}cout<<lineatodo<<endl;
	archivo.close();
	ofstream archivo_salida(archivo_sal); // abrir el archivo en modo de escritura
	archivo_salida<< lineatodo;
	archivo_salida.close(); // cerrar el archivo
}

// FUNCION CREAR ARCHIVO
void crearArchivo(){
    string nombreArchivo, contenido;
    ofstream archivo;
    // Pedimos al usuario el nombre del archivo
    cout << "Escribe el nombre del archivo: ";
    cin >> nombreArchivo;
    // Agregamos la extensión .txt al nombre del archivo
    nombreArchivo += ".txt";
    // Creamos el archivo
    archivo.open(nombreArchivo.c_str());
    if (archivo.fail()) {
        cout << "Error al crear el archivo." << endl;
        return;
    }
    // Preguntamos si el usuario quiere escribir en el archivo
    cout << "Quieres escribir algo en el archivo? (S/N): ";
    char opcion;
    cin >> opcion;
    if (opcion == 'S' || opcion == 's') {
        // Pedimos al usuario el contenido que quiere escribir
        cout << "Escribe el contenido del archivo: ";
        cin.ignore();
        getline(cin, contenido);
        // Escribimos el contenido en el archivo
        archivo << contenido << endl;
        cout << "Archivo creado correctamente con contenido." << endl;
    } else {
        // Si el usuario no quiere escribir en el archivo, lo dejamos vacío
        cout << "Archivo creado correctamente sin contenido." << endl;
    }
    // Cerramos el archivo
    archivo.close();
}




//FUNCION MENU
void menu() {
    int opcion,semi;
    string nombrearchivo,archivosalida;
    

    do {
        cout << "\n\tBIENVENIDO AL MENU METODO [1] \n" << endl;
        cout << "1. CREAR ARCHIVO / ESCRIBIRLO [1]" << endl;
        cout << "2. ENCRIPTAR  ARCHIVO      [2]" << endl;
        cout << "3. DESENCRIPTAR  ARCHIVO   [3]" << endl;
        cout << "4. SALIR " << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\tElegiste La Opcion 1" << endl;
                crearArchivo();
                break;
            case 2:
                cout << "\t Opcion 2\n\n\t  *INGRESA NOMBRE DE ARCHIVO " << endl;
                cin>>nombrearchivo;nombrearchivo+= ".txt"; 
				cout<< "\t  *INGRESA EL ARCHIVO A GUARDAR  < Puede ser el mismo >\n";
                cin>>archivosalida;archivosalida+= ".txt";cout<<" Ingresa semila \n";
				cin>> semi;
				archivo_TO_binario(nombrearchivo);// archivo a binario
				codificarArchivo(nombrearchivo,archivosalida,semi);
                break;
            case 3:
                cout << "\t La Opcion 3" << endl;
                cout << "\t Opcion 2\n\n\t  *INGRESA NOMBRE DE ARCHIVO " << endl;
                cin>>nombrearchivo;nombrearchivo+= ".txt"; 
				cout<< "\t  *INGRESA EL ARCHIVO A GUARDAR  < Puede ser el mismo >\n";
                cin>>archivosalida;archivosalida+= ".txt";cout<<" Ingresa semila \n";
				cin>> semi;
				desencriptarArchivo(nombrearchivo,archivosalida, semi);
                break;
            case 4:
                cout << "\t ¡Hasta Luego!" << endl;
                break;
            default:
                cout << "\t Opcion inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 4);
}
//FUNCION MENU
void MenuMetodo2() {
    int opcion,semi;
    string nombrearchivo,archivosalida;
    

    do {
        cout << "\n\tBIENVENIDO AL MENU METODO [2] \n" << endl;
        cout << "1. CREAR ARCHIVO / ESCRIBIRLO [1]" << endl;
        cout << "2. ENCRIPTAR  ARCHIVO      [2]" << endl;
        cout << "3. DESENCRIPTAR  ARCHIVO   [3]" << endl;
        cout << "4. SALIR " << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\tElegiste La Opcion 1" << endl;
                crearArchivo();
                break;
            case 2:
                cout << "\t Opcion 2\n\n\t  *INGRESA NOMBRE DE ARCHIVO " << endl;
                cin>>nombrearchivo;nombrearchivo+= ".txt"; 
				cout<< "\t  *INGRESA EL ARCHIVO A GUARDAR  < Puede ser el mismo >\n";
                cin>>archivosalida;archivosalida+= ".txt";cout<<" Ingresa semila \n";
				cin>> semi;
				archivo_TO_binario(nombrearchivo);// archivo a binario
				codificarArchivoM2(nombrearchivo,archivosalida,semi);
                break;
            case 3:
                cout << "\t La Opcion 3" << endl;
                cout << "\t Opcion 2\n\n\t  *INGRESA NOMBRE DE ARCHIVO " << endl;
                cin>>nombrearchivo;nombrearchivo+= ".txt"; 
				cout<< "\t  *INGRESA EL ARCHIVO A GUARDAR  < Puede ser el mismo >\n";
                cin>>archivosalida;archivosalida+= ".txt";cout<<" Ingresa semila \n";
				cin>> semi;
				codificarArchivoM2(nombrearchivo,archivosalida, semi);
                break;
            case 4:
                cout << "\t ¡Hasta Luego!" << endl;
                break;
            default:
                cout << "\t Opcion inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 4);
}

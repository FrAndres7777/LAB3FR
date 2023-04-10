#include "FUNCIONESMETODO1FINAL.h"
#include <cmath>
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




string* iterarArchivo(string nombreArchivo, int& cantLineas) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return nullptr;
    }

    cantLineas = 0;
    string linea;
    while (getline(archivo, linea)) {
        cantLineas++;
    }
    archivo.close();

    string* lineasArchivo = new string[cantLineas];
    archivo.open(nombreArchivo);
    int i = 0;
    while (getline(archivo, linea)) {
        lineasArchivo[i] = linea;
        i++;
    }
    archivo.close();
    return lineasArchivo;
}

void menuuser(){
	int cantLineas;
	int ubisaldo ;
	string user,passw;
    string nombreArchivo = "usuarios.txt";
    string* lineas = iterarArchivo(nombreArchivo, cantLineas);
    bool uservery= true;
    cout << "Ingrese ID: ";cin>>user;
	cout << "Ingrese Contraseña: ";cin>>passw;
	user = lineabincodi(user);
    passw=lineabincodi(passw);
    while (uservery){
    	for (int i = 0; i < cantLineas; i++) {
        	if(i%3==0 or i==0){
        		if(lineas[i]==user){
        			uservery = false;
        			if(lineas[i+1]!=passw){
        				uservery=true;
        				
					}else{
						ubisaldo=i+2;
					}
				}
			}
    	}if(uservery){
    		cout<<"\t USUARIO y/o CONTRASENA INCORRECTOS";
    		cout << "Ingrese ID: ";cin>>user;
			cout << "Ingrese Contraseña: ";cin>>passw;
			user = lineabincodi(user);
    		passw=lineabincodi(passw);
    		
		}
	}
	cout<<"\n\n\tInicio De Seccion Exitoso \n\n";
	int opcionu;
	lineas[ubisaldo]=desencriptar_linea(lineas[ubisaldo], 4);
	int valor= valorlinea(lineas[ubisaldo]);
	int retiro ;
	do {
		cout<<"\t\tMirar Saldo   [1]\n";
		cout<<"\t\tRetirar Cash  [2]\n";
		cin>> opcionu;
		switch (opcionu) {
            case 1:
                cout << "\t\t"<<valor << endl;
                break;
            case 2:
                cout << "\t\tIngrese valor a retirar" << endl;
                cin>>retiro;
                if(valor <retiro+1000){
                	cout<<"\t\tSaldo Insuficiente mi Pez";
				}else{
					cout<<"\t\tRetiro Realizado";
					valor = valor - retiro - 1000;
				}
                
                break;
            case 3:
                cout << "Saliendo..." << endl;
                
                break;
            default:
                cout << "Entrada inválida. Intente nuevamente." << endl;
                break;
        }
	}while(opcionu!= 3);
	cout<<valor;
	string valorStr = to_string(valor);
	cout<<valorStr<<"h i";
    lineas[ubisaldo]=lineabincodi(valorStr);
    ofstream archivoSalida("usuarios.txt"); // Abrir archivo en modo escr
    for (int i = 0; i < cantLineas; i++) {
        archivoSalida << lineas[i] << endl;
    }
    archivoSalida.close(); 
    delete[] lineas;
    
	
}





int contarLineas(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return -1;
    }

    int cantLineas = 0;
    string linea;
    while (getline(archivo, linea)) {
        cantLineas++;
    }
    archivo.close();

    return cantLineas;
}







void registroarchivousuarios(){
	bool uservery=true;
	string linea,usuarioR,passwordR,saldoR;
	cout << "Ingrese Cuidadosamente \n\tUsuario : ";cin>>usuarioR;
	cout<< "\tPassword : ";cin>> passwordR;
	cout << "\tSaldo";cin>> saldoR;
	usuarioR= lineabincodi(usuarioR) ;
	//
	int cantLineas;
    string nombreArchivo = "usuarios.txt";
    string* lineas = iterarArchivo(nombreArchivo, cantLineas);
    while (uservery){
    	uservery=false;
    	for (int i = 0; i < cantLineas; i++) {
        	if(i%3==0 or i==0){
        		if(lineas[i]==usuarioR){
        			uservery = true;
				}
			}
    	}if(uservery){
    		cout<<"\t USUARIO NO VALIDO INGRESE NUEVO";
    		usuarioR.clear();
    		cin>>usuarioR;
    		usuarioR= lineabincodi(usuarioR);
		}
	}
    delete[] lineas;
    usuarioR= usuarioR+ '\n';
	
	
	
	
	
	//
	passwordR= lineabincodi(passwordR) + '\n';
	saldoR=lineabincodi(saldoR) ;
	linea = linea + usuarioR+passwordR+saldoR;
    ofstream archivo("usuarios.txt", ios::app); // ios::app para abrir en modo append
    if (archivo.is_open()) { // verificamos si el archivo se abrió correctamente
        archivo << linea << endl;
        archivo.close(); // cerramos el archivo
    }
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    return ;
}


void abrirArchivoAdmin() {
    string nombreArchivo="sudo.txt",user,passw;
    bool flag = true;
    ifstream archivoEntrada;
    ofstream archivoSalida;

    // Pedir al usuario el nombre del archivo
    // Abrir el archivo en modo lectura
    archivoEntrada.open(nombreArchivo);

    // Verificar si el archivo está vacío
    if (archivoEntrada.peek() == ifstream::traits_type::eof()) {
        archivoEntrada.close();
        archivoSalida.open(nombreArchivo);
		cout<< " Bienvenido Admin\n\tPor favor Regitre Sus Datos\n";
        // Pedir al usuario el texto a escribir en el archivo
        cout << "Ingrese ID: ";cin>>user;
		cout << "Ingrese Contraseña: ";cin>>passw;
		user = lineabincodi(user);
        passw=lineabincodi(passw);
        // Escribir el texto en el archivo y cerrarlo
        archivoSalida << user + '\n';
        archivoSalida << passw;
        archivoSalida.close();

        cout << "Sus Dtos  Como Administrador Fueron Guardados." << endl;
    }
    else {
    	string linea,linea2;
    	getline(archivoEntrada, linea);
    	getline(archivoEntrada, linea2);
		do{
		cout<<"\n  iniciar Seccion \n"<<endl;
    	cout << "\t Ingrese ID: ";cin>>user;
    	user = lineabincodi(user);
		cout << "\t Ingrese Contraseña: ";cin>>passw;
		passw=lineabincodi(passw);
        // Leer el contenido del archivo y mostrarlo en pantalla
    	if(linea!= user){flag =false;
		}else{flag=true;
		}
		if(linea2!= passw or flag == false){flag =false;
		}else{flag=true;
		}
		int opcion;
		if(flag){
			cout<<"\n   inicio seccion con exito";
			while (flag) { // repetimos hasta que el usuario quiera salir
       	 		cout << "\t   Elija una opcion:" << endl;
        		cout << "\t\t1. Agregar usuarios" << endl;
       			cout << "\t\t2. Salir" << endl;
       			cin >> opcion;
       			switch (opcion) {
		            case 1:
		                registroarchivousuarios();
		                break;
		            case 2:
		                flag = false;
		                break;
		            default:
		                cout << "Opcion invalida. Solo puede salir al ingresar 2." << endl;
		                break;
		        }
		    }flag = true;
		}else{
			cout<<"ID o PassWord INCORECCTOS ";
		}

		}while(flag == false);
        archivoEntrada.close();
    }
}
void menucajero(){
	int opcion ;
	cout << "\n\tWELCOME TO THE CASHIER[1] \n" << endl;
	do {
		cout << "\t_________\n";
		cout << "\t M E N U\n";
        cout << "\t---------\n" << endl;
        cout << "1. ENTRAR COMO USUARIO [1]" << endl;
        cout << "2. ENTRAR COMO ADMIN    [2]" << endl;
        cout << "3. SALIR " << endl;
        cin >> opcion;
        switch(opcion) {
            case 1:
            	menuuser();
				break;
            case 2:
                cout << "\tHI ADMIN "<< endl;
                abrirArchivoAdmin();
                break;
            case 3:
                cout << "\t ¡Hasta Luego!\n" << endl;
                break;
            default:
                cout << "\t Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 3);

}




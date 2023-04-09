#include "FUNCIONESMETODO1FINAL.h"



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
			    	cout<<"iniciar Seccion "<<endl;
    	cout << "Ingrese ID: ";cin>>user;
    	user = lineabincodi(user);
		cout << "Ingrese Contraseña: ";cin>>passw;
		passw=lineabincodi(passw);
        // Leer el contenido del archivo y mostrarlo en pantalla
    	if(linea!= user){flag =false;
		}else{flag=true;
		}
		if(linea2!= passw or flag == false){flag =false;
		}else{flag=true;
		}
		if(flag){
			cout<<"inicio seccion con exito";
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
                cout << "\tHI USER" << endl;
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



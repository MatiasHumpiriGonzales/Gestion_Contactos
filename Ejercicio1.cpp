#include <iostream>
#include <string>
using namespace std;
const int MAX_CONTACTOS = 100;
struct contactoEmail {
    string nombreCompleto;
    char sexo;
    int edad;
    string telefono;
    string email;
    string nacionalidad;
};
			string obtenerServidor(string correo) {
            size_t pos = correo.find('@');
            if (pos != string::npos) {
            return correo.substr(pos + 1);
        }
        return "";
}
int main () {
    contactoEmail est[MAX_CONTACTOS];
    int total_contactos = 0;
    int opcion;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Eliminar contacto\n";
        cout << "3. Mostrar listado general\n";
        cout << "4. Mostrar contactos ordenados por servidor de correo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch (opcion) {
        	case 1: {
        		if (total_contactos >= MAX_CONTACTOS){
        			cout << "No se puede agregar mas contactos.\n";
			    break;
			}
			contactoEmail a;
			cout << "Nombre completo: ";
            getline(cin, a.nombreCompleto);
            cout << "Sexo (M/F): ";
            cin >> a.sexo;
            cout << "Edad: ";
            cin >> a.edad;
            cin.ignore();
            cout << "Telefono: ";
            getline(cin, a.telefono);
            cout << "Email: ";
            getline(cin, a.email);
            cout << "Nacionalidad: ";
            getline(cin, a.nacionalidad);
            est[total_contactos] = a;
            total_contactos++;
            cout << "Contacto agregado.\n";
            break;
            }
            case 2: {
            	string nombreBuscar;
            	cout << "Ingrese el nombre completo del contacto a eliminar que desea: ";
            	getline(cin, nombreBuscar);
            	bool encontrado = false;
            	for (int i = 0; i < total_contactos; i++){
            		if(est[i].nombreCompleto ==nombreBuscar) {
            			for (int j = i; j < total_contactos - 1; j++) {
            				est[j] = est[j + 1];
						}
						total_contactos--;
						encontrado = true;
						cout << "Contacto eliminado.\n";
						break;
					}
				}
				if (!encontrado) {
					cout << "No se encontro el contacto.\n";
				}
				break;
			}
			case 3: {
				if (total_contactos == 0){
					cout << "No hay contactos registrado.\n";
				} else {
					for (int i = 0; i < total_contactos; i++){
						cout << "Nombre: " << est[i].nombreCompleto << endl;
                        cout << "Sexo: " << est[i].sexo << endl;
                        cout << "Edad: " << est[i].edad << endl;
                        cout << "Telefono: " << est[i].telefono << endl;
                        cout << "Email: " << est[i].email << endl;
                        cout << "Nacionalidad: " << est[i].nacionalidad << endl;
                        cout << "--------------------------\n";
					}
				}
				break;
			}
		    case 4: {
				if (total_contactos == 0){
					cout << "No hay contactos registrados\n";
				} else {
					for (int i = 0; i < total_contactos - 1; i++){
						for (int j = 0;j < total_contactos - i - 1; j++){
							if(obtenerServidor(est[j].email) > obtenerServidor(est[j+1].email)){
								contactoEmail temp = est[j];
								est[j] = est[j + 1];
								est[j + 1]= temp;
							}
						}
					}
					for (int i = 0; i < total_contactos; i++){
						cout << "Nombre: " << est[i].nombreCompleto << endl;
						cout << "Sexo: " << est[i].sexo << endl;
						cout << "Edad: " << est[i].edad << endl;
						cout << "Telefono: " << est[i].telefono << endl;
						cout << "Email: " << est[i].email << endl;
						cout << "Nacionalidad: " << est[i].nacionalidad << endl;
						cout << "-----------------------\n";
					}
				}
				break;
			}
			case 5:{
				cout << "Saliendo del programa.\n";
				break;
			}
			default:
				cout << "Opcion invalida.\n";
			}
	}while (opcion != 5);
	return 0;
}
	
		     
			
			
 

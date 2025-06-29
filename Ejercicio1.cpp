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
}
 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void registrarVenta();
void mostrarVentas();

int main() {
    int opc;

    do {
        cout << "===== REGISTRO DE VENTAS =====" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Mostrar ventas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                registrarVenta();
                break;

            case 2:
                mostrarVentas();
                break;

            case 3:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opc != 3);

    return 0;
}
void registrarVenta() {
    string producto;
    double monto;

    cin.ignore();

    cout << "Ingrese el nombre del producto: ";
    getline(cin, producto);

    cout << "Ingrese el monto de la venta: $";
    cin >> monto;

    ofstream archivo("ventas.txt", ios::app);

    if (archivo.is_open()) {
        archivo << producto << " - $" << monto << endl;
        archivo.close();

        cout << "\nVenta registrada correctamente." << endl;
    } else {
        cout << "\nError al abrir el archivo." << endl;
    }
}
void mostrarVentas() {
    string linea;

    ifstream archivo("ventas.txt");

    if (archivo.is_open()) {
        cout << "\n===== VENTAS REGISTRADAS =====" << endl;

        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cout << "\nNo hay ventas registradas todavia." << endl;
    }
}
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// estructura para almacenar los datos de los pasajeros
struct Pasajero
{
    string nombre;
    int numeroAsiento;
    bool ocupado;
};

// clase oara manejar la informacion de cada clase
class Clase {
    private:
    Pasajero * asientos;
    int capacidad;
    int asientosVendidos;
    double precioBase;
    string nombreClase;

    public:
    // contructor
    Clase(int cap, double precio, string nombre) {
        capacidad = cap;
        asientosVendidos = 0;
        precioBase = precio;
        nombreClase = nombre;

        // Arreglo dinamico de asientos
        asientos = new Pasajero[capacidad];

        // inicializacion de asientos
        for (int i =0; i < capacidad; i++) {
            asientos[i].ocupado = false;
            asientos[i].numeroAsiento = i + 1;
            asientos[i].nombre = "";
        }
    }

    // descrutor de clase
    ~Clase() {
        delete[] asientos;
    }

    // venden bolotes
    bool venderBoleto (string nombre) {
        if (asientosVendidos >= capacidad) {
             cout <<"No hay asientos disponibles en " << nombreClase << " clase." <<endl;
            return false;
        }

        // buscar primer asiento disponible
        for (int i = 0; i < capacidad; i++) {
            if (!asientos[i].ocupado) {
                asientos[i].ocupado = true;
                asientos[i].nombre = nombre;
                asientosVendidos++;
                cout << "Boleto vendido exitosamente" << endl;
                cout << "Clase: " << nombreClase << endl;
                cout << "Asiento #" << asientos[i].numeroAsiento <<endl;
                cout << "Precio: $" << fixed << setprecision(2) << precioBase <<endl;
                return true;
            }
        }

        return false;
    }

    // mostrar informacion de la clase
    void mostrarInfo() {
        cout << nombreClase <<" Clase:" << endl;
        cout << " Asiento vendidos: " << asientosVendidos << "/" << capacidad << endl;
        cout << " Porcentaje ocupado" << fixed << setprecision(1) << (asientosVendidos * 100 / capacidad) << "%"<< endl;
        cout << " Ingreso estimado: $" << calcularIngreso() << endl;
    }

    // Mostrar listas de pajareos 
    void mostrarPasajeros() {
        cout << "\n--- Lista de pasajero ----" << nombreClase <<" Clase:" << endl;
        bool hayPasajeros = false;

        for (int i = 0; i <capacidad; i++) {
            if (asientos[i].ocupado) {
               cout << "Asientos " << setw(3) << asientos[i].numeroAsiento << asientos[i].nombre << endl;
               hayPasajeros = true;
            }
        }

        if (!hayPasajeros) {
            cout << "No hay pasajeros para esta clase." << endl;
        }
    }

    // calcular ingreso estimado
    double calcularIngreso() {
        return asientosVendidos * precioBase;
    }

    // verificar si hay disponibilidad de asientos
    bool hayDisponibilidad() {
        return asientosVendidos < capacidad;
    }

    int obtenerAsientosVendidos() {
        return asientosVendidos;
    }

};

// clase para manejar el avion completo
class Avion {
    private:
    Clase* primeraClase;
    Clase* segundaClase;
    Clase* terceraClase;
    int capacidadTotal;

    public:
    // contructor
    Avion(int capacidadTotal) {
        this->capacidadTotal = capacidadTotal;

        // calcular capacidad por clase segun su porcentajes de precios
        int capacidadPrimera = capacidadTotal * 0.15;
        int capacidadSegunda = capacidadTotal * 0.25;
        int capacidadTercera = capacidadTotal * 0.60;

        // crear las clases con su precio
        primeraClase = new Clase(capacidadPrimera, 16912.20, "Primera");
        segundaClase = new Clase(capacidadSegunda, 15125.70, "Segunda");
        terceraClase = new Clase(capacidadTercera, 13756.06, "Tercera");

        cout << " Avión Inicializado " << endl;
        cout << "Capacidad total: " << capacidadTotal << " asientos" << endl;
        cout << "Primera Clase: " << capacidadPrimera << " asientos (15%)" << endl;
        cout << "Segunda Clase: " << capacidadSegunda << " asientos (25%)" << endl;
        cout << "Tercera Clase: " << capacidadTercera << " asientos (60%)" << endl;
        cout << "----------------" << endl;
    }

    // Destructor
    ~Avion() {
        delete primeraClase;
        delete segundaClase;
        delete terceraClase;
    }

    // Vender boletos por clases especifica
    bool venderBoleto(int clase, string nombre) {
        switch (clase)
        {
            case 1:
                return primeraClase->venderBoleto(nombre);   
            case 2:
                return segundaClase->venderBoleto(nombre);
            case 3:
                return terceraClase->venderBoleto(nombre);      
            default:
                cout << "Clase invalidad" << endl;
                return false;
        }
    }

     // Mostrar estadísticas del vuelo
    void mostrarEstadisticas() {
        cout << "\n Estadísticas del vuelo " << endl;
        primeraClase->mostrarInfo();
        cout << endl;
        segundaClase->mostrarInfo();
        cout << endl;
        terceraClase->mostrarInfo();
        
        double ingresoTotal = primeraClase->calcularIngreso() + 
                             segundaClase->calcularIngreso() + 
                             terceraClase->calcularIngreso();
        
        int totalVendidos = primeraClase->obtenerAsientosVendidos() + 
                           segundaClase->obtenerAsientosVendidos() + 
                           terceraClase->obtenerAsientosVendidos();
        
        cout << "\n Resumen " << endl;
        cout << "Total boletos vendidos: " << totalVendidos << "/" << capacidadTotal << endl;
        cout << "Porcentaje de ocupación: " << fixed << setprecision(1) 
             << (totalVendidos * 100.0 / capacidadTotal) << "%" << endl;
        cout << "Ingreso total estimado: $" << fixed << setprecision(2) << ingresoTotal << endl;
        cout << "-------------------------" << endl;
    }
    
    // Mostrar todos los pasajeros
    void mostrarTodosPasajeros() {
        cout << "\n Listado de pasajeros " << endl;
        primeraClase->mostrarPasajeros();
        segundaClase->mostrarPasajeros();
        terceraClase->mostrarPasajeros();
    }
    
    // Verificar si hay disponibilidad en alguna clase
    bool hayDisponibilidad() {
        return primeraClase->hayDisponibilidad() || 
               segundaClase->hayDisponibilidad() || 
               terceraClase->hayDisponibilidad();
    }
    
    int getCapacidadTotal() {
        return capacidadTotal;
    }
    
    int getTotalVendidos() {
        return primeraClase->obtenerAsientosVendidos() + 
               segundaClase->obtenerAsientosVendidos() + 
               terceraClase->obtenerAsientosVendidos();
    }
};

// Función para limpiar la pantalla
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para pausar y continuar
void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

// Función principal
int main() {
    int capacidadAvion;
    
    cout << " Sistema de gestíon de pasajeros. " << endl;
    cout << "Ingrese la capacidad total del avión: ";
    cin >> capacidadAvion;
    
    // Validar entrada
    while (capacidadAvion <= 0) {
        cout << "Capacidad inválida. Ingrese un número positivo: ";
        cin >> capacidadAvion;
    }
    
    limpiarPantalla();
    
    // Crear el avión
    Avion avion(capacidadAvion);
    
    int opcion;
    string nombre;
    int clase;
    
    do {
        cout << "\n Menu principal " << endl;
        cout << "1. Vender boleto" << endl;
        cout << "2. Mostrar estadísticas" << endl;
        cout << "3. Mostrar todos los pasajeros" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        // Limpiar buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(opcion) {
            case 1:
                if (!avion.hayDisponibilidad()) {
                    cout << "\n¡El avión está completamente lleno! No se pueden vender más boletos." << endl;
                    pausar();
                    break;
                }
                
                cout << "\n Ventas de vuelos " << endl;
                cout << "Asientos disponibles: " << avion.getCapacidadTotal() - avion.getTotalVendidos() << endl;
                cout << "Seleccione la clase:" << endl;
                cout << "1. Primera Clase $16912.20" << endl;
                cout << "2. Segunda Clase $15125.70" << endl;
                cout << "3. Tercera Clase $13756.06" << endl;
                cout << "Opción: ";
                cin >> clase;
                
                // Validar clase
                if (clase < 1 || clase > 3) {
                    cout << "Clase inválida!" << endl;
                    pausar();
                    break;
                }
                
                cout << "Ingrese el nombre completo del pasajero: ";
                cin.ignore();
                getline(cin, nombre);
                
                if (nombre.empty()) {
                    cout << "Nombre inválido!" << endl;
                    pausar();
                    break;
                }
                
                limpiarPantalla();
                if (avion.venderBoleto(clase, nombre)) {
                    cout << "\n¡Venta realizada con éxito!" << endl;
                }
                pausar();
                break;
                
            case 2:
                limpiarPantalla();
                avion.mostrarEstadisticas();
                pausar();
                break;
                
            case 3:
                limpiarPantalla();
                avion.mostrarTodosPasajeros();
                pausar();
                break;
                
            case 4:
                cout << "\n¡Gracias por usar el sistema!" << endl;
                break;
                
            default:
                cout << "Opción inválida!" << endl;
                pausar();
                break;
        }
        
        limpiarPantalla();
        
    } while (opcion != 4);
    
    return 0;
}

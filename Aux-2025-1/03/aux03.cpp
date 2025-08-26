#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Setters con validación
    void setEdad(int nuevaEdad) {
        if (nuevaEdad >= 0) {
            edad = nuevaEdad;
        }
    }

    // Getters
    int getEdad() const { return edad; }
    string getNombre() const { return nombre; }
};


int main() {
    
    string saludo = "Hola";
    string nombre = "Ana";
    
    // Concatenación
    string mensaje = saludo + ", " + nombre + "!";
    cout << mensaje << endl; // Hola, Ana!
    
    // Longitud
    cout << "Longitud: " << mensaje.size() << endl; 
    
    // Búsqueda
    size_t pos = mensaje.find("Ana");
    if (pos != string::npos) {
        cout << "Ana está en la posición: " << pos << endl;
    }

    //Manejo de Archivos

    ofstream archivoSalida("datos.txt");
    if (archivoSalida.is_open()) {
        archivoSalida << "Línea 1\nLínea 2\n";
        archivoSalida.close();
    }

    // Lectura
    ifstream archivoEntrada("malibu.txt");
    string linea;
    if (archivoEntrada.is_open()) {
        while (getline(archivoEntrada, linea)) {
            cout << linea << endl;
        }
        archivoEntrada.close();
    }

    
    //Encapsulamiento
    Persona p;
    p.setEdad(25); // Correcto
    // p.edad = -5; // Error: miembro privado
    cout << "Edad: " << p.getEdad() << std::endl;

    return 0;
}
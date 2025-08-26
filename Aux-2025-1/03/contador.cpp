#include <iostream>
using namespace std;

// TDA Contador
class Contador {
private:
    int valor;  // Atributo privado (encapsulado)

public:
    // Constructor (inicializa el contador en 0)
    Contador() : valor(0) {}

    // Operación para incrementar el contador
    void incrementar() {
        valor++;
    }

    // Operación para decrementar el contador (con validación)
    void decrementar() {
        if (valor > 0) {  // No permite valores negativos
            valor--;
        }
    }

    // Operación para obtener el valor actual
    int obtenerValor() const {
        return valor;
    }

    // Operación para reiniciar el contador
    void reiniciar() {
        valor = 0;
    }
};

int main() {
    // Uso del TDA Contador
    Contador miContador;

    cout << "Valor inicial: " << miContador.obtenerValor() << endl; // 0

    miContador.incrementar();
    miContador.incrementar();
    cout << "Después de incrementar 2 veces: " << miContador.obtenerValor() << endl; // 2

    miContador.decrementar();
    cout << "Después de decrementar: " << miContador.obtenerValor() << endl; // 1

    miContador.reiniciar();
    cout << "Después de reiniciar: " << miContador.obtenerValor() << endl; // 0

    return 0;
}
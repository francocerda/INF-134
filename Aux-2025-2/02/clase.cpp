#include<iostream>

using namespace std;

struct Punto {
    double x; 
    double y; 

    void imprimir() {
        cout << "Punto en (" << x << ", " << y << ")" << std::endl;
    }
};

class CuentaBancaria {
private:
    double saldo; // No se puede acceder desde fuera

public:
    // Constructor
    CuentaBancaria(double saldo_inicial) {
        saldo = saldo_inicial;
    }

    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
        }
    }

    double getSaldo() {
        return saldo;
    }
};

class Persona{
private:
    int edad;
    string rut;

public:

    Persona(int x, string y){ // Constructor
        edad = x;
        rut = y;
        cout << rut << endl;

    }
    ~Persona(){
        cout << "Destruccion"<< endl;
    }

    void saludar(){
        cout << "Hola, mi rut es " << rut << " y tengo " << edad << " anios." << endl;
    }

};


int main(){

    CuentaBancaria BancoEstado(1000.00);
    BancoEstado.depositar(50.0);
    cout << "El saldo es: " << BancoEstado.getSaldo() << endl;

    //---------------------------------------------------------------

    Punto plano = {2.3,4.2};

    cout << "--- Asignacion Normal (Estatica / Stack) ---" << endl;
    Persona persona_estatica(30,"12.345.678-9");
    persona_estatica.saludar();

    cout << "\n--- Asignacion Dinamica (Heap) ---" << endl;
    Persona* punteroPersona;//Creamos un puntero, nada mas.
    punteroPersona = new Persona(25, "98.765.432-1");
    punteroPersona->saludar();
    delete punteroPersona;

    return 0;
}
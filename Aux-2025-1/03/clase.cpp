#include<iostream>

using namespace std;


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
#include <iostream>
#include <string>

using namespace std;

class Auto {
private:
    string marca;
    string modelo;
    int velocidad;

public:
    Auto(string m, string mod) {
        marca = m;
        modelo = mod;
        velocidad = 0;
        cout << "Se construyo un " << marca << " " << modelo << endl;
    }

    void acelerar(int aumento) {
        if (aumento > 0) {
            velocidad = velocidad + aumento;
            cout << "El " << marca << " acelera. Velocidad actual: " << velocidad << " km/h" << endl;
        }
    }

    void frenar(int reduccion) {
        if (reduccion > 0) {
            velocidad = velocidad - reduccion;// ojo que puede ser velocidad -= reduccion
            if (velocidad < 0) {
                velocidad = 0;
            }
            cout << "El " << marca << " frena. Velocidad actual: " << velocidad << " km/h" << endl;
        }
    }

    void mostrarInfo() {
        cout << "--------------------" << endl;
        cout << "Info del Auto:" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Velocidad: " << velocidad << " km/h" << endl;
        cout << "--------------------" << endl;
    }
};

int main() {
    Auto miFerrari("Ferrari", "F8");
    Auto miVocho("Volkswagen", "Escarabajo");

    miFerrari.mostrarInfo();
    miVocho.mostrarInfo();

    miFerrari.acelerar(100);
    miVocho.acelerar(30);

    miFerrari.frenar(20);
    miVocho.acelerar(15);

    miFerrari.mostrarInfo();
    miVocho.mostrarInfo();

    return 0;
}
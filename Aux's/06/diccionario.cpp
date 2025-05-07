#include <iostream>
#include <string>

using namespace std;

struct Par {
    int clave;
    string valor;
};

const int MAX_CAPACIDAD = 100;

class DiccionarioOrdenado {
private:
    Par elementos[MAX_CAPACIDAD];
    int tamanoActual;

    int buscarPosicion(int clave) {
        int indice = 0;
        while (indice < tamanoActual && elementos[indice].clave < clave) {
             indice++;
        }
        return indice;
    }

public:
    DiccionarioOrdenado() {
        tamanoActual = 0;
    }

    bool estaVacio() {
        return tamanoActual == 0;
    }

    int obtenerTamano() {
        return tamanoActual;
    }

    bool insertar(int clave, string valor) {
        if (tamanoActual >= MAX_CAPACIDAD) {
            cerr << "Error: Diccionario lleno. No se puede insertar (" << clave << ": '" << valor << "')." << endl;
            return false;
        }

        int pos = buscarPosicion(clave);

        if (pos < tamanoActual && elementos[pos].clave == clave) {
             cerr << "Error: La clave " << clave << " ya existe. No se insertó." << endl;
            return false;
        }

         for (int i = tamanoActual; i > pos; --i) {
             elementos[i] = elementos[i - 1];
         }

        elementos[pos].clave = clave;
        elementos[pos].valor = valor;
        tamanoActual++;

        return true;
    }

    string buscar(int clave) {
        int pos = buscarPosicion(clave);
        string valorEncontrado = "";

         if (pos < tamanoActual && elementos[pos].clave == clave) {
             valorEncontrado = elementos[pos].valor;
         }

        return valorEncontrado;
    }

    bool eliminar(int clave) {
        int pos = buscarPosicion(clave);

        if (pos >= tamanoActual || elementos[pos].clave != clave) {
            return false;
        }

         for (int i = pos; i < tamanoActual - 1; ++i) {
             elementos[i] = elementos[i + 1];
         }

         tamanoActual--;

        return true;
    }

    void imprimir() {
        cout << "Diccionario Ordenado (tamano: " << tamanoActual << "):" << endl;
        if (estaVacio()) {
            cout << "  { Vacío }" << endl;
            return;
        }
        cout << "  {" << endl;
        for (int i = 0; i < tamanoActual; ++i) {
            cout << "    " << elementos[i].clave << ": '" << elementos[i].valor << "'" << endl;
        }
        cout << "  }" << endl;
    }
};

int main() {
    DiccionarioOrdenado miDiccionario;

    cout << "Diccionario creado. ¿Está vacío? " << (miDiccionario.estaVacio() ? "Sí" : "No") << endl;
    miDiccionario.imprimir();
    cout << "-------------------------" << endl;

    cout << "Insertando elementos..." << endl;
    miDiccionario.insertar(5, "Manzana");
    miDiccionario.insertar(2, "Pera");
    miDiccionario.insertar(8, "Naranja");
    miDiccionario.insertar(1, "Uva");
    miDiccionario.insertar(5, "Plátano");
    miDiccionario.insertar(6, "Melón");

    miDiccionario.imprimir();
    cout << "Tamaño actual: " << miDiccionario.obtenerTamano() << endl;
    cout << "¿Está vacío? " << (miDiccionario.estaVacio() ? "Sí" : "No") << endl;
    cout << "-------------------------" << endl;

    cout << "Buscando claves..." << endl;
    cout << "Valor para clave 5: '" << miDiccionario.buscar(5) << "'" << endl;
    cout << "Valor para clave 1: '" << miDiccionario.buscar(1) << "'" << endl;
    cout << "Valor para clave 99: '" << miDiccionario.buscar(99) << "' (Esperado: vacío)" << endl;
    cout << "-------------------------" << endl;

    cout << "Eliminando elementos..." << endl;
    cout << "¿Se eliminó la clave 2? " << (miDiccionario.eliminar(2) ? "Sí" : "No") << endl;
    miDiccionario.imprimir();
    cout << "¿Se eliminó la clave 99? " << (miDiccionario.eliminar(99) ? "Sí" : "No") << " (Esperado: No)" << endl;
    miDiccionario.imprimir();
     cout << "¿Se eliminó la clave 8? " << (miDiccionario.eliminar(8) ? "Sí" : "No") << endl;
    miDiccionario.imprimir();
    cout << "Tamaño final: " << miDiccionario.obtenerTamano() << endl;

    return 0;
}
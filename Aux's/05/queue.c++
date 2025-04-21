#include<iostream>

using namespace std;

class Cola {
private:
    int* arreglo;     // Arreglo dinámico para almacenar elementos
    int capacidad;    // Capacidad máxima de la cola
    int frente;       // Índice del primer elemento (para quitar)
    int final;        // Índice del último elemento (para agregar)
    int contador;     // Número de elementos actuales en la cola

public:
    // Constructor (inicializa la cola)
    Cola(int capacidad);

    // Destructor (libera memoria)
    ~Cola();

    // Operaciones básicas
    void encolar(int elemento); // Agregar al final
    void desencolar();          // Eliminar el frente
    int verFrente();            // Ver el elemento del frente
    bool estaVacia();           // ¿Está vacía?
    bool estaLlena();           // ¿Está llena?
    int tamanio();              // Número de elementos
};

// Constructor: crea una cola vacía con cierta capacidad
Cola::Cola(int capacidad) {
    this->capacidad = capacidad;
    arreglo = new int[capacidad]; // Reservar memoria
    frente = 0;      // El frente inicia en 0
    final = -1;      // Final inicia en -1 (cola vacía)
    contador = 0;    // Contador inicia en 0
}

// Destructor: libera la memoria del arreglo
Cola::~Cola() {
    delete[] arreglo;
}

void Cola::encolar(int elemento) {
    if (estaLlena()) {
        cerr << "Error: Cola llena!" << endl;
        exit(1);
    }
    // Mover el índice "final" de manera circular
    final = (final + 1) % capacidad;
    arreglo[final] = elemento;
    contador++;
}

void Cola::desencolar() {
    if (estaVacia()) {
        cerr << "Error: Cola vacía!" << endl;
        exit(1);
    }
    // Mover el índice "frente" de manera circular
    frente = (frente + 1) % capacidad;
    contador--;
}

// Ver el elemento del frente
int Cola::verFrente() {
    if (estaVacia()) {
        cerr << "Error: Cola vacía!" << endl;
        exit(1);
    }
    return arreglo[frente];
}

// Verificar si está vacía
bool Cola::estaVacia() {
    return (contador == 0);
}

// Verificar si está llena
bool Cola::estaLlena() {
    return (contador == capacidad);
}

// Obtener número de elementos
int Cola::tamanio() {
    return contador;
}

int main() {
    // Crear cola con capacidad para 3 elementos
    Cola miCola(3);

    // Encolar elementos
    miCola.encolar(10);
    miCola.encolar(20);
    miCola.encolar(30);

    cout << "Frente: " << miCola.verFrente() << endl; // 10

    // Desencolar
    miCola.desencolar();
    cout << "Nuevo frente: " << miCola.verFrente() << endl; // 20

    // Ver tamaño
    cout << "Elementos en cola: " << miCola.tamanio() << endl; // 2

    return 0;
}
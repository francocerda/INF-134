#include<iostream>

using namespace std;

class Pila{
    private:
        int tope; //indice de mi tope
        int capacidad; //max tamaño de la pila
        int* arreglo; //puntero a la pila
    public:
        Pila(int capacidad);
        ~Pila();
        void push(int valor);
        void pop();
        int top();
        bool isEmpty();
};

Pila::Pila(int capacidad){
    this->capacidad = capacidad;
    arreglo = new int[capacidad];
    tope = -1;
}

// Destructor: libera la memoria del arreglo
Pila::~Pila() {
    delete[] arreglo;
}

void Pila::push(int elemento) {
    if (tope == capacidad - 1) { // Si la pila está llena
        cerr << "Error: Pila llena!" << endl;
        exit(1);
    }
    tope++;             // Movemos el índice del tope
    arreglo[tope] = elemento; // Almacenamos el elemento
}

void Pila::pop() {
    if (isEmpty()) { // Si la pila está vacía
        cerr << "Error: Pila vacía!" << endl;
        exit(1);
    }
    tope--; // Basta con decrementar el índice (no borramos físicamente)
}

int Pila::top() {
    if (isEmpty()) {
        cerr << "Error: Pila vacía!" << endl;
        exit(1);
    }
    return arreglo[tope]; // Devuelve el valor en el tope
}

bool Pila::isEmpty() {
    return (tope == -1); // Si el índice del tope es -1, la pila está vacía
}

int main() {
    // Crear pila con capacidad para 5 elementos
    Pila miPila(5);

    // Insertar elementos
    miPila.push(10);
    miPila.push(20);
    miPila.push(30);

    // Ver tope
    cout << "Tope actual: " << miPila.top() << endl; // 30

    // Eliminar tope
    miPila.pop();
    cout << "Tope después de pop: " << miPila.top() << endl; // 20

    // Verificar si está vacía
    cout << "Vacía? " << (miPila.isEmpty() ? "Sí" : "No") << endl; // No

    return 0;
}
#include<iostream>

using namespace std;

int sumar(int a, int b);

int main(){

    cout << "Hola Mundo" << endl;
   
    //Tipos de Datos
    int edad = 25;
    double altura = 1.75;
    char inicial = 'J';
    bool esEstudiante = true;
    string nombre = "Juan Perez";

    cout << "Nombre: " << nombre << endl;
    cout << "Inicial: " << inicial << endl;
    cout << "Edad: " << edad << " anios" << endl;
    cout << "Altura: " << altura << " metros" << endl;
    cout << "Es estudiante? (1 es si, 0 es no): " << esEstudiante << endl;

    //Entrada
    int edad;

    cout << "Por favor, ingresa tu edad: ";
    cin >> edad; // Lee un número entero desde el teclado

    cout << "Tienes " << edad << " anios." << endl;

    //Condicionales
    int numero;

    cout << "Ingresa un numero: ";
    cin >> numero;

    if (numero > 0) {
        cout << "El numero es positivo." << endl;
    } else if (numero < 0) {
        cout << "El numero es negativo." << endl;
    } else {
        cout << "El numero es cero." << endl;
    }

    //ciclo for
    cout << "Contando del 1 al 5:" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << i << endl;
    }

    //Funcion
    int num1 = 10;
    int num2 = 5;
    int resultado = sumar(num1, num2); // Llamada a la función

    cout << "La suma de " << num1 << " y " << num2 << " es: " << resultado << endl;

    //Arreglos
    int numeros[5] = {10, 20, 30, 40, 50};

    cout << "Elementos del arreglo:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Elemento " << i << ": " << numeros[i] << endl;
    }


    return 0;
}

// Definición de la función
int sumar(int a, int b) {
    return a + b;
}
#include <iostream>
#include <string>

using namespace std;

// Función para imprimir un arreglo de enteros
void imprimirArreglo(int arr[], int tamaño, const string& nombre) {
    cout << nombre << ": ";
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    // --------------------- Introducción a Punteros ---------------------
    cout << "=== Introducción a Punteros ===\n";

    // **¿Qué es un puntero?**
    // Un puntero es una variable especial que guarda la dirección de memoria de otra variable.
    // Nos permite trabajar con datos de forma indirecta, lo cual es muy útil para manejar memoria y estructuras complejas.

    // Declaramos una variable normal
    int numero = 10;

    // Declaramos un puntero a entero (int*)
    int* ptr;

    // Le asignamos la dirección de 'numero' usando el operador '&' (dirección de)
    ptr = &numero;

    // Ahora 'ptr' guarda la dirección de memoria donde está 'numero'
    cout << "Valor de numero: " << numero << endl;
    cout << "Dirección de numero: " << &numero << endl;
    cout << "Valor de ptr (dirección): " << ptr << endl;

    // Usamos el operador '*' (desreferencia) para acceder al valor en esa dirección
    cout << "Valor al que apunta ptr: " << *ptr << endl;

    // Podemos modificar 'numero' a través del puntero
    *ptr = 20;
    cout << "Nuevo valor de numero tras modificar con el puntero: " << numero << endl;

    // --------------------- Punteros y Arreglos ---------------------
    cout << "\n=== Punteros y Arreglos ===\n";

    // **Relación entre punteros y arreglos**
    // En C++, el nombre de un arreglo es un puntero al primer elemento del arreglo.
    // Esto significa que podemos usar punteros para trabajar con arreglos.

    // Creamos un arreglo de calificaciones
    int calificaciones[5] = {85, 90, 78, 92, 88};

    // Mostramos el arreglo original
    imprimirArreglo(calificaciones, 5, "Calificaciones originales");

    // Creamos un puntero que apunta al inicio del arreglo
    int* ptrCalificaciones = calificaciones; // Equivale a &calificaciones[0]

    // Accedemos a los elementos usando el puntero
    cout << "Primer elemento: " << *ptrCalificaciones << endl;
    cout << "Segundo elemento: " << *(ptrCalificaciones + 1) << endl; // Sumamos 1 para avanzar


    cout << "Primer elemento(dirección de memoria): " << ptrCalificaciones << endl;
    cout << "Segundo elemento(dirección de memoria): " << (ptrCalificaciones + 1) << endl;
    cout << "Tercer elemento(dirección de memoria): " << (ptrCalificaciones + 2) << endl;
    // También podemos usar notación de arreglo con el puntero
    cout << "Tercer elemento: " << ptrCalificaciones[2] << endl;

    // Modificamos el arreglo usando el puntero
    ptrCalificaciones[0] = 95;       // Cambia el primer elemento
    *(ptrCalificaciones + 3) = 100;  // Cambia el cuarto elemento

    // Mostramos el arreglo modificado
    imprimirArreglo(calificaciones, 5, "Calificaciones modificadas");

    // --------------------- Ejemplo Práctico  ---------------------
    cout << "\n=== Ejemplo Práctico: Ajuste de Calificaciones ===\n";

    // Imagina que quieres ajustar las calificaciones de un estudiante sumando 5 puntos a cada una,
    // pero sin que ninguna supere 100. Usaremos un puntero para hacerlo.

    for (int i = 0; i < 5; i++) {
        int* ptrActual = &calificaciones[i]; // Puntero al elemento actual
        *ptrActual += 5;                     // Aumentamos en 5
        if (*ptrActual > 100) {              // Si supera 100, lo limitamos
            *ptrActual = 100;
        }
    }

    // Mostramos el resultado
    imprimirArreglo(calificaciones, 5, "Calificaciones después del ajuste");

    // --------------------- Aritmética de Punteros ---------------------
    cout << "\n=== Aritmética de Punteros ===\n";

    // Podemos movernos por un arreglo usando aritmética de punteros.
    // Al sumar 1 a un puntero, avanza al siguiente elemento (según el tipo de dato).

    int arreglo[3] = {10, 20, 30};
    int* ptrArreglo = arreglo;

    cout << "Elemento 0: " << *ptrArreglo << endl;
    ptrArreglo++; // Avanza al siguiente elemento
    cout << "Elemento 1: " << *ptrArreglo << endl;
    ptrArreglo++; // Avanza otra vez
    cout << "Elemento 2: " << *ptrArreglo << endl;

    // Podemos calcular la diferencia entre dos punteros
    int* ptrInicio = &arreglo[0];
    int* ptrFin = &arreglo[2];
    cout << "Diferencia entre ptrFin y ptrInicio: " << (ptrFin - ptrInicio) << " elementos" << endl;

    // --------------------- Precauciones ---------------------
    cout << "\n=== Precauciones con Punteros ===\n";

    // **Cuidado con los punteros:**
    // 1. No uses un puntero sin inicializarlo
    // int* ptrSinInicializar;
    // *ptrSinInicializar = 5; // ERROR: No sabemos a dónde apunta

    // 2. No desreferencies un puntero nulo
    // int* ptrNulo = nullptr;
    // cout << *ptrNulo; // ERROR: Intento de acceder a memoria inválida

    // 3. No accedas fuera de los límites de un arreglo
    // ptrArreglo = &arreglo[3]; // ERROR: Fuera de los límites

    cout << "Siempre inicializa tus punteros y respeta los límites de memoria.\n";

    return 0;
}
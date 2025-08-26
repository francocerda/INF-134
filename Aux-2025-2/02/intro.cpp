#include <iostream>
using namespace std;

// 5. Funciones en C++
int suma(int a, int b)
{
    a += b;
    return a + b; // Función que devuelve la suma de dos números
}

int main()
{

    // 1. Tipos de datos en C++
    int entero = 10;       // Declaración de un entero
    double decimal = 3.14; // Declaración de un número decimal
    char caracter = 'A';   // Declaración de un carácter
    bool bandera = true;   // Declaración de un valor booleano

    cout << "Tipos de datos en C++:" << endl;
    cout << "Entero: " << entero << endl;
    cout << "Decimal: " << decimal << endl;
    cout << "Carácter: " << caracter << endl;
    cout << "Bandera: " << bandera << endl;
    cout << endl;

    int n, m;
    if (n > m)
    {
        n += 1;
    }

    // 2. Arreglos en C++
    int arreglo[5] = {1, 2, 3, 4, 5}; // Declaración de un arreglo de 5 enteros

    cout << "Arreglo en C++:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento " << i << ": " << arreglo[i] << endl;
    }
    cout << endl;

    // 3. Structs (estructuras) en C++
    struct Persona
    {
        string nombre;
        int edad;
    };

    // Crear un objeto de la estructura Persona
    Persona persona1 = {"Juan", 25};
    Persona persona2 = {"Pedro", 22};

    cout << "Struct en C++ (estructura de datos):" << endl;
    cout << "Nombre: " << persona1.nombre << ", Edad: " << persona1.edad << endl;
    cout << endl;

    // 4. Punteros en C++
    int valor = 100;
    int* puntero = &valor; // Puntero que apunta a la dirección de memoria de "valor"

    cout << "Punteros en C++:" << endl;
    cout << "Valor de la variable: " << valor << endl;
    cout << "Dirección de memoria de 'valor': " << puntero << endl;
    cout << "Valor apuntado por el puntero: " << *puntero << endl;
    cout << endl;

    int resultado = suma(5, 3); // Llamada a la función suma
    cout << "Funciones en C++:" << endl;
    cout << "Suma de 5 y 3: " << resultado << endl;
    cout << endl;

    // 6. Memoria dinámica en C++
    int* arregloDinamico = new int[5]; // Crear un arreglo dinámico de 5 enteros

    // Asignar valores al arreglo dinámico
    for (int i = 0; i < 5; i++)
    {
        arregloDinamico[i] = i * 10; // Asignar múltiplos de 10
    }

    cout << "Memoria dinámica en C++:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento " << i << " del arreglo dinámico: " << arregloDinamico[i] << endl;
    }
    delete[] arregloDinamico; // Liberar la memoria dinámica

    return 0;
}

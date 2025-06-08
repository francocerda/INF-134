#include <iostream>
#include <vector>
#include <list>
#include <queue>    // Para BFS
#include <algorithm> // Para find (opcional, para evitar duplicados al agregar aristas)
#include <string>   // Para la indentación en DFS

using namespace std;

// Definición de la clase Grafo
class Grafo {
public:
    int numNodos;
    vector<list<int>> adjList; // Lista de adyacencias

    // Constructor
    Grafo(int n) {
        numNodos = n;
        adjList.resize(numNodos); // Redimensiona la lista para el número de nodos
        cout << "Grafo creado con " << numNodos << " nodos (numerados de 0 a " << numNodos - 1 << ")." << endl;
        cout << "--------------------------------------------------" << endl;
    }

    // Función para agregar una arista (conexión)
    // Para un grafo no dirigido, se añade en ambas direcciones
    void agregarArista(int u, int v) {
        if (u >= 0 && u < numNodos && v >= 0 && v < numNodos) {
            // Añadir v a la lista de u
            // Opcional: verificar si ya existe para no duplicar en grafos simples
            if (find(adjList[u].begin(), adjList[u].end(), v) == adjList[u].end()) {
                adjList[u].push_back(v);
            }
            // Añadir u a la lista de v (porque es no dirigido)
            if (find(adjList[v].begin(), adjList[v].end(), u) == adjList[v].end()) {
                adjList[v].push_back(u);
            }
            cout << "Arista agregada entre nodo " << u << " y nodo " << v << "." << endl;
        } else {
            cerr << "Error: Nodos " << u << " o " << v << " fuera de rango." << endl;
        }
    }

    // Función para mostrar la lista de adyacencias (la estructura del grafo)
    void mostrarLista() {
        cout << "\n--- Estructura del Grafo (Lista de Adyacencias) ---" << endl;
        for (int i = 0; i < numNodos; ++i) {
            cout << "Nodo " << i << " conectado con: ";
            if (adjList[i].empty()) {
                cout << "(ninguno)";
            } else {
                // Opcional: Ordenar para una visualización consistente
                // adjList[i].sort(); 
                for (int vecino : adjList[i]) {
                    cout << vecino << " ";
                }
            }
            cout << endl;
        }
        cout << "--------------------------------------------------" << endl;
    }

    // Implementación de Búsqueda en Anchura (BFS)
    void BFS(int nodoInicio) {
        if (nodoInicio < 0 || nodoInicio >= numNodos) {
            cerr << "Error: Nodo de inicio BFS inválido." << endl;
            return;
        }

        cout << "\n--- Iniciando BFS desde el nodo " << nodoInicio << " ---" << endl;
        vector<bool> visitado(numNodos, false); // Vector para marcar nodos visitados
        queue<int> cola;                       // Cola para BFS

        visitado[nodoInicio] = true;
        cola.push(nodoInicio);

        cout << "Paso 0: Nodo inicial " << nodoInicio << " agregado a la cola. Marcado como visitado." << endl;
        mostrarEstadoCola(cola);
        mostrarVisitados(visitado);

        int pasoBFS = 1;
        while (!cola.empty()) {
            int u = cola.front(); // Tomar el primer nodo de la cola
            cola.pop();

            cout << "\nPaso " << pasoBFS << ": Sacar nodo " << u << " de la cola. Procesando nodo " << u << "." << endl;
            
            // Opcional: Ordenar vecinos para una exploración determinista si es necesario
            // adjList[u].sort();

            cout << "  Explorando vecinos de " << u << ": ";
            bool algunVecinoNoVisitado = false;
            for (int vecino : adjList[u]) {
                cout << vecino << " ";
                if (!visitado[vecino]) {
                    algunVecinoNoVisitado = true;
                    visitado[vecino] = true;
                    cola.push(vecino);
                    cout << "(no visitado, se marca y encola) ";
                } else {
                    cout << "(ya visitado) ";
                }
            }
            if (adjList[u].empty()) cout << "(sin vecinos)";
            else if (!algunVecinoNoVisitado && !adjList[u].empty()) cout << "(todos los vecinos ya visitados)";
            cout << endl;

            mostrarEstadoCola(cola);
            mostrarVisitados(visitado);
            pasoBFS++;
        }
        cout << "\n--- BFS Finalizado ---" << endl;
        cout << "--------------------------------------------------" << endl;
    }

    // Función auxiliar para DFS recursivo
    void DFSRecursivo(int u, vector<bool>& visitado, int& pasoDFS, const string& indentacion) {
        visitado[u] = true;
        cout << indentacion << "Paso " << pasoDFS << ": Visitando nodo " << u << " (Profundidad actual)." << endl;
        cout << indentacion << "  Procesando nodo " << u << ". Marcado como visitado." << endl;
        mostrarVisitados(visitado, indentacion + "  ");

        pasoDFS++;
        
        // Opcional: Ordenar vecinos
        // adjList[u].sort();

        cout << indentacion << "  Explorando vecinos de " << u << ":" << endl;
        bool exploradoAlgunCamino = false;
        for (int v : adjList[u]) {
            cout << indentacion << "    Considerando vecino " << v << ": ";
            if (!visitado[v]) {
                cout << "NO VISITADO. Llamada recursiva a DFS(" << v << ")." << endl;
                exploradoAlgunCamino = true;
                DFSRecursivo(v, visitado, pasoDFS, indentacion + "      ");
                cout << indentacion << "    Retorno de DFS(" << v << ") a DFS(" << u << ")." << endl;
            } else {
                cout << "YA VISITADO." << endl;
            }
        }
        if (!exploradoAlgunCamino && !adjList[u].empty()) {
             cout << indentacion << "  Todos los vecinos de " << u << " ya fueron visitados por alguna ruta anterior." << endl;
        } else if (adjList[u].empty()){
             cout << indentacion << "  Nodo " << u << " no tiene vecinos." << endl;
        }
        cout << indentacion << "  Termina exploración desde " << u << " en esta rama." << endl;
    }

    // Implementación de Búsqueda en Profundidad (DFS)
    void DFS(int nodoInicio) {
        if (nodoInicio < 0 || nodoInicio >= numNodos) {
            cerr << "Error: Nodo de inicio DFS inválido." << endl;
            return;
        }
        cout << "\n--- Iniciando DFS desde el nodo " << nodoInicio << " (Recursivo) ---" << endl;
        vector<bool> visitado(numNodos, false); // Vector para marcar nodos visitados
        int pasoDFS = 1;
        DFSRecursivo(nodoInicio, visitado, pasoDFS, ""); // Llamada a la función recursiva
        cout << "\n--- DFS Finalizado ---" << endl;
        cout << "--------------------------------------------------" << endl;
    }

private:
    // Funciones auxiliares para mostrar estados
    void mostrarEstadoCola(const queue<int>& q) {
        cout << "  Estado actual de la Cola: [";
        queue<int> temp_q = q;
        while (!temp_q.empty()) {
            cout << temp_q.front();
            temp_q.pop();
            if (!temp_q.empty()) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void mostrarVisitados(const vector<bool>& visitado, const string& indentacion = "  ") {
        cout << indentacion << "Nodos Visitados hasta ahora: { ";
        bool primero = true;
        for (int i = 0; i < numNodos; ++i) {
            if (visitado[i]) {
                if (!primero) {
                    cout << ", ";
                }
                cout << i;
                primero = false;
            }
        }
        cout << " }" << endl;
    }
};


// --- Función Principal (main) para Demostración ---
int main() {
    // Crear un grafo con 6 nodos (0 a 5)
    Grafo miGrafo(6);

    // Añadir aristas para formar una estructura de ejemplo
    //     0 --- 1
    //     | \ / |
    //     |  2  | --- 3
    //     | / \ |
    //     5 --- 4
    //
    cout << "\n--- Agregando Aristas ---" << endl;
    miGrafo.agregarArista(0, 1);
    miGrafo.agregarArista(0, 2);
    miGrafo.agregarArista(0, 5); // Conexión adicional
    miGrafo.agregarArista(1, 2);
    miGrafo.agregarArista(2, 3);
    miGrafo.agregarArista(2, 4); // Conexión adicional
    miGrafo.agregarArista(3, 4); // Conexión adicional
    miGrafo.agregarArista(4, 5); // Conexión adicional para hacer un ciclo 0-5-4-2-0

    // Mostrar la estructura final del grafo
    miGrafo.mostrarLista();

    // Probar BFS comenzando desde el nodo 0
    miGrafo.BFS(0);

    // Probar DFS comenzando desde el nodo 0
    // Nota: El orden exacto de visita en DFS puede variar si los vecinos
    // no se procesan en un orden fijo (ej. si no se ordenan las listas de adyacencia)
    // pero la lógica de "profundizar primero" se mantendrá.
    miGrafo.DFS(0);
    
    // Ejemplo con un nodo de inicio diferente
    // miGrafo.BFS(3);
    // miGrafo.DFS(3);

    return 0;
}
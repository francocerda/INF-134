#include<bits/stdc++.h>

using namespace std;

class Grafo {
private:
    int V;
    vector<list<int>> adj;

public:
    Grafo(int V) {
        this->V = V;
        adj.resize(V);
    }

    void agregarArista(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        vector<bool> visitado(V, false);
        queue<int> cola;

        visitado[s] = true;
        cola.push(s);

        while (!cola.empty()) {
            s = cola.front();
            cout << s << " ";
            cola.pop();

            for (int adyacente : adj[s]) {
                if (!visitado[adyacente]) {
                    visitado[adyacente] = true;
                    cola.push(adyacente);
                }
            }
        }
    }

    void DFS(int s) {
        vector<bool> visitado(V, false);
        stack<int> pila;

        pila.push(s);

        while (!pila.empty()) {
            s = pila.top();
            pila.pop();

            if (!visitado[s]) {
                cout << s << " ";
                visitado[s] = true;
            }

            for (int adyacente : adj[s]) {
                if (!visitado[adyacente]) {
                    pila.push(adyacente);
                }
            }
        }
    }
};

int main() {
    Grafo g(4);
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 2);
    g.agregarArista(2, 0);
    g.agregarArista(2, 3);
    g.agregarArista(3, 3);

    cout << "Recorrido BFS (desde el vertice 2): ";
    g.BFS(2);
    cout << endl;

    cout << "Recorrido DFS (desde el vertice 2): ";
    g.DFS(2);
    cout << endl;

    return 0;
}
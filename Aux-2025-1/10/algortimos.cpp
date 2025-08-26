#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int>>>& adj, int start_node) {
    int n = adj.size();
    vector<int> dist(n, INF);
    dist[start_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});

    // BUCLE PRINCIPAL: Se ejecuta V veces (una por cada nodo que se finaliza).
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        // OPERACIÓN COSTOSA 1: Cuesta O(log V) extraer el mínimo de la cola de prioridad.
        // Como se hace V veces, el costo total de esta línea es V * log(V).
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        // BUCLE INTERNO: En total, a lo largo de todas las iteraciones del while,
        // este bucle for recorrerá cada arista E una sola vez.
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                // OPERACIÓN COSTOSA 2: Cuesta O(log V) insertar/actualizar en la cola de prioridad.
                // En el peor caso, se ejecuta por cada arista E.
                // Costo total de esta línea es E * log(V). Este es el término dominante.
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Distancias desde el nodo " << start_node << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Nodo " << i << ": Infinito" << endl;
        } else {
            cout << "Nodo " << i << ": " << dist[i] << endl;
        }
    }
}

void prim(const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start_node = 0;
    key[start_node] = 0;
    pq.push({0, start_node});

    int mst_weight = 0;

    // BUCLE PRINCIPAL: Al igual que en Dijkstra, se ejecuta V veces.
    while (!pq.empty()) {
        int u = pq.top().second;
        // OPERACIÓN COSTOSA 1: Idéntica a Dijkstra. Cuesta O(log V) por extracción.
        // Costo total: V * log(V).
        pq.pop();

        if (inMST[u]) {
            continue;
        }
        
        inMST[u] = true;
        mst_weight += key[u];

        // BUCLE INTERNO: También recorre cada arista E una vez en total.
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                // OPERACIÓN COSTOSA 2: Idéntica a Dijkstra. Cuesta O(log V) por inserción.
                // En el peor caso, se ejecuta E veces.
                // Costo total: E * log(V). El término dominante.
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Aristas del Árbol de Expansión Mínima (MST):" << endl;
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << endl;
        }
    }
    cout << "Peso total del MST: " << mst_weight << endl;
}

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    // Las operaciones find y unite son casi O(1) gracias a las optimizaciones
    // (path compression y union by rank/size), su costo real es O(α(V)),
    // donde α es la función inversa de Ackermann, que es prácticamente constante.
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void kruskal(vector<Edge>& edges, int n) {
    // OPERACIÓN MÁS COSTOSA: Ordenar todas las E aristas.
    // Un buen algoritmo de ordenamiento tiene una complejidad de O(N log N).
    // En este caso, N es E, por lo que el costo es O(E * log E).
    // Esta línea define la complejidad total del algoritmo.
    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(n);
    vector<Edge> result;
    int mst_weight = 0;

    // BUCLE PRINCIPAL: Se ejecuta una vez por cada arista E.
    for (const auto& edge : edges) {
        // Las operaciones find() son súper rápidas (casi O(1)), por lo que no dominan.
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            // unite() también es súper rápida.
            dsu.unite(edge.u, edge.v);
            result.push_back(edge);
            mst_weight += edge.weight;
        }
    }

    cout << "Aristas del Árbol de Expansión Mínima (MST):" << endl;
    for (const auto& edge : result) {
        cout << edge.u << " - " << edge.v << " (peso: " << edge.weight << ")" << endl;
    }
    cout << "Peso total del MST: " << mst_weight << endl;
}
    
signed main(){


    return 0;
}
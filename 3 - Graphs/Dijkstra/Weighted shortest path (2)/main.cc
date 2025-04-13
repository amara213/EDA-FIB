#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

using vertex = int;
using graph = vector<vector<pair<vertex, int>>>; // Lista de adyacencia
using P = pair<int, vertex>;                    // Distancia, vÃ©rtice

vector<int> dijkstra(const graph &g, vertex s, vector<int> &padre) {
    int n = g.size();
    vector<int> D(n, INT_MAX);        // Distancias desde el origen
    vector<bool> marked(n, false);   // Visitados
    priority_queue<P, vector<P>, greater<P>> pq;

    D[s] = 0;
    pq.push({D[s], s});
    padre[s] = -1; // El nodo origen no tiene padre

    while (!pq.empty()) {
        vertex u = pq.top().second;
        pq.pop();

        if (!marked[u]) {
            marked[u] = true;
            for (auto i : g[u]) {
                vertex neigh = i.first;
                int peso = i.second;
                if (D[neigh] > D[u] + peso) {
                    D[neigh] = D[u] + peso;
                    padre[neigh] = u; // Actualizar el padre del nodo vecino
                    pq.push({D[neigh], neigh});
                }
            }
        }
    }
    return D;
}

void print_path(vector<int> &padre, int destino) {
    vector<int> path;
    while (destino != -1) { 
        path.push_back(destino);
        destino = padre[destino];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        if (i == path.size()-1) cout << path[i];
        else cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        graph g(n);
        for (int k = 0; k < m; ++k) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back({v, c});
        }
        vertex x, y;
        cin >> x >> y;

        vector<int> padre(n, -1); // Vector para guardar los padres
        vector<int> D = dijkstra(g, x, padre);

        if (D[y] == INT_MAX)
            cout << "no path from " << x << " to " << y << endl;
        else {
            print_path(padre, y);
        }
    }
}
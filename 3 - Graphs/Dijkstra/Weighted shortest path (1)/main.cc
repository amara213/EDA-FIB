#include<limits.h>

using namespace std;

using vertex = int;
using graph = vector<vector<pair<vertex,int>>>;// for the adjacency list of a weighted directed graph
using P = pair<int,vertex>; //distance, vertex

vector<int> dijkstra(const graph& g, vertex s){
    int n = g.size();
    vector<int> D(n, INT_MAX);//for all the distances from s
    vector<bool> marked(n,false);//for the visited vertices
    priority_queue<P,vector<P>, greater<P>> pq;

    D[s] = 0;
    pq.push({D[s], s});

    while (not pq.empty()) {
        vertex u = pq.top().second;
        pq.pop();

        if(not marked[u]) {
            marked[u] = true;
            for(auto i : g[u]) {
                vertex neigh = i.first;
                int peso = i.second;
                if(D[neigh] > D[u] + peso) {
                    D[neigh] = D[u] + peso;
                    pq.push({D[neigh], neigh});
                }

            }
        }
    }

return D;
}


int main(){
    int n, m;
    while(cin >> n >> m){
        graph g(n);
        for (int k = 0; k < m; ++k){
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back({v,c});
        }
        vertex x, y;
        cin >> x >> y;
        vector<int> D = dijkstra(g, x);
        if (D[y] == INT_MAX) cout << "no path from " << x << " to " << y << endl;
        else cout << D[y] << endl;
    }
}
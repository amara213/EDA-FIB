#include <iostream>
#include <vector>
#include <queue>


using namespace std;


bool pasa(int x, int y, const vector<vector<char> >& mapa) {
    return (x >= 0 and x < int(mapa.size()) and y >= 0 and y < int(mapa[0].size()) and mapa[x][y] != 'X');
}

int distancia_minima(int origX, int origY, vector<vector<char> >& mapa) {
    int filas = mapa.size();
    int columnas = mapa[0].size();
         int mayor = -1;
    queue<pair<int, int>> Q;
    vector<vector<int>> dist(filas, vector<int>(columnas, -1));
    Q.push({origX, origY});
    dist[origX][origY] = 0; 
    
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        
        if (mapa[x][y] == 't') {
            mayor = dist[x][y];
        }
        if (pasa(x + 1, y, mapa) and dist[x+1][y] == -1) {
            Q.push({x + 1, y});
            dist[x + 1][y] = dist[x][y] + 1;
        }
        if (pasa(x - 1, y, mapa) and dist[x-1][y] == -1) {
            Q.push({x - 1, y});
            dist[x - 1][y] = dist[x][y] + 1;
        }
        if (pasa(x, y + 1, mapa) and dist[x][y+1] == -1) {
            Q.push({x, y + 1});
            dist[x][y + 1] = dist[x][y] + 1;
        }
        if (pasa(x, y - 1, mapa) and dist[x][y-1] == -1) {
            Q.push({x, y - 1});
            dist[x][y - 1] = dist[x][y] + 1;
        }
    }
    return mayor;  
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> mapa(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapa[i][j];
        }
    }
    
    int origX, origY;
    cin >> origX >> origY;  
    --origX;
    --origY;

    int dist = distancia_minima(origX, origY, mapa);
    
    if(dist == -1) cout << "no es pot arribar a cap tresor"; 
	else cout << "distancia maxima: " << dist;
	cout << endl;
}
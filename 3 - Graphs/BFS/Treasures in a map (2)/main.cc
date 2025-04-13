#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


bool pasa(int x, int y, const vector<vector<char> >& mapa) {
    return (x >= 0 and x < int(mapa.size()) and y >= 0 and y < int(mapa[0].size()) and mapa[x][y] != 'X');
}

int distancia_minima(int origX, int origY, vector<vector<char> >& mapa) {
    int filas = mapa.size();
    int columnas = mapa[0].size();
    
    queue<pair<int, int>> Q;
    vector<vector<int>> dist(filas, vector<int>(columnas, -1));
    
    Q.push({origX, origY});
    dist[origX][origY] = 0; 
    
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        
        if (mapa[x][y] == 't') {
            return dist[x][y];
        }

        mapa[x][y] = 'X';
        

        if (pasa(x + 1, y, mapa) and mapa[x + 1][y] != 'X') {
            Q.push({x + 1, y});
            dist[x + 1][y] = dist[x][y] + 1;
        }
        if (pasa(x - 1, y, mapa) and mapa[x - 1][y] != 'X') {
            Q.push({x - 1, y});
            dist[x - 1][y] = dist[x][y] + 1;
        }
        if (pasa(x, y + 1, mapa) and mapa[x][y + 1] != 'X') {
            Q.push({x, y + 1});
            dist[x][y + 1] = dist[x][y] + 1;
        }
        if (pasa(x, y - 1, mapa) and mapa[x][y - 1] != 'X') {
            Q.push({x, y - 1});
            dist[x][y - 1] = dist[x][y] + 1;
        }
    }
    
    return -1;  
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> mapa(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapa[i][j];  // Cargar el mapa
        }
    }
    
    int origX, origY;
    cin >> origX >> origY;  
    --origX;
    --origY;
    
    int dist = distancia_minima(origX, origY, mapa);
    
    if(dist == -1) cout << "no es pot arribar a cap tresor"; 
	else cout << "distancia minima: " << dist;
	cout << endl;
}
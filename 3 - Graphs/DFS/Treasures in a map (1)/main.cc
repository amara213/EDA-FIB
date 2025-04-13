#include <iostream>
#include <vector>

using namespace std;
typedef vector <vector<char>> GridGraph;

GridGraph read_grid_graph(int n, int m){
    GridGraph G(n+2, vector<char>(m+2, 'X')); 
    for (int i = 1; i <= n; ++i) {
         for (int j = 1; j <= m; ++j)
            cin >> G[i][j];
    }
       
    return G;
}


bool dfs(const GridGraph& G, vector<vector<bool>>& visited, int i, int j) {
    
    if (not visited[i][j]) {
        if (G[i][j] == 't') return true;
         visited[i][j] = true;
        if (G[i-1][j] != 'X' and  not visited[i-1][j]) // up
            if (dfs(G, visited, i-1, j)) return true;
        
        if (G[i][j+1] != 'X' and not visited[i][j+1]) // right
            if (dfs(G, visited, i, j+1)) return true;
        
        if (G[i+1][j] != 'X' and  not visited[i+1][j]) // down
            if (dfs(G, visited, i+1, j)) return true;
        
        if (G[i][j-1] != 'X' and not visited[i][j-1]) // left
            if (dfs(G, visited, i, j-1)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    GridGraph abc = read_grid_graph(n, m);

    int r, c;
    cin >> r >> c;

    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));


    if (dfs(abc, visited, r, c)) 
        cout << "yes" << endl;
    else 
        cout << "no" << endl;


}
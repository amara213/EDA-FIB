#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<char,bool>> Fila;
typedef vector<vector<pair<char,bool>> > Matriu;


void dfs(Matriu& mat, int i, int j, int &tesoro) {
    
    if (!mat[i][j].second) {
        if (mat[i][j].first == 't') {
            ++tesoro;
        }
         mat[i][j].second = true;
        if (mat[i-1][j].first != 'X' and  !mat[i-1][j].second) // up
            (dfs(mat, i-1, j, tesoro)); 
        
        if (mat[i][j+1].first != 'X' and  !mat[i][j+1].second) // rimatht
          (dfs(mat, i, j+1, tesoro)); 
        
        if (mat[i+1][j].first != 'X' and   !mat[i+1][j].second) // down
             (dfs(mat, i+1, j, tesoro));
        
        if (mat[i][j-1].first != 'X' and  !mat[i][j-1].second) // left
            (dfs(mat, i, j-1, tesoro));
    }
  
}

int main() {
    int n, m;
    cin >> n >> m;
    Matriu mat(n + 2, Fila(m + 2, {'X', false}));
    for (int i = 1; i <= n; ++i) {
         for (int j = 1; j <= m; ++j) {
            cin >> mat[i][j].first;
         }
    }

    int tesoro = 0;
    int r, c;
    cin >> r >> c;

        dfs(mat,r,c,tesoro);
        cout << tesoro << endl;



}
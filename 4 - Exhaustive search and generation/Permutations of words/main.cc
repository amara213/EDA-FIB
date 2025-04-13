#include <iostream>
#include <vector>
#include <string>

using namespace std;

void write (const vector<string> & v){
    cout << '(';
    cout << v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i)
        cout << "," << v[i];
         cout << ')';
    cout << endl;
}

void backtrack(vector<string>& sol, int k,vector<pair<string,bool>>& used){
    if (k == sol.size()) {
        write(sol);
    }
    else {
        for (int i = 0; i < used.size(); i++) {
            if (not used[i].second) {
            sol[k] = used[i].first;
             used[i].second = true;
            backtrack(sol, k+1, used);
            used[i].second = false;
           
            }
            
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> sol(n);
    vector<pair<string,bool>> used(n); 
    for (int i = 0; i < n; i ++) {
        cin >> used[i].first;
        used[i].second = false;
    }
    backtrack(sol, 0, used);

}
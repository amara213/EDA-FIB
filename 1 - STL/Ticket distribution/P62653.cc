#include<iostream>
#include<vector>

using namespace std;

void write (const vector<int> & v){
    cout << '(';
    cout << v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i)
        cout << "," << v[i];
         cout << ')';
    cout << endl;
}

void backtrack(vector<int>& sol, int k,vector<bool>& used){
    if (k == sol.size()) {
        write(sol);
    }
    else {
        for (int i = 0; i < used.size(); i++) {
            if (not used[i]) {
            sol[k] = i+1;
             used[i] = true;
            backtrack(sol, k+1, used);
            used[i] = false;
           
            }
            
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> sol(n);
    vector<bool> used(n, false); 
    backtrack(sol, 0, used);

}
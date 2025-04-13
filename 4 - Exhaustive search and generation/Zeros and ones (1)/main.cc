// Zeros and ones (1)
#include<iostream>
#include<vector>

using namespace std;

void write (const vector<bool> & v){
    cout << v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i)
        cout << " " << v[i];
    cout << endl;
}

void backtrack(vector<bool>& sol, int k){
 if (k == sol.size()) {
    write(sol);
 }
 else {
    sol[k] = false;
    backtrack(sol, k+1);
    sol[k] = true;
    backtrack(sol, k+1);
    
 }
}

int main(){
    int n;
    cin >> n;
    vector<bool> sol(n,false);
    backtrack(sol, 0);
}
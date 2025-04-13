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

void backtrack(vector<bool>& sol, int k, int zeros, int ones){
if (k == sol.size()) {
    write(sol);
}
else {
    sol[k] = false;
    if (zeros > 0) {
        backtrack(sol, k+1, zeros -1, ones);
    }
    sol[k] = true;
        if (ones > 0) {
        backtrack(sol, k+1, zeros, ones-1);
    }
}
}

int main(){
    int n;
    cin >> n;
    int o;
    cin >>o;
    vector<bool> sol(n);
    backtrack(sol, 0, n-o, o);

}
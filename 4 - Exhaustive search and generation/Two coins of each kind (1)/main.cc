// Two coins of each kind (3)
#include<iostream>
#include<vector>

using namespace std;

int x, n;
vector<int> coins;//eventually n will be coins.size()
using VI = vector<int>;
using VB = vector<bool>;

void write(VB &sol, VI& x) {
    cout << "{";
    bool first = true;
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i]) { 
            if (!first) cout << ","; 
            cout << x[i];
            first = false; 
        }
    }
    cout << "}" << endl;
}

void bt(int k, int part_sum, VB& sol, VI& x, int s){
   int n = x.size();
   if (k == n) {
    if (part_sum == s) {
        write(sol, x);
    }
   }
   else {
    if (!sol[k]) {
            sol[k] = true;
    bt(k+1, part_sum + x[k], sol, x, s);
     sol[k] = false;
    }
    bt(k+1, part_sum, sol, x, s);

   }
}

int main(){
    int s, n;
    cin >> s >> n;
    VI values(n); 
    for (int i = 0; i < n; ++i){
        cin >> values[i];
    }
    VB sol(n);
    bt(0, 0, sol, values, s);
}
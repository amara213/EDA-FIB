#include <iostream>
#include <vector>
using namespace std;

void magia(vector<bool> &f, vector<bool> &dp, vector<bool> &ds, int i, int n, int& cont){
    if(i == n){ 
        ++cont;
    }
    else{

        for(int j=0; j<n; ++j){ 
            if(!f[j] and !ds[j+i] and !dp[i-j+n-1]){ 
                f[j] = true;
                ds[i+j] = true;
                dp[i-j+n-1] = true;
                magia(f, dp, ds, i+1, n, cont);
                f[j] = false;
                ds[i+j] = false;
                dp[i-j+n-1] = false;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<bool> f(n, false);
    vector<bool> diagonals_p(2*n-1, false);
    vector<bool> diagonals_s(2*n-1, false);
    int cont = 0;
    magia(f, diagonals_p, diagonals_s, 0, n, cont);
    cout <<  cont << endl;
}
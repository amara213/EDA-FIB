#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



void backtrack(int acc_sum, int k, vector<int>& used, vector<int>& monedas, int x, int& count) {
    if (acc_sum == x) {
        ++count;
    } else if (k < monedas.size() && acc_sum < x) {

        if (used[k] < 2) {
            ++used[k];
            backtrack(acc_sum + monedas[k], k, used, monedas, x, count);
            --used[k];
        }

        backtrack(acc_sum, k + 1, used, monedas, x, count);
    }
}

int main() {
    int n, x;
    while (cin >> x >> n) {
        vector<int> monedas(n);
        for (int i = 0; i < n; ++i) {
            cin >> monedas[i];
        }
        sort(monedas.begin(), monedas.end());

        vector<int> used(n, 0); 
        int count = 0;
        backtrack(0, 0, used, monedas, x, count);
        cout << count << endl;
    }
}
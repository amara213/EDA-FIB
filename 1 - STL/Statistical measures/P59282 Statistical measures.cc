#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    map<int, int> m;
    string command;
    double total = 0.0, mid = 0.0;
    int unidades = 0;


    while (cin >> command) {
        if (command == "number") {
            int n;
            cin >> n; 
            ++m[n];
            ++unidades;
            total += n;
            mid = total / unidades;
        
        } 
        else if (command == "delete") {
            if (!m.empty()) {
        auto it = m.begin();
        if (it->second > 1) {
            --it->second;
        } else {
            m.erase(it);
        }
        --unidades;
        total -= it->first;
        if (unidades > 0) {
            mid = total / unidades;
        } else {
            mid = 0.0;
        }
    }
}
  if (!m.empty()) {
            auto it_min = m.begin();
            auto it_max = --m.end();
            cout << "minimum: " << it_min->first 
                 << ", maximum: "  << it_max->first 
                 << ", average: " << fixed << setprecision(4) << mid << endl;
  }
  else cout << "no elements" << endl;
    } 
}
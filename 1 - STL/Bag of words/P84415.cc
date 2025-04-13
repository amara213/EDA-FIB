#include <map>
#include <iostream>
#include <map>

using namespace std;

void maxi(map<string, int> &mapa) {
auto it = --mapa.end();
cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
}

void mini(map<string, int> &mapa) {
auto it = mapa.begin();
cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
}


int main() {
    map<string, int> mapa;
    string s;
    while (cin >> s) {
        if (s == "store") {
            string w;
            cin >> w;
            ++mapa[w];
        }
        else if (s == "minimum?") {
            if (mapa.empty()) cout << "indefinite minimum" << endl;
            else {
                mini(mapa);
            }    
        }
        else if (s == "maximum?") {
            if (mapa.empty()) cout << "indefinite maximum" << endl;
            else {
                maxi(mapa);
            }    
        }
        else if (s == "delete") {
            string w;
            cin >> w;
            auto it = mapa.find(w);

            if (it != mapa.end()) {
                if (it->second > 1) --mapa[w];
                else mapa.erase(w);
            }
    
        }
    }
}
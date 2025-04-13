#include <map>
#include <iostream>

using namespace std;

int main() {

string act; 
string name;
map<string, int> mapa;

while (cin >> name >> act) {
if (act == "enters") {
    map<string,int>::iterator it = mapa.find(name);
    if (it != mapa.end()) cout << name << " is already in the casino" << endl;
    else mapa[name] = 0;
}
else if (act == "wins") {
    int n;
    cin >> n;
    map<string,int>::iterator it = mapa.find(name);
    if (it != mapa.end()) mapa[name] += n;
    else cout << name << " is not in the casino" << endl;
}
else if (act == "leaves") {
    map<string,int>::iterator it = mapa.find(name);
    if (it != mapa.end()) {
        cout << name << " has won " << mapa[name] << endl;
        mapa.erase(name);
    }
    else cout << name << " is not in the casino" << endl;   
}

}
cout << "----------" << endl;
for (map<string,int>::iterator it = mapa.begin(); it != mapa.end(); ++it) {
    cout << it->first << " is winning " << it->second << endl;
}
}
#include<iostream>
#include<set>
using namespace std;

int main() {
  set<string> s;
  string elem;
  auto mitjana = s.begin();
  while (cin >> elem and elem != "END") {
    auto it = s.insert(elem).first;
    if (mitjana == s.end()) mitjana = it;
    else if (s.size() % 2 == 0 and elem < *mitjana) mitjana--;
    else if (s.size() % 2 != 0 and elem > *mitjana) mitjana++;
    cout << *mitjana << endl;
  }
}

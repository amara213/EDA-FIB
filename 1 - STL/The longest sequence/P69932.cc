#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main() {
string s;
 while (getline(cin, s)) {
        istringstream iss(s);  
        int num, cont = 0;
        set<int> numbers;

        while (iss >> num) {
            numbers.insert(num);  
        }

        auto it = numbers.begin();
        int last;

        if (!numbers.empty()) {
            last = *it;
            ++it;
            ++cont;
        }

        for (it = numbers.begin(); it != numbers.end(); ++it) {
            if ((*it%2 == 0 and last%2 != 0) or (*it%2 != 0 and last%2 == 0)) ++cont;
			last = *it;
        }
        cout << cont << endl;

}
}
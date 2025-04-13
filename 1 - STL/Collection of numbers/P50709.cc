#include <queue>
#include <iostream>
using namespace std;
int main() {
priority_queue<int> pq;
int x;
char c;
while (cin >> c) {
    if (c == 'S') { 
            cin >> x;
            pq.push(x);
        }
    else if (c == 'A') { 
            if (!pq.empty()) {
                cout << pq.top() << endl;
            }
            else cout << "error!" << endl;
        }
    else if (c == 'R') {  
            if (!pq.empty()) {
            pq.pop(); 
        }
         else cout << "error!" << endl; 
        }
    else if (c == 'I') {  
            if (!pq.empty()) { 
                cin >> x;
                int num = pq.top();
                num = x + num;
                pq.pop();
                pq.push(num);
            }
            else cout << "error!" << endl;
        }
     else if (c == 'D') { 
             if (!pq.empty()) { 
                cin >> x;
                int num = pq.top();
                num = num - x;
                pq.pop();
                pq.push(num);
            }
            else cout << "error!" << endl;
        }
}

 }
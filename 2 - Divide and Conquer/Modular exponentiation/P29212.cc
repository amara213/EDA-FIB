#include <iostream>
using namespace std;


int expeasy(int n, int k, int m) {
  if (k == 0) return 1; // n^0 = 1
  if (n == 0) return 0; // 0^k = 0

  int res;
   if (k % 2 == 0) {
    res = expeasy(n, k / 2, m);
    res = (res * res) % m;
  } else {
     res = n % m;
    res = (res * expeasy(n, k - 1, m) % m) %m;
  }


  return (res + m) % m;
}


int main() {
  int n, k, m;
  while (cin >> n >> k >> m)
    cout << expeasy(n, k, m) << endl;
}

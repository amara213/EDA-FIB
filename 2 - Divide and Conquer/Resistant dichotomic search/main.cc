#include <iostream>
#include <vector>


using namespace std;




bool resistant_search(double x, const vector<double>& v, int left, int right) {
    if (left > right) return false;
    if (left + 1 >= right) return x == v[left] or x == v[right];
    int mid = (left+right)/2;
    if (v[mid] > x) return v[mid+1] == x or resistant_search(x, v, left, mid-1);


    else if(v[mid] < x) return v[mid-1] == x or resistant_search(x, v, mid+1, right);
    else return true;
}

bool resistant_search(double x, const vector<double>& v) {
    return  resistant_search(x, v, 0, v.size()-1);
}
#include<iostream>
#include<vector>
#include <string>

using namespace std;


// first cons, sec vocals
void backtrack(string sol, int k, vector<pair<bool, bool>>& used, vector<char>& cons, vector<char>& vowels){
    if (k == (cons.size())*2) {
        cout << sol << endl;
    }
    else {
            string temp;
            if (k == 0) {
                for (int j = 0; j < cons.size(); ++j ){
				if (not used[j].first){
					used[j].first = true;
                    temp = sol + cons[j];
					backtrack(temp, k+1, used, cons, vowels);
					used[j].first = false;
				}
			}
            }
            else {
          
                if (k%2 == 0) {
                    for (int j = 0; j < vowels.size(); ++j ){
                    if (not used[j].first){
					used[j].first = true;
                    temp = sol + cons[j];
					backtrack(temp, k+1, used, cons, vowels);
					used[j].first = false;
                    }
				}
                }
                else {
                    for (int j = 0; j < vowels.size(); ++j ){
                    if (not used[j].second){
            
					used[j].second = true;
                    temp = sol + vowels[j];
					backtrack(temp, k+1, used, cons, vowels);
					used[j].second = false;
				}
                    }
                    
                }
					         
        }
    }
}



int main(){
    int  n;
    cin >> n;

   vector<pair<bool, bool>> used(n, make_pair(false, false)); 

   vector<char> cons(n); 
   vector<char> vowels(n); 

    for (int i = 0; i < n; ++i){
        cin >> cons[i];
    }

     for (int i = 0; i < n; ++i){
        cin >> vowels[i];
    }
    backtrack("", 0, used, cons, vowels);

}
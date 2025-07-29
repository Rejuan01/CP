#include<bits/stdc++.h>
using namespace std;
int factorialMod(int n, int x) {
    //if (x == 6 && n >= 6) return 0; 
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact = (fact * i) % x;
    }
    return fact;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> result;
        result.push_back(1);
        if(n >= 3 || !(d%3)){
            result.push_back(3);
        }
        if(d == 0 || d == 5){
            result.push_back(5);
        }
        if((n==2 && d == 7) || n >=3){
            result.push_back(7);
        }
        
        if(n >= 6){
            result.push_back(9);
        }
        else{
            long long  s = factorialMod(n, 9);
            s = (s%9 * d%9)%9;
            if(s == 0){
                result.push_back(9);
            }
        }
        for(auto it: result){
            cout << it << " ";
        }
        cout << endl;

    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int profit = 0;
    for(int i = 0; i < n-1; i++){
        int p = x[i] - x[i+1] - c;
        //cout << p << " ";
        if(profit < p){
            profit = p;
        }
    }
    cout << profit << endl;
}
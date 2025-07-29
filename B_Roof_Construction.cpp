#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k = 0; // will store max position of '1'
        int p = n-1;
        while(p/2){
            k++;
            p /= 2;
        }
        int x = pow(2, k); // cannot minimize xor below 2^k
        vector<int> ans;
        for(int i = n-1; i >= x; i--){
            ans.push_back(i);
        } ans.push_back(0);
        for(int i = 1; i < x; i++){
            ans.push_back(i);
        }
        for(int it: ans){
            cout << it << " ";
        } cout << endl;
    }
}
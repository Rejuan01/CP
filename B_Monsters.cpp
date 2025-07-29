#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main(){
    int t;
    cin >> t;
    while(t--){
        lli n, k;
        cin >> n >> k;
        vector<pair<lli, int>> v;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            x = x%k;
            if(x == 0) x = k;
            v.push_back({x, i+1});
        }
        stable_sort(v.begin(),v.end(), [](const pair<lli, int>& a, const pair<lli, int>& b){
            return a.first > b.first;  
        });
        for(const auto &[a, index] : v){
            cout << index << " ";
        }
        cout << endl;
    }
}
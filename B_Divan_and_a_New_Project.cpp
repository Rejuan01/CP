#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            v.push_back({temp, i+1});
        }
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });
        vector<int> ans(n+1, 0);
        int coord = 1;
        lli time = 0;
        for(auto it = v.begin(); it != v.end(); ++it){
            ans[it->second] = coord;
            time += 2LL*coord*(it->first);
            it++;
            if(it != v.end()) ans[it->second] = (-1)*coord;
            if(it == v.end()) break;
            time += 2LL*coord*(it->first);
            coord++;
        }
        cout << time << endl;
        for(int it: ans){
            cout << it << " ";
        } cout << endl;
    }
}
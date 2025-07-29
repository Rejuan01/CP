#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, p;
        cin >> n >> p;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].second; // frequency
        }
        for(int i = 0; i < n; i++){
            cin >> v[i].first; // cost
        }
        sort(v.begin(), v.end());
        auto it = v.begin();
        if(it->first >= p){ // initial cost <= minimum
            cout << 1LL*n*p << endl;
            continue;
        }
        int count = 1;
        long long int cost = p; // One with lowest cost is informed
        for(const auto &[cst, f]: v){
            if(cst > p || count == n) break;
            if(count+f > n){
                cost += 1LL*cst*(n-count);
                count = n;
            }
            else{
                count += f;
                cost += 1LL*f*cst;
            }
        }
        if(count < n){
            cost += 1LL*p*(n-count);
        }
        cout << cost << endl;
    }
}
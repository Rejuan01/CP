#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main(){
    int t;
    cin >> t;
    while(t--){
        lli n, k, b;
        lli s;
        cin >> n >> k >> b >> s;
        lli p = s - k*b;
        if(p < 0 || p > (k-1)*n){
            cout << -1 << endl;
            continue;
        }
        //cout << n << endl;
        vector<lli> ans(n, 0);
        if(p == n*(k-1)){ // maximum possibe value of p
            ans[0] = k*b + (k-1);
            p -= (k-1);
        }else{
            ans[0] = k*b + p%(k-1);
            p -= p%(k-1);
        }
        for(int i = 1; i < n && i <= p/(k-1); i++){
            ans[i] = k-1;
        }
        for(auto it = ans.rbegin(); it != ans.rend(); ++it){
            cout << *it << " "; 
        } cout << endl;
    }
}
// 1000000000000000000
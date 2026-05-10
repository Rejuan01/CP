#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n){
    map<ll, ll> mp;
    for(ll i = 2; i*i <= n; i++){
        while(n%i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if(n > 1) mp[n]++;
    for(auto &x : mp){
        cout << x.first << "^" << x.second << " ";
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    while (1) {
        cin >> n;
        if(n == 0) break;
        solve(n);
    }
    return 0;
}
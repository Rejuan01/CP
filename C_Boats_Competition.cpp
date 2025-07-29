#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi c(n+1), s(2*n+1), v;  // frequency, sum's frequency, distinct values
    for(ll i = 1; i <= n; i++){
        ll temp;
        cin >> temp;
        if(c[temp] == 0){
            v.push_back(temp);
        }
        c[temp]++;
    }
    for(ll i = 0; i < v.size(); i++){
        ll p = c[v[i]];
        if(p > 1){
            s[2*v[i]] += p/2;
        }
        for(ll j = i+1; j < v.size(); j++){
            ll x = min(c[v[i]], c[v[j]]); 
            s[v[i]+v[j]] += x;
        }
    }
    ll x = *max_element(s.begin(), s.end());
    cout << x << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
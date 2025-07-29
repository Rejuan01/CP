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
    vi c;
    ll count = 0;
    for(ll i = 0; i < n; i++){
        ll temp; 
        cin >> temp;
        count += temp;
        c.push_back(count);
    }
    ll m;
    cin >> m;
    while(m--){
        ll x; 
        cin >> x;
        ll p = lower_bound(c.begin(), c.end(), x) - c.begin();
        cout << p+1 << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
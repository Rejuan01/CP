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
    ll n, m;
    cin >> n >> m;
    multiset<ll> a;
    vi b(n);
    a.insert(m);
    for(ll i = 1; i < n; i++){
        ll x; cin >> x;
        a.insert(x);
    }
    for(ll i = 0; i < n; i++) cin >> b[i];
    sort(b.begin(), b.end(), greater<ll>());
    for(auto x: b){
        auto it = a.lower_bound(x);
        if(it == a.begin()) break;
        --it;
        a.erase(it);
    }
    cout << a.size() << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
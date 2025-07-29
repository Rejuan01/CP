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
    vi a(n), b;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++){
        if(a[i] != a[i+1]){
            b.push_back(i);
        }
    }
    ll q;
    cin >> q;
    for(ll i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll x = lower_bound(b.begin(), b.end(), l) - b.begin();
        if(x < b.size() && b[x] < r){
            cout << b[x]+1 << " " << b[x]+2 << endl;
        }
        else{
            cout << -1 << " " << -1 << endl;
        }
    } cout << endl;
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
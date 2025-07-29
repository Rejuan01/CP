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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll p = 1, q = n-2;
    while(p < q){
        ll x = 0, y = 0;
        if(a[p] == a[p-1]) x++;
        if(a[q] == a[q+1]) x++;
        if(a[p] == a[q+1]) y++;
        if(a[q] == a[p-1]) y++;
        if(x > y) swap(a[p], a[q]);
        p++; q--;
    }
    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        if(a[i] == a[i+1]) ans++;
    }
    cout << ans << endl;
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
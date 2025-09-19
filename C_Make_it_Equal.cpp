#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        x = x%k;
        a[i] = min(x, k-x);
    }
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        x = x%k;
        b[i] = min(x, k-x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a == b){
        yes;
    }else no;

    
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
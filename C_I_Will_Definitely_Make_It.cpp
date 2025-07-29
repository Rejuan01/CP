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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi b;
    ll x = a[k-1];
    b.push_back(x);
    for(auto it: a){
        if(it > x) b.push_back(it);
    }
    sort(b.begin(), b.end());
    ll h = 0;
    for(ll i = 0; i < b.size()-1; i++){
        ll z = (b[i+1]-b[i]);
        ll y = b[i]-h;
        if(y < z){
            no; return;
        }
        h += z;
    }
    yes;
    
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
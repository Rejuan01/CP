#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n, x;
    cin >> n >> x;
    ll y = 0;
    vi a(n), b(n), c(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    for(ll i = 0; i < n; i++) cin >> c[i];
    ll p = 0, q = 0, r = 0;
    while(p < n || q < n || r < n){
        if(y == x){
            yes; return;
        }
        if(p < n && (a[p]|x) == x){ // Where a[p] is set, x is also set
            y |= a[p++];
        }else if(q < n && (b[q]|x) == x){
            y |= b[q++];
        }else if(r < n && (c[r]|x) == x){
            y |= c[r++];
        }else{
            no; return;
        }
    }
    if(y == x) yes;
    else{ // read all but did not reach x
        no;
    }
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
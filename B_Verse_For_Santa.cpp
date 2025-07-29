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
    ll n, s;
    cin >> n >> s;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll index = 0, mx = 0;
    ll p = 0, sm = 0;
    while(p < n && sm+a[p] <= s){
        sm += a[p];
        if(a[p] > mx){
            mx = a[p];
            index = p;
        }
        p++;
    }
    if(p == n){
        cout << 0 << endl;
        return;
    }
    if(a[p] < a[index]){
        cout << index+1 << endl;
    }else{
        cout << p+1 << endl;
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
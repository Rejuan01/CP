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
    ll oneCount = 0;
    for(ll i = 0; i < n; i++) cin >> a[i];
    if(n == k){
        ll index = 1;
        for(ll i = 1; i < n; i+=2){
            if(a[i] != index){
                cout << index << endl; return;
            } index++;
        }
        cout << n/2 + 1 << endl; return;
    }
    for(ll i = 1; i <= n-k+1; i++){
        if(a[i] != 1){
            cout << 1 << endl; return;
        }
    }
    cout << 2 << endl;
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
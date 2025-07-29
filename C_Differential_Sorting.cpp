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
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    if(is_sorted(a.begin(), a.end())){
        cout << 0 << endl; return;
    }
    if(a[n-2] > a[n-1]){
        cout << -1 << endl;
        return;
    }
    if(a[n-1] < 0){
        cout << -1 << endl; return;
    }
    cout << n-2 << endl;
    for(ll i = 1; i < n-1; i++){
        cout << i << " " << n-1 << " " << n << endl;
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
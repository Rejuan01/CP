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
    vi a(n+1, -1);
    bool flag = 0;
    for(ll i = 1; i <= n; i++){
        cin >> a[i]; 
        if(abs(a[i]-a[i-1]) <= 1) flag = true;
    }
    if(flag){
        cout << 0 << endl;
        return;
    }
    for(ll i = 1; i <= n-2; i++){ 
        // if any segment is not directly increasing or decreansing 
        if(a[i] < a[i+1] && a[i+1] > a[i+2]){
            cout << 1 << endl; return;
        }
        if(a[i] > a[i+1] && a[i+1] < a[i+2]){
            cout << 1 << endl; return;
        }
    }
    cout << -1 << endl;
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
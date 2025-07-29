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
    ll a[n][n];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++) 
            cin >> a[i][j];
    }
    bool c[2*n+1] = {false};
    vi p(n+1);
    for(ll i = 0; i < n; i++){
        //cout << i << " " << a[0][i] << endl;
        p[i+1] = a[0][i];
        c[a[0][i]] = true;
    }
    for(ll i = 1; i < n; i++){
        p.push_back(a[i][n-1]);
        c[a[i][n-1]] = true;
    }
    for(ll i = 1; i <= 2*n; i++){
        if(c[i] == false){
            p[0] = i; break;
        }
    }
    for(auto it: p){
        cout << it << " ";
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
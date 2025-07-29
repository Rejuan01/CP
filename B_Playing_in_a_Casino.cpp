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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll res = 0;
    for(ll j = 0; j < m; j++){
        vi v;
        ll sum = 0, sum2 = 0;
        for(ll i = 0; i < n; i++){
            v.push_back(a[i][j]);
            sum += a[i][j]; // sum of column j
        }
        sort(v.begin(), v.end()); // sort column j
        for(ll i = 0; i < n; i++){
            sum2 += v[i]; // sum from 0 to current index
            ll x = sum - sum2; // sum of right elements
            x = x - (n-i-1)*v[i]; // total difference between v[i] and any right side element
            res += x; 
        }
    }
    cout << res << endl;
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
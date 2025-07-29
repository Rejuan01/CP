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
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 2){
        cout << a[0]+a[1] << endl; return;
    }
    if(k == 1){
        ll m = INT_MIN;
        for(ll i = 1; i < n-1; i++)  m = max(m, a[i]);
        m += (max(a[0], a[n-1]));
        m = max(m, a[0]+a[n-1]);
        cout << m << endl;
        return;
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll cost = 0;
    for(ll i = 0; i < k+1; i++){
        cost += a[i];
    }
    cout << cost << endl;
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
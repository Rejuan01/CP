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
    cin >> n;
    vi a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    vi x(m), y(m);
    for(ll i = 0; i < m; i++) cin >> x[i] >> y[i];
    sort(a.begin(), a.end());
    for(ll i = 0; i < m; i++){
        ll index = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
        if(index == n){
            ll ans = x[i]-a[n-1];
            if(sum-a[n-1] < y[i]){
                ans += y[i] - (sum - a[n-1]);
            }
            cout << ans << endl; continue;
        }
        ll p = sum - a[index];
        ll cost = max(0LL, (y[i]-p));
        if(index == 0){
            cout << cost << endl; continue;
        }
        index--;
        p = sum - a[index];
        ll cost1 = x[i]-a[index];
        cost1 += max(0LL, (y[i]-p));
        cout << min(cost, cost1) << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
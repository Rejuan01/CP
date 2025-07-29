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
    vi last(k, -1); // start from -1 position
    vi max_step(k), max2_step(k); // max and 2nd max steps for k colors
    for(ll i = 0; i < n; i++){
        ll step = i - last[a[i]-1]; // current position - last position (for color a[i])
        last[a[i]-1] = i;   
        if(step > max_step[a[i]-1]){
            max2_step[a[i]-1] = max_step[a[i]-1];
            max_step[a[i]-1] = step;
        }
        else if(step > max2_step[a[i]-1]){
            max2_step[a[i]-1] = step;
        }
    }
    for(ll i = 0; i < k; i++){
        ll step = n - last[i]; // last step(out of bridge) from last position
        if(step > max_step[i]){
            max2_step[i] = max_step[i];
            max_step[i] = step;
        }
        else if(step > max2_step[i]){
            max2_step[i] = step;
        }
    }
    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i < k; i++){
        ll m = max((max_step[i]+1)/2, max2_step[i]); // max step for color i+1
        ans = min(ans, m);
    }
    cout << ans-1 << endl;
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
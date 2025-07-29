#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll c = 0;
void solve(){
    ll n;
    cin >> n;
    vi a(n+1);
    vector<vi> v(n+1, vi(32, 0)); 
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        ll x = a[i];
        for(ll j = 0; j < 32; j++){ // prefix sum of j th set bit till i th number
            v[i][j] = v[i-1][j];
            if(x&1) v[i][j]++;
            x >>= 1;
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll l, k;
        cin >> l >> k;
        ll l1 = l, r1 = n+1;
        while(l1 + 1 < r1){
            ll mid = (l1+r1)/2;
            ll s = 0;        // AND from l to mid
            for(ll j = 0; j < 32; j++){
                if(v[mid][j] - v[l-1][j] == mid-l+1){
                    s += (1<<j);
                }
            }
            if(s >= k){
                l1 = mid;
            }else r1 = mid;
        }
        ll s = 0;
        for(ll j = 0; j < 32; j++){ // final check for indalid cases
            if(v[l1][j] - v[l-1][j] == l1-l+1){
                s += (1<<j);
            }
        }
        if(s < k) l1 = -1;
        cout << l1 << " ";
    } cout << endl;
    
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
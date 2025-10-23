#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vi> a(n+1, vi(m+1));
    vi s(n);
    map<ll, vi> mp;
    for(ll i = 0; i < n; i++){
        cin >> s[i];
        mp[s[i]].pb(i);
        for(ll j = 0; j < m; j++) cin >> a[i][j];
    }
    ll x = 0;
    ll p = 0;

    for(auto &[c, v]: mp){
        for(auto i: v){
            ll q = 0;
            for(ll j = 0; j < m; j++){
                if(a[i][j] == -1) a[i][j] = x;
                q += a[i][j];
            }
            p = max(p, q);
        } break;
    }
    mp.erase(mp.begin());


    
    for(auto &[c, v]: mp){
        // cout << c << " : " << endl;
        ll pp = 0;
        for(auto i: v){
            ll q = 0, z = p+1;
            // cout << z << endl;
            for(ll j = 0; j < m; j++){
                if(a[i][j] != -1){
                    z-=a[i][j];
                    // cout << z << endl;
                }
            }
            z = max(z, 0LL);
            // cout << z << endl;
            for(ll j = 0; j < m; j++){
                if(a[i][j] == -1){
                    a[i][j] = min(k, z);
                    z = max(z-k, 0LL);
                }
                // cout << a[i][j] << " ";
                q += a[i][j];
            }
            if(q <= p){
                no; return;
            }
            // cout << endl;
            pp = max(pp, q);
        }
        p = pp;
    }
    yes;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cout << a[i][j] << " ";
        } cout << endl;
    }
    
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
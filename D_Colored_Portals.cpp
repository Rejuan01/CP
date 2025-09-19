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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
ll inf = 1e18+10;
void solve(){
    ll n, q;
    cin >> n >> q;
    vector<string> a(n+1);
    map<string, vi> mp;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]].pb(i);
    }
    while(q--){
        ll x, y; cin >> x >> y;
        if(x > y) swap(x, y);
        if(a[x][0] == a[y][0] || a[x][0] == a[y][1] || a[x][1] == a[y][0] || a[x][1] == a[y][1]){
            cout << y-x << endl; continue;
        }
        ll ans = inf;
        for(auto ch: a[x]){
            bool flag = 0;
            for(auto cc: a[y]){
                string s = ""; s.pb(min(ch, cc)); s.pb(max(ch, cc));
                // cout << s << endl;
                auto idx = lower_bound(mp[s].begin(), mp[s].end(), x);
                if(idx != mp[s].end()){
                    // cout << *idx << endl;
                    if(*idx <= y){
                        ans = y-x; flag = 1; break;
                    }
                    if(*idx > y){
                        ans = min(ans, y-x+2*(*idx-y));
                    }
                }
                if(mp[s].size() && idx != mp[s].begin()){
                    --idx;
                    // cout << *idx << endl;
                    ans = min(ans, y-x+2*(x-*idx));
                }                
            }
            if(flag) break;
        }
        if(ans == inf){
            cout << -1 << endl; continue;
        }
        cout << ans << endl;
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
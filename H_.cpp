#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n;
    cin >> n;
    map<ll, set<ll>> mp;
    map<ll, ll> cnt;
    vi ans;
    for(ll i = 0; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(c < 240){
            if(mp[a].count(b)) ans.pb(0);
            else{
                mp[a].insert(b);
                cnt[a]++;
                ans.pb(b);
            }
        }
        else{
            if(mp[a].count(b)) ans.pb(0);
            else if(cnt[a] < 3){
                mp[a].insert(b);
                ans.pb(b);
                cnt[a]++;
            }
            else{
                mp[a].insert(b);
                cnt[a]++;
                ans.pb(0);
            }
        }
    }
    for(auto it: ans) cout << it << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
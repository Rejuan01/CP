#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
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
    ll n, m;
    cin >> n >> m;
    vp a(m);
    map<ll, ll> mp;
    for(ll i = 0; i < m; i++){
        ll x,y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    
    set<pr> ans;
    ll k = a[0].first, c = 0;

    {
        for(ll i = 1; i < m; i++){
            if(k != a[i].first && k != a[i].second){
                c++;
                mp[a[i].first]++;
                mp[a[i].second]++;
            }
        }

        if(c==0)
        for(ll i = 1; i <= n; i++){
            if(i == k) continue;
            ans.insert({min(i, k), max(i, k)});
        }
        else
        for(auto [p, q]: mp){
            if(q == c){
                ans.insert({min(p, k), max(p, k)});
            }
        }
    }

    k = a[0].second, c = 0;
    mp.clear();

    {
        for(ll i = 1; i < m; i++){
            if(k != a[i].first && k != a[i].second){
                c++;
                mp[a[i].first]++;
                mp[a[i].second]++;
            }
        }

        if(c==0)
        for(ll i = 1; i <= n; i++){
            if(i == k) continue;
            ans.insert({min(i, k), max(i, k)});
        }
        else
        for(auto [p, q]: mp){
            if(q == c){
                ans.insert({min(p, k), max(p, k)});
            }
        }
    }

    cout << ans.size() << endl;
    
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
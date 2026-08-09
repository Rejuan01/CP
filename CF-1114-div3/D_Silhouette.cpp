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
    ll n;
    cin >> n;
    vi a(n);
    map<ll, ll> mp, mp1;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vp v;
    for(auto it: mp) v.pb(it);
    if(v[0].first != 0){
        cout << -1 << endl; return;
    }
    ll m = v.size(), c = 0, s = 0;
    for(ll i = 1; i < m; i++){
        ll x = v[i].first-s;
        if(x%v[i-1].second != 0 || x/v[i-1].second <= c){
            cout << -1 << endl;
            return; 
        }
        else{
            mp1[v[i-1].first] = x/v[i-1].second;
            s = v[i].first;
            c = x/v[i-1].second;
        }
    }
    mp1[v[m-1].first] = c+1;

    for(auto it: a) cout << mp1[it] << " ";
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
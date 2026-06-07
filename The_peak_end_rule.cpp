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
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n);
    vp v;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(i < n-1)
        v.pb({a[i], i});
    }
    ll ans = a[n-1];
    rsort(v);
    // cout << v[0].first << " " << ans << endl;
    // if(v[0].first > 0) 
    ans += v[0].first;
    b[n-1] = 1;
    b[v[0].second] = 1;
    ll id = 2;
    for(ll i = 1; i < n-1 && id <= k; i+=2){
        if(i == n-2){
            if(v[i].first > 0)
            {
                ans += v[i].first;
                b[v[i].second] = id;
                break;
            }
        }
        // cout << "** " << i << endl;  
        if(v[i].first > 0)
        {
            ans += v[i].first;
            b[v[i].second] = id;
        }
        else break;

        if(v[i+1].first > 0)
        {
            ans += v[i+1].first;
            b[v[i+1].second] = id++;
        }
        else break;
    }
    for(auto &it: b) if(it == 0) it = 1;
    cout << ans << endl;
    for(auto it: b) cout << it <<" ";
    cout << endl;
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
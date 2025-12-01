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
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(1);
    for(ll i = 1; i <= n; i+=2) a.pb(i);
    for(ll i = 2; i <= n; i+=2) a.pb(i);
    vi b(n+1);
    for(ll i = 1; i <= n; i++){
        b[a[i]] = i;
    }
    vi ans(n+1);
    ans[1] = 1; 
    ans[n] = n;
    set<ll> st;
    for(ll i = 2; i < n; i++) st.insert(i);
    while(!st.empty()){
        ll z = *st.begin();
        ll x = z;
        vi v;

        do{ 
            v.pb(x);
            x = b[x];
        }
        while(x != z);

        for(ll i = 0; i < v.size(); i++){
            ll idx = (i + k)%v.size();
            ans[v[idx]] = v[i];
            st.erase(v[i]);
        }
    }
    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

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
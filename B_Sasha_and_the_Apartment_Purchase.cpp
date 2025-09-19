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
    vi a(n+1), s(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    for(ll i = 1; i <= n; i++) cout << s[i] << " ";
    cout << endl << endl;
    ll l = 1, r = n-k;
    map<ll, ll> mp;
    ll c = LONG_MAX;
    while(r <= n){
        ll x = (l+r)/2, y = (l+r+1)/2;
        ll s1 = (x-l)*a[x] - (s[x-1]-s[l-1]) + (s[r]-s[x])-(r-x)*a[x];
        ll s2 = (y-l)*a[y] - (s[y-1]-s[l-1]) + (s[r]-s[y])-(r-y)*a[y];
        cout << l << " " << r << " " << x << " " << y << endl;
        cout << s1 << " " << s2 << endl;
        // s1 = min(s1, s2);
        mp[s1]++;
        if(x != y) mp[s2]++;
        c = min({c, s1, s2});
        l++; r++;
    }
    cout << mp[c] << endl;
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
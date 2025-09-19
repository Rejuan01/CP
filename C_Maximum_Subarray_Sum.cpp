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

void show(vi &v){
    for(auto it: v) cout << it << " ";
    cout << endl;
}

void solve(ll tc){
    ll n, k, z = 0;
    string s;
    cin >> n >> k >> s;
    vi a(n);
    map<ll, ll> mp;
    vp v;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        if(s[i] == '0') continue;
        z++;
        ll c = 0, mx = 0;
        ll j = i;
        while(j < n && s[j] != '0'){
            c += a[j]; 
            if(c < 0) c = 0;
            if(c > k){
                no; return;
            }
            mx = max(mx, c);
            j++;
        }
        if(j-i == n){ // i = 0, j = n (all '1')
            if(mx == k){
                yes; show(a);
            }else no; return;
        }
        i = j;
    }

    ll x = 0;
    while(x < n && s[x] != '0') x++;
    // cout << x << endl;

    ll m1 = 0, m2 = 0;
    ll c = 0;
    for(ll i = x-1; i >= 0 ; i--){
        c += a[i];
        // cout << c << endl;
        m1 = max(m1, c);
    }
    ll y = x; c = 0;
    while(y < n && s[y] == '0'){
        s[y] = '1';
        y++;
    }

    for(ll i = y; i < n && s[i] == '1'; i++){
        c += a[i];
        // cout << c << endl;
        m2 = max(m2, c);
    }
    a[x] = k-m1-m2;
    ll neg_inf = -1e18;
    for(ll i = 0; i < n; i++){
        if(s[i] == '0') a[i] = neg_inf;
    }
    // cout << m1 << " " << m2 << endl;
    yes;
    show(a);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
       solve(i);
    }
    return 0;
}
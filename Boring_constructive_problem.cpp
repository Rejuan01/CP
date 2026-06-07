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
    ll a, b, n, s;
    cin >> a >> b >> n >> s; 
    if(b > a) swap(a, b);
    if(s%a != 0 || (s%a == 0 && s > n*a)){
        yes;
        for(ll i = 0; i < n; i++) cout << a << " ";
        cout << endl;
        return;
    }
    if(s%b != 0 || (s%b == 0 && s > n*b)){
        yes;
        for(ll i = 0; i < n; i++) cout << b << " ";
        cout << endl;
        return;
    }
    ll x = s/a - 1, y = s/b - 1;
    if(a%b == 0){
        if(a == s || (a/b == 2 && 2*(x+1) <= n)){
            no;
            return;
        }
    }
    y = 1;
    vi v;
    while(v.size() < n){
        for(ll i = 0; i < x && v.size() < n; i++) v.pb(a);
        for(ll i = 0; i < y && v.size() < n; i++) v.pb(b);
    }
    yes;
    for(auto it: v) cout << it << " ";
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
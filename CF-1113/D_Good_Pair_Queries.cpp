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
    ll n, q;
    cin >> n >> q;
    string s1, s2;
    cin >> s1 >> s2;
    vi a(n+1), b(n+1), c(n+1), d(n+1);
    for(ll i = 1; i <= n; i++){
        a[i] = a[i-1];
        b[i] = b[i-1];
        c[i] = c[i-1];
        if(s1[i-1] == '0' && s2[i-1] == '1'){
            a[i]++;
        }
        else if(s1[i-1] == '1' && s2[i-1] == '0'){
            b[i]++;
        }
        else{
            c[i]++;
        }
    }
    while(q--){
        ll l, r;
        cin >> l >> r;
        ll x = a[r]-a[l-1], y = b[r]-b[l-1], z = c[r]-c[l-1];
        // cout << x << " " << y << " " << z << endl;
        if(z >= abs(x-y)) yes;
        else no;
    }
    
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
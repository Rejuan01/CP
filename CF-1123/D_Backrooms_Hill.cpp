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
    vi a, b;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(i&1) a.pb(x);
        else b.pb(x);
    }
    a.pb(0);
    b.pb(0);
    ssort(a);
    ssort(b);
    // for(auto it: b) cout << it << " ";
    // cout << endl;
    // for(auto it: a) cout << it << " ";
    // cout << endl;

    ll i = a.size()-1, j = b.size()-1;
    while(i > 0 && j > 0){
        // cout << b[j-1] << " " << b[j] << endl;
        // cout << a[i-1] << " " << a[i] << endl;
        if(a[i] < b[j-1] || b[j] < a[i-1]){
            no;
            return;
        }
        i--;
        j--;
    }
    yes;
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
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
    vi a(n);
    ll s = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    ll x = s, id = -1, mx = s;
    for(ll i = 0; i < n; i++)           // select a +ve that would be -ve and its prefix be +ve
    {
        if(a[i] < 0) x += abs(2*a[i]);
        else if(x-2*a[i] > mx){
            id = i;
            mx = x-2*a[i];
        }
    }
    if(id == -1)
    {
        cout << 0 << endl << endl;
        return;
    }
    // make [1, id-1] all -ve so that final flip make them +ve.  same as C1 ;(
    vi v;
    if(a[id-1] > 0) v.pb(id-1);
    for(ll i = id-2; i >= 0; i--)
    {
        if(a[i]*a[i+1] < 0) v.pb(i);
    }
    v.pb(id);
    cout << v.size() << endl;
    for(auto it: v) cout << it+1 << " ";
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
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
void solve(){
    ll n;
    cin >> n;
    ll a = 0, b = 0;
    vi x(n), y(n);
    for(ll i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(ll i = 0; i < n; i++){
        ll j = (i+1)%n;
        a += (x[i]*y[j]-x[j]*y[i]);
        ll dx = abs(x[i]-x[j]), dy = abs(y[i]-y[j]);
        b += __gcd(dx, dy);
    }
    a = abs(a);
    ll in = (a-b+2)/2;
    cout << in << " " << b << endl;
}
// Pick's theorem: A = i + B/2 -1
// A = area, B = lattice points in boundary, i = lattice points inside
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
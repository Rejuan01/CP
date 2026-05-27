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
    ll n, h, k;
    cin >> n >> h >> k;
    vi a(n);
    ll s = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    ll c = h/s;
    if(h%s == 0){
        ll x = c*n + (c-1)*k;
        cout << x << endl;
        return;
    }
    h %= s;
    vi mn(n), mx(n);

    ll x = h;
    ll id;

    for(id = 0; id < n && x > 0; id++) x -= a[id];
    id--;    

    ll ans = c*(n+k) + id+1;

    mn[0] = a[0], mx[n-1] = a[n-1];

    for(ll i = n-2; i >= 0; i--) mx[i] = max(mx[i+1], a[i]);

    for(ll i = 1; i < n; i++)
    {
        mn[i] = min(mn[i-1], a[i]); 
        a[i] += a[i-1];
    }

    for(ll i = 0; i < id; i++)      // if possible to kill with i+1 bullets
    {
        ll sum = a[i];
        if(mx[i+1] > mn[i])
        {
            sum += mx[i+1]-mn[i];
            if(sum >= h)
            {
                ans = c*(n+k)+i+1;
                break;          
            }
        }
    }
    cout << ans << endl;
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
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
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    vector<vector<bool>> ck(n+1, vector<bool> (n+1));
    
    ll c[n+1];
    
    for(ll i = 0; i < n; i++){
        ll mx = 0, mn = 1e18;
        memset(c, 0, sizeof(c));
        for(ll j = i; j < n && j < i + n/2; j++){
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);

            if(c[a[j]])  break;
            
            c[a[j]]++;

            if(j-i == mx-mn) ck[mn][mx] = 1;
        }
    }
    for(ll d = n/2; d > 0; d--){
        for(ll i = 0; i+2*d <= n; i++){
            if(ck[i+1][i+d] && ck[i+d+1][i+2*d]){
                cout << d << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
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
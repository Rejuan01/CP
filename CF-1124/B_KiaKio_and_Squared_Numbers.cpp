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
ll fun(ll x){
    ll s = 0;
    while(x){
        ll k = x%10;
        s += k*k;
        x /= 10;
    }
    return s;
}
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n), b(n, -1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll k = 0;
    for(ll i = 0; i < n; i++){
        ll x = a[i], c = 1;
        if(x == 4){
            b[i] = 1;
            continue;
        }
        if(x == 1){
            k++;
            continue;
        }
        while(x != 4 && x != 1){
            x = fun(x);
            c++;
        }
        if(x == 4){
            b[i] = c;
        }
        else if(x == 1){
            k++;
        }
    }
    ll ans = k*(k-1)/2;
    for(ll i = 0; i < n; i++)
    {
        if(b[i] == -1) continue;

        for(ll j = i+1; j < n; j++)
        {
            if(b[j] == -1) continue;

            if(abs(b[i]-b[j])%8 == 0)
            {
                // cout << a[i] << " " << a[j] << endl;
                // cout << b[i] << " -- " << b[j] << endl;
                ans++;
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
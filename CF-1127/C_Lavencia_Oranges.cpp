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
    ll l = 0, r = n;
    while(l+1 < r)
    {
        ll m = (l+r)/2, c = 0;
        for(ll i = 1; i <= n; i++){
            c += (m/i)*i;
            if(c >= n) break;
        }
        if(c >= n) r = m;
        else l = m;
    }
    cout << r << endl; // min cost
    
    vi a(n+1);
    ll rem = n, x = 0;

    for(ll i = r; i  > 0 && rem > 0; i--)
    {     
        ll c = min(r/i, rem/i);   // c numbers with freq i
        rem -= i*c;

        // cout << i << " : " << c << " -- " << rem << endl;

        for(ll j = 0; j < c; j++){
            x++;
            for(ll k = 0; k < i; k++){
                cout << x << " ";
            }
        }
        // cout << endl;
    }
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
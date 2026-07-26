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

const ll MOD = 998244353;

void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n-1);
    bool f = 0;
    for(ll i = 0; i < n-1; i++){
        cin >> a[i];
        if(a[i] == n) f = 1;
    }

    if(f){
        cout << 0 << endl;
        return;
    }

    set<ll> st;
    st.insert(a[0]);

    for(ll i = 1; i < n-1; i++){
        if((f && a[i] > a[i-1])){      // once its start decreasing (passing the n in the permutation), cannot increase anymore
            cout << 0 << endl;
            return;
        }
        if(a[i] < a[i-1]) f = 1;

        if(!f) st.insert(a[i]);
        else if(st.count(a[i])){       // decreasing part cannot have the same value already in th increasing part
            cout << 0 << endl;
            return;
        }
    }

    ssort(a);
    ll ans = 2;

    for(ll i = 1; i < n-1; i++){
        if(a[i] == a[i-1]){                    // in this position in permutation, there must be some value less than a[i]
            ans = ans*(a[i]-i) % MOD;          // remaining value less than a[i] = a[i]-i
        }
        // cout << i << " " << ans << endl;
    }

    cout << ans << endl;
}
// for calculation, need to traverse from smaller to the highrt value. Also could be implemented using two pointer (ig) from both direction & calculate for the min
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
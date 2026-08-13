#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
#define ld long double
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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n+1);
    for(ll i = 1; i <= n; i++){
        if(s[i-1] == 'o') a[i]++;
        a[i] += a[i-1];
    }

    ld one = 1.00000000000, zero = 0.000000000000;
    ld l = zero, r = 100.1;

    ll itr = 40;

    while(itr--){
        ld p = (l+r)/2;
        vector<ld> b(n+1), c(n+1); 
        bool flag = 0;
        for(ll i = 1; i <= n; i++){
            if(s[i-1] == 'o') b[i] = one;
            b[i] -= p;

            b[i] += b[i-1];
            c[i] = min(c[i-1], b[i]);        // c[0] starts with zero, and I dont consider if any min from 1 to i is > 0

            if(a[i] < k) continue;

            ll j = upper_bound(a.begin(), a.end(), a[i]-k) - a.begin() - 1;
            if(b[i] - c[j] >= zero){
                flag = 1;
                break;
            }
        }
        if(flag) l = p;
        else r = p;
    }
    cout << fixed << setprecision(7) << l << endl;
}
/*
    In a Subarray, to have a win percentage >= p, win_count - len*p >= 0
    So I can -= p in all idx and the subarrays with sum >= 0 is only in consideration now
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
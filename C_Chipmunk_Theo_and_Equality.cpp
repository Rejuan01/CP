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
    map<ll, ll> cost, cnt;
    for(ll i = 0; i < n; i++) cin >> a[i];
    ssort(a);
    ll x = a[0];
    ll c = 0;

    while(x >= 1) // first number
    {
        if(x == 1)
        {
            cnt[1]++;
            cost[1] += c;
            break;
        }

        cnt[x]++;
        cost[x] += c++;
        if(x&1) x++;
        else x >>= 1;
    }

    if(a[0] == 1)  // 1 -> 2 case
    {
        cnt[2]++;
        cost[2]++;
    }

    for(ll i = 1; i < n; i++)
    {
        ll k = a[i];
        c = 0;

        while(k >= 1){

            if(k == 1)
            {
                cnt[1]++;
                cost[1] += c;
                break;
            }
            
            if(cnt.count(k)){  // only if already found from the first number
                cnt[k]++;
                cost[k] += c;
            }
            c++;
            if(k&1) k++;
            else k >>= 1;
        }

        if(a[i] == 1 && cnt.count(2))     // 1->2 case
        {
            cnt[2]++;
            cost[2]++;
        }
    }
    ll ans = 1e18;
    for(auto [v, f]: cnt){
        if(f == n) ans = min(ans, cost[v]); // min cost among those numbers got from every a[i]
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
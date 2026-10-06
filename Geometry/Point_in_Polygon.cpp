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
    ll n,m;
    cin >> n >> m;
    vi x(n), y(n);
    for(ll i = 0; i < n; i++) cin >> x[i] >> y[i];
    while(m--){
        ll p, q;
        cin >> p >> q;
        ll cnt = 0;
        for(ll i = 0; i < n; i++){
            ll j = (i+1)%n;
            ll x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
            if(y1 == y2){
                if(q == y1 && p >= min(x1, x2) && p <= max(x1, x2)){
                    cnt = -1; break;
                }
                continue;
            }
            if(y1 > y2){
                swap(x1, x2);
                swap(y1, y2);
            }
            i128 d = (i128)(x2-x1)*(q-y1)-(i128)(y2-y1)*(p-x1);

            if(d > 0 && q >= y1 && q < y2){        // half open interval to ignore redundent count of intersection with nodes
                cnt++;
            }
            else if(d == 0 && q >= y1 && q <= y2){   // close interval (in the case: two edge intersect in their upper bound)      
                cnt = -1; break;
            }
        }
        if(cnt == -1) cout << "BOUNDARY" << endl;
        else if(cnt&1) cout << "INSIDE" << endl;
        else cout << "OUTSIDE" << endl;
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
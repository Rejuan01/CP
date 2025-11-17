#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, k, m, a, b;
    cin >> n >> k >> m >> a >> b; 
    if(n%m == 0){
        cout << 0 << endl; return;
    }
    if(k == 1){
        cout << -1 << endl; return; 
    }
    ll s = LONG_LONG_MAX;
    vi ans;
    ll x = n;
    ll c1 = 0; 
    while(x){
        __int128 p = x, q = x+1; 
        ll c2 = 0; 
        while(1){
            c2++;
            p *= k; q *= k;      
            __int128 val = ((p+m-1)/m)*m;
            if(val < q){              // a multiple of m found in [p , q) 
                break;
            }
        } 
        ll cost = c2*a + c1*b; 
        s = min(s, cost); 
        if(x%m==0){
            s = min(s, c1*b);
        } 
        c1++;
        x/=k; 
    }
    s = min(s, c1*b);
    cout << s << endl;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
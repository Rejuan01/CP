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
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll s, m;
    cin >> s >> m;
    vi a;
    for(ll i = 0; i < 63; i++){
        if(m&(1LL<<i)) a.pb((1LL<<i));
    }
    rev(a);
    for(ll i = 0; i < 63; i++){
        if(s&(1LL<<i)){
            if((1LL<<i) < a.back()){       // cannot reach s using any bit of m
                cout << -1 << endl;
                return;
            }
            break;
        }
    }
    ll tm = s;
    ll l = 0, r = 0;
    for(auto it: a){
        r = max(r, s/it);
        s %= it;
    }
    while(l+1 < r){
        ll x = l+(r-l)/2;
        ll s1 = tm;
        for(auto it: a){
            if(x <= s1/it){
                s1 -= it*x;
            }
            else{
                s1 %= it;
            }
        }
        if(s1 == 0) r = x; // I can generate s using x numbers (which are generated using bits of m)
        else l = x;
    }
    cout << r << endl;
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
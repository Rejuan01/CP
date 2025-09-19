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
    ll n;
    cin >> n;
    vi b(n), c(n+1);
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        c[b[i]]++;
    }
    map<ll, multiset<ll>> mp;
    ll x = 1;
    for(ll i = 1; i <= n; i++){
        if(c[i]%i != 0){
            cout << -1 << endl;
            return;
        }
        if(c[i] == 0) continue;
        ll k = c[i]/i;
        for(ll j = 0; j < k; j++){
            for(ll p = 0; p < i; p++){
                mp[i].insert(x);
            }
            x++;
        }
    }
    vi a;
    for(auto z: b){
        auto it = mp[z].begin();
        a.pb(*it);
        mp[z].erase(it); // problem here
    }
    for(auto it: a){
        cout << it << " ";
    } cout << endl;

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
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
    vi c(2*n);
    vector<vi> a(n, vi(n));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            fill(c.begin(), c.end(), 0);
            for(ll k = 0; k < i; k++) c[a[k][j]] = 1;
            for(ll k = 0; k < j; k++) c[a[i][k]] = 1; 
            for(ll k = 0; k < 2*n; k++){
                if(c[k] == 0){
                    a[i][j] = k;
                    break;
                }
            }
        } 
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
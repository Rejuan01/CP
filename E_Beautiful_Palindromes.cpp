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
    ll n, k;
    cin >> n >> k;
    vi a(n), c(n+1);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]] = 1;
    }
    ll x = 0, y = 0, z = 0;
    for(ll i = 1; i <= n; i++) if(c[i] == 0){x = i; break;}
    if(x == 0){                                             // a is a permutation on len n
        for(ll i = 0; k > 0; i = (i+1)%3){
            cout << a[i] << " ";
            k--;
        }
        cout << endl; return;
    }
    y = a.back();
    for(ll i = 1; i < 4; i++) 
        if(i != x && i != y){
            z = i; break;
        }
    for(ll i = 0; i < k; i++){
        if(i%3 == 0) cout << x << " ";
        else if(i%3 == 1) cout << z << " ";
        else cout << y << " ";
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
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
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
    ll a, b;
    cin >> a >> b;
    ll c1 = 0, c2 = 0;
    ll x = a, y = b, k = 1;
    while(1){
        if(a >= k){
            a -= k;
            c1++;
        } else break;
        k *= 2;
        if(b >= k){
            b -= k;
            c1++;
        } else break;
        k *= 2;
    }
    a = x, b = y, k = 1;
    while(1){
        if(b >= k){
            b -= k;
            c2++;
        } else break;
        k *= 2;
        if(a >= k){
            a -= k;
            c2++;
        } else break;
        k *= 2;
    }
    cout << max(c1, c2) << endl;
    
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
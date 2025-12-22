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
    ll n, k;
    cin >> n >> k;
    if(k&1){
        while(k--) cout << n << " ";
        cout << endl; return;
    }
    vector<bool> tight(k, 1);
    vi a(k);
    ll c = 0, x = n, cnt = 0;
    while(x>>=1) c++;
    for(ll i = c; i >= 0; i--){
        if((1<<i)&n){
            for(ll j = 0; j < k; j++){
                if(j == x){
                    tight[x] = 0;
                }
                else if(x >= k && j == 0) continue;
                else a[j] ^= (1 << i);
            } x++;
        }
        else
        for(ll j = 0; j < k-1; j += 2){
            if((!tight[j]) && (!tight[j+1])){
                a[j] ^= (1<<i);
                a[j+1] ^= (1<<i);
            }
        }
    }
    for(ll i = 0; i < k; i++) cout << a[i] << " ";
    cout << endl;
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
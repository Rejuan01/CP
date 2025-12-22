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
    ll n, x;
    cin >> n >> x;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vector<vi> b;
    for(ll i = 1; i < n; i++){
        for(ll j = 0; j < i; j++){
            b.push_back({a[i]+a[j], j+1, i+1});
        }
    }
    ssort(b);
    ll l = 0, r = b.size()-1;
    while(l < r){
        if(b[l][0]+b[r][0] < x) l++;
        else if(b[l][0]+b[r][0] > x) r--;
        else if(b[l][1] == b[r][1] || b[l][2] == b[r][2]) break;
        else{
            cout << b[l][1] << " " << b[l][2] << " " << b[r][1] << " " << b[r][2] << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
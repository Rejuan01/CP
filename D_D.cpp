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
    ll n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    vector<vector<bool>> mrk(n, vector<bool>(m, 0));
    vp v(n*m+1);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
            v[a[i][j]] = {i, j};
        }
    }
    for(ll i = 0; i < n*m; i++){
        ll x = v[i].first, y = v[i].second;
        if(mrk[x][y]){
            cout << i << endl;
            return;
        }
        for(ll j = x-1; j >= 0; j--){
            ll k = y+1;
            if((k < m && mrk[j][k]) || k >= m) break; 
            for(; k < m; k++){
                if(mrk[j][k]) break;
                mrk[j][k] = 1;
            }
        }
        for(ll j = x+1; j < n; j++){
            ll k = y-1;
            if((k >= 0 && mrk[j][k]) || k < 0) break;
            for(; k >= 0; k--){
                if(mrk[j][k]) break;
                mrk[j][k] = 1;
            }
        }
    }
    cout << n*m << endl;
    
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
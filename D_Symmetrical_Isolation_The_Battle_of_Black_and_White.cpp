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
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(ll i = 0; i < n; i++) cin >> s[i];
    bool flag = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'W') continue;
            if((i > 0 && s[i-1][j] == 'B') || (i < n-1 && s[i+1][j] == 'B') || (j > 0 && s[i][j-1] == 'B') || (j < m-1 && s[i][j+1] == 'B')){
                no; return;
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'W') continue;
            ll k = m-1-j;
            if((i > 0 && s[i-1][k] == 'B') || (i < n-1 && s[i+1][k] == 'B') || (k > 0 && s[i][k-1] == 'B') || (k < m-1 && s[i][k+1] == 'B')){
                flag = 1; break;
            }
        }
        if(flag) break;
    }
    if(!flag){
        yes; return;
    }
    flag = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(s[i][j] == 'W') continue;
            ll k = n-1-i;
            if((k > 0 && s[k-1][j] == 'B') || (k < n-1 && s[k+1][j] == 'B') || (j > 0 && s[k][j-1] == 'B') || (j < m-1 && s[k][j+1] == 'B')){
                flag = 1; break;
            }
        }
        if(flag) break;
    }
    if(flag) no;
    else yes;
    
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
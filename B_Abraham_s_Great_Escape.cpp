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
    ll c = n*n-k;
    if(c == 1){
        no; return;
    }
    vector<vector<char>> a(n, vector<char>(n, '0'));
    yes;
    for(ll i = 0; i < n; i++){
        if(c){
            if(i == 0) a[i][0] = 'R';
            else a[i][0] = 'U';
            c--;
        }else a[i][0] = 'R';
        for(ll j = 1; j < n; j++){
            if(c){
                a[i][j] = 'L';
                c--;
            } else a[i][j] = 'R';
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++) cout << a[i][j];
        cout << endl;
    }
    
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
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
const ll N = 8;
vector<bool> diag1(2*N), diag2(2*N), col(N);
ll track(vector<string> &s, ll i){
    if(i == N) return 1;
    ll c = 0;
    for(ll j = 0; j < N; j++){
        if(s[i][j] != '.' || diag1[i+j] || diag2[i-j+N] || col[j]) continue;
        col[j] = diag1[i+j] = diag2[i-j+N] = 1;
        c += track(s, i+1);
        col[j] = diag1[i+j] = diag2[i-j+N] = 0;
    }
    return c; 
}
void solve(){
    vector<string> s(N);
    for(ll i = 0; i < N; i++) cin >> s[i];
    ll ans = track(s, 0);
    cout << ans << endl;
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
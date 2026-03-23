#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
    vector<string> s(n);
    vector<set<ll>> adj(26);
    for(ll i = 0; i < n; i++) cin >> s[i];
    for(ll i = 0; i < n-1; i++){
        for(ll j = 0; ; j++){
            if(j >= s[i+1].size() && j < s[i].size()){
                cout << "Impossible" << endl; return;
            }
            if(j >= s[i].size() || j >= s[i+1].size()) break;
            if(s[i][j] != s[i+1][j]){
                ll u = s[i][j]-'a';
                ll v = s[i+1][j]-'a';
                adj[u].insert(v);
                break;
            }
        }
    }
    vi indeg(26);
    for(auto st: adj){
        for(auto cc: st) indeg[cc]++;
    }
    string ans = "";
    queue<ll> q;
    for(ll i = 0; i < 26; i++) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        ans.pb(char('a'+u));
        for(auto c: adj[u]){
            if(--indeg[c] == 0) q.push(c);
        }
    }
    if(ans.size() != 26){
        cout << "Impossible" << endl; return;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
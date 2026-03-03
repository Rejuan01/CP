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
void solve(ll tc){
    ll n, m, x;
    cin >> n >> m >> x;
    string s = "";
    vi r;
    for(ll i = 0; i < m; i++){
        ll k;
        char c;
        cin >> k >> c;
        r.pb(k); 
        s.push_back(c);
    }
    set<ll> st;
    set<pr> sp;
    queue<pr> q;
    q.push({x, 0});     // {player, no of throw done to reach this player}
    sp.insert({x, 0});
    while(!q.empty()){
        ll k = q.front().first;
        ll id = q.front().second;
        q.pop();
        if(id == m){
            st.insert(k); continue;
        }
        if(s[id] == '0' || s[id] == '?'){
            ll v = (k-1+r[id])%n + 1;
            if(!sp.count({v, id+1})){
                q.push({v, id+1});
                sp.insert({v, id+1});
            }
        }
        if(s[id] == '1' || s[id] == '?'){
            ll v = (k-1-r[id]+n)%n + 1;
            if(!sp.count({v, id+1})){
                q.push({v, id+1});
                sp.insert({v, id+1});
            }
        }
    }
    cout << st.size() << endl;
    for(auto it: st) cout << it << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
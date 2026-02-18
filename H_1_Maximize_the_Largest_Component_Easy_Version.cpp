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
const ll N = 1e6+5;
vector<string> s;
vector<vi> v;  // visit mark with component no
ll com[N];
ll n, m;
bool check(ll x, ll y){
    if(x < 0 || y < 0 || x >= n || y >= m || v[x][y] || s[x][y] == '.') return 0;
    return 1;
}
void dfs(ll x, ll y, ll id){
    v[x][y] = id;
    com[id]++;
    if(check(x-1, y)) dfs(x-1, y, id);
    if(check(x, y-1)) dfs(x, y-1, id);
    if(check(x+1, y)) dfs(x+1, y, id);
    if(check(x, y+1)) dfs(x, y+1, id);
}
void solve(ll tc){
    cin >> n >> m;
    s.resize(n);
    v.assign(n, vi(m, 0));
    memset(com, 0, (n*m+1)*sizeof(ll));
    for(ll i = 0; i < n; i++) cin >> s[i];
    ll id = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(!v[i][j] && s[i][j] == '#'){
                id++;
                dfs(i, j, id);
            }
        }
    }
    // cout << id << endl;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        set<ll> st;
        ll cnt = 0;
        for(ll j = 0; j < m; j++){
            if(s[i][j] == '.'){       // make it '#' and merge with up and down cells if possible
                cnt++;
                if(i-1 >= 0 && !st.count(v[i-1][j])){
                    st.insert(v[i-1][j]);
                    cnt += com[v[i-1][j]];
                }
                if(i+1 < n && !st.count(v[i+1][j])){
                    st.insert(v[i+1][j]);
                    cnt += com[v[i+1][j]];
                }
            }
            else if(!st.count(v[i][j])){
                st.insert(v[i][j]);
                cnt += com[v[i][j]];
            }
        }
        // cout << i << " : " << cnt << endl;
        ans = max(ans, cnt);
    }
    for(ll j = 0; j < m; j++){
        set<ll> st;
        ll cnt = 0;
        for(ll i = 0; i < n; i++){
            if(s[i][j] == '.'){        // make it '#' and merge with left and right cells if possible 
                cnt++;
                if(j-1 >= 0 && !st.count(v[i][j-1])){
                    st.insert(v[i][j-1]);
                    cnt += com[v[i][j-1]];
                }
                if(j+1 < m && !st.count(v[i][j+1])){
                    st.insert(v[i][j+1]);
                    cnt += com[v[i][j+1]];
                }
            }
            else if(!st.count(v[i][j])){
                st.insert(v[i][j]);
                cnt += com[v[i][j]];
            }
        }
        // cout << j << " : " << cnt << endl;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
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
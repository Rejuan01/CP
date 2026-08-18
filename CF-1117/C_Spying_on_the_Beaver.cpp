#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

vector<vi> adj;
set<ll> st, st1;

bool dfs(ll u){
    if(st.count(u)){
        st1.insert(u);
        return 1;           
    }
    for(auto v: adj[u]){
        if(dfs(v)) return 1;    // completely end the dfs
    }
    return false;
}

void solve(ll tc){
    ll n;
    cin >> n;

    adj.assign(n+1, {});
    st.clear();
    st1.clear();

    for(ll i = 2; i <= n; i++) {
        ll p;
        cin >> p;
        adj[p].pb(i);
    }

    ll m;
    cin >> m;
    vi a(m);
    bool flag = 0;
    for(ll i = 0; i < m; i++){
        cin >> a[i];   
        st.insert(a[i]);
        if(a[i] == 1) flag = 1;     
    }

    if(flag){
        cout << m-1 << " ";
        for(auto it: a){
            if(it != 1) cout << it << " ";
        }
        cout << endl;
        return;
    }

    for(auto v: adj[1]) dfs(v);

    ll x = 0;
    if(st1.size() != 0) x = *st1.begin();

    cout << m-1 << " ";
    for(auto it: a){
        if(it != x) cout << it << " ";
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
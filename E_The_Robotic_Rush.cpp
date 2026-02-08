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
#define all(a) a.begin(), a.end()
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];
    string s; 
    cin >> s;
    ssort(a); ssort(b);
    vp l, r;
    for(ll i = 0; i < n; i++){
        ll id = upper_bound(all(b), a[i]) - b.begin();
        if(id != m) r.pb({b[id]-a[i], i});             // robot i will die if move b[id]-a[i] or more steps right
        id--;
        if(id >= 0) l.pb({a[i]-b[id], i});             // robot i will die if move a[i]-b[id] or more steps left
    }
    ssort(l); ssort(r);
    ll cnt = 0, mx = 0, mn = 0, i = 0, j = 0;
    set<ll> st;  // died robots
    for(auto ch: s){
        if(ch == 'R') cnt++;
        else cnt--;
        if(cnt > 0)
            while(i < r.size() && r[i].first <= cnt){
                st.insert(r[i].second);
                i++;
            }
        else
            while(j < l.size() && l[j].first <= abs(cnt)){
                st.insert(l[j].second);
                j++;
            }
        cout << n-st.size() << " ";
    } cout << endl;
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
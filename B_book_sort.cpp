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
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n);
    set<pr> st;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        st.insert({a[i], i});
    }
    vp v;
    for(ll i = 0; i < n-1; i++){                 // make a[i] <= a[j] for all i < j  
        ll x = a[i];

        st.erase({x, i});

        while(st.begin()->first < x){                // make operation with smallest in the right 
            ll id = st.begin()->second;
            ll s = st.begin()->first + x;
            st.erase(st.begin());

            x = s/2;
            a[id] = (s+1)/2;
            
            st.insert({a[id], id});
            v.pb({i, id});
        }
        
    }
    cout << v.size() << endl;
    for(auto it: v) cout << it.first+1 << " " << it.second+1 << endl;

}
// if M = V.size() time complexity = M log(M)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
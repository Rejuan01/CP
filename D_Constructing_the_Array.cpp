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
    ll n;
    cin >> n;
    vi a(n+1);
    ll c = 1;

    map<ll, priority_queue<pr, vector<pr>, greater<pr>>, greater<ll>> mp;
    mp[n].push({1, n});

    while(c <= n){
        auto it = mp.begin();
        auto &q = mp.begin()->second;
        auto [x, y] = q.top();
        q.pop();

        if(q.size() == 0) mp.erase(it);
        
        ll z = (x+y)/2;
        a[z] = c++;

        if(x != z) mp[z-x].push({x, z-1});
        if(y != z) mp[y-z].push({z+1, y});
        
    }
    
    for(ll i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    
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
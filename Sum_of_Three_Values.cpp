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
    ll n, x;
    cin >> n >> x;
    vi a(n);
    map<ll, vi> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]].pb(i+1);
    }
    ssort(a);
    for(ll i = 0; i < n-2; i++){
        ll l = i+1, r = n-1;
        ll s = x-a[i];
        while(l < r){
            if(a[l]+a[r] < s) l++;
            else if(a[l]+a[r] > s) r--;
            else{
                cout << mp[a[i]].back() << " "; mp[a[i]].pop_back();
                cout << mp[a[l]].back() << " "; mp[a[l]].pop_back();
                cout << mp[a[r]].back() << " "; mp[a[r]].pop_back();
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
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
    ll n;
    cin >> n;
    vector<vi> events;
    for(ll i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        events.pb({x, 1, i}); // arrival event
        events.pb({y, 2, i}); // departure event
    }
    vi ans(n), rooms;
    ssort(events);
    ll k = 0;
    for(auto e: events){
        if(e[1] == 1){      // arrival
            if(rooms.size() == 0){
                rooms.pb(++k);
            }
            ans[e[2]] = rooms.back();
            rooms.pop_back();
        }
        else rooms.pb(ans[e[2]]); // in departure, make the room unallocated
    }
    cout << k << endl;
    for(ll i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
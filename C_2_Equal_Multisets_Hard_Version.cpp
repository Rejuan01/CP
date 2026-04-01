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
#define na cout<<"no"<<endl
void solve(ll tc){
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    map<ll, ll> ma, mb;
    for(ll i = 0; i < k; i++){
        ma[a[i]]++;
        set<ll> sta, stb;
        for(ll j = i; j < n && sta.size() < 2; j += k){
            sta.insert(a[j]);
            if(b[j] != -1) stb.insert(b[j]);
        }
        if(sta.size() > 1){
            for(ll j = i; j < n; j += k){
                if(b[j] == -1) b[j] = a[j];
                else if(a[j] != b[j]){
                    no;
                    return;
                }
            }
        }
        else{
            if(stb.size() > 1){
                no;
                return;
            }
            if(stb.size() == 1){
                ll x = *stb.begin();
                for(ll j = i; j < n; j += k){
                    if(b[j] == -1) b[j] = x;
                }
            } 
            // if stb.size() == 0 (all -1), we can assign any value, so we do nothing 
        }
        mb[b[i]]++;
    }
    for(auto [x, y]: ma){
        if(mb[x] > y){
            na;
            return;
        }
        ll d = y - mb[x];
        mb[-1] -= d;
        if(mb[-1] < 0){
            na;
            return;
        }
    }
    yes;
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
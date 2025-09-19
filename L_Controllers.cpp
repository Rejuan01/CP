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
    ll n, c1 = 0, c2 = 0, a, b;
    cin >> n;
    string s;
    cin >> s;
    for(auto &ch: s){
        if(ch == '+') c1++;
        else c2++;
    }
    ll d = abs(c1-c2);
    ll q; cin >> q;
    while(q--){
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(a == b){
            if(d) no;
            else yes;
            continue;
        }
        ll m = (d*b)/(a-b);
        if((d*b%(a-b) != 0) || m > min(c1, c2)){
            no; continue;
        }
        yes;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
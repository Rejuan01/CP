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
const ll N = 1e8+5;
bool p[N];
void solve(){
    ll cnt = 0;
    vi a;
    memset(p, 1, sizeof(p));
    p[0] = p[1] = 0;
    for(ll i = 2; i < N; i++){
        if(p[i]){
            cnt++;
            if(cnt%100 == 1) cout << i << endl;
            for(ll j = i*i; j < N; j += i){
                p[j] = 0;
            }
        }
    }
}
// from spoj
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
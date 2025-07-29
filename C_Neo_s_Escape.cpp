#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vb = vector<bool>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll test = 0;
void solve(){
    ll n;
    cin >> n;
    map<ll, vi, greater<ll>> m;
    vi a(n+1);
    vb mark(n+2, 0);    // in which position, previously made clones can be used directly
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    ll ans = 0;
    for(auto &[k, v]: m){
        ll p = 0;
        while(p < v.size()){
            bool flag = false;
            if(mark[v[p]]) flag = true;
            mark[v[p]-1] = 1;
            while(p < v.size() - 1 && v[p] + 1 == v[p+1]){
                p++;
            }
            if(mark[v[p]]) flag = true;
            mark[v[p]+1] = 1;
            // if start or end of a continuous segment is not marked
            if(!flag) ans++;
            p++;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
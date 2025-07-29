#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll N = 5e5 + 20;
ll a[N];
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> v;
    for(ll i = 0; i < m; i++){
        ll k; cin >> k;
        bool flag = false;
        ll idx = -1;
        set<ll> st;
        for(ll j = 0; j < k; j++){
            ll x; cin >> x;
            if((!flag) && a[x]){
                flag = true;
                idx = a[x];
            }
            st.insert(x);
        }
        if(flag){
            for(auto &it: st){
                v[idx-1].insert(it);
                a[it] = idx;
            }
        }else{
            v.push_back(st);
            for(auto &it: st){
                a[it] = v.size();
            }
        }
    }
    for(ll i = 1; i <= n; i++){
        if(a[i]){
            ll idx = a[i]-1;
            cout << v[idx].size() << " ";
        }else{
            cout << 1 << " ";
        }
    }
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}
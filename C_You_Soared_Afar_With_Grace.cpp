#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi a(n+1), b(n+1), ind(n+1);
    ll index;
    bool flag = false;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        ind[a[i]] = i;
    }
    ll c = 0;
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
        if(a[i] == b[i]){
            c++;
            index = i;
        }
    }
    if(c > 1){
        cout << -1 << endl; return;
    }
    set<pair<ll, ll>> st;
    for(ll i = 1; i <= n; i++){
        st.insert({a[i], b[i]});
    }
    for(auto &[x, y]: st){
        if(st.find({y, x}) == st.end()){
            cout << -1 << endl;
            return;
        }
    }
    ll ans = 0;
    vp v;
    if(n%2 == 1 && index != (n+1)/2){
        ans++;
        v.push_back({index, (n+1)/2});
        ll tmp = ind[a[index]];
        ind[a[index]] = a[(n+1)/2];
        ind[a[(n+1)/2]] = tmp;
        swap(a[index], a[(n+1)/2]);
        swap(b[index], b[(n+1)/2]);
    }
    ll p = 1, q = n;
    while(p < q){
        if(a[p] != b[q]){
            ans++;
            ll i = ind[b[q]];
            v.push_back({p, i});
            ll tmp = ind[a[p]];
            ind[a[p]] = ind[a[i]];
            ind[a[i]] = tmp;
            swap(a[p], a[i]);
            swap(b[p], b[i]);
        }
        p++; q--;
    }
    cout << ans << endl;
    for(auto &[x, y]: v){
        cout << x << " " << y << endl;
    }
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
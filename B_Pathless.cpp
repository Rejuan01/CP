#include<bits/stdc++.h>
using namespace std;
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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    ll s = 0;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        mp[a[i]]++;
    }
    if(s > k){
        for(auto it: a){
            cout << it << " ";
        } cout << endl;
        return;
    }
    ll x = k-s;
    if(x != 1){
        cout << -1 << endl; return;
    }
    ll c = mp[1];
    while(c--) cout << 1 << " ";
    c = mp[2];
    while(c--) cout << 2 << " ";
    c = mp[0];
    while(c--) cout << 0 << " ";
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
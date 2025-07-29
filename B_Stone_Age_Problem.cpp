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
    ll n, q;
    cin >> n >> q;
    vi a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    map<ll, ll> mp;
    bool flag = false;
    ll c;
    while(q--){
        ll t, i, x;
        cin >> t;
        if(t == 2){
            cin >> x;
            flag = true;
            mp = map<ll, ll>(); // clear the map
            c = x;
            sum = n*x;
            cout << sum << endl; continue;
        }
        cin >> i >> x; // t == 1
        if(flag){
            if(mp.find(i-1) == mp.end()){
                sum += x-c;
                mp[i-1] = x;
            }
            else{
                sum += x-mp[i-1];
                mp[i-1] = x;
            }
            cout << sum << endl; continue;
        }
        sum -= a[i-1]; // this part will work till t always 1
        a[i-1] = x;
        sum += x;
        cout << sum << endl;
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
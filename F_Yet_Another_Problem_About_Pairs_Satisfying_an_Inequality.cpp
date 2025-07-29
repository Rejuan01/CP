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
    vi v;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ll temp;
        cin >> temp;
        if(i <= temp) continue;
        v.push_back(i); // when value < index
        ll c = lower_bound(v.begin(), v.end(), temp) - v.begin(); // count of i such: i < a[j]
        ans += c;
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
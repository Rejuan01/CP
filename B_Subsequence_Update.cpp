#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    ll n, l, r;
    cin >> n >> l >> r;
    vi a, b, c;
    for(ll i = 1; i < l; i++){
        ll temp; cin >> temp;
        a.push_back(temp);
    }
    for(ll i = l; i < r+1; i++){
        ll temp; cin >> temp;
        a.push_back(temp);
        b.push_back(temp);
    }
    for(ll i = r+1; i < n+1; i++){
        ll temp; cin >> temp;
        b.push_back(temp);
    }
    ll sum1 = 0, sum2 = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll x = r-l+1;
    for(ll i = 0; i < x; i++){
        sum1 += a[i];
        sum2 += b[i];
    }
    cout << min(sum1, sum2) << endl;
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
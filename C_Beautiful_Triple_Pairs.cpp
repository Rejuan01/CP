#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    map<pair<ll, ll>, ll> m1, m2, m3;
    map<tuple<ll, ll, ll>, ll> m;
    ll pairCount = 0;
    for(int i = 0; i < n-2; i++){
        pairCount += m1[{a[i+1], a[i+2]}]-m[{a[i], a[i+1], a[i+2]}]; // previously how many times the 2nd and 3rd eleents were the same. But not the 1st one. Current triple will pair with those
        pairCount += m2[{a[i], a[i+2]}]-m[{a[i], a[i+1], a[i+2]}];  // previously how many times the 1st and 3rd eleents were the same. But not the 2nd one. Current triple will pair with those
        pairCount += m3[{a[i], a[i+1]}]-m[{a[i], a[i+1], a[i+2]}];  //..
        
        m1[{a[i+1], a[i+2]}]++;// update the counts
        m2[{a[i], a[i+2]}]++;
        m3[{a[i], a[i+1]}]++;
        m[{a[i], a[i+1], a[i+2]}]++;
    }
    m1.clear();
    m2.clear();
    m3.clear();
    m.clear();
    cout << pairCount << endl;
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
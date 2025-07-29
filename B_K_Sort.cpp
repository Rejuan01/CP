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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll maxDIff = 0, ans = 0;
    //map<ll, ll> mp;
    for(ll i = 0; i < n-1; ){
        while(i < n-1 && a[i] <= a[i+1]) i++;
        ll j;
        for(j = i+1; j < n && a[j] < a[i]; j++){
            maxDIff = max(maxDIff, a[i]-a[j]);
            ans += (a[i]-a[j]);
        } i = j;
    }
    cout << ans+maxDIff << endl; // total amount need to be increased + number of steps(maxDiff)
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
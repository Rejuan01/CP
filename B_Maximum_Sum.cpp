#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end());
    vi s;
    for(ll i = 0; i < n; i++){
        sum += a[i];
        s.push_back(sum);
    } 
    ll ptr = n-k-1;
    ll x = sum-s[ptr]; // sum of last k values, zero pair from the beginning
    for(ll i = 1; i <= k; i++){
        ll p = s[2*i-1];  // sum of first i pairs
        ll q = sum-s[ptr+i]; // sum of last k-i values
        x = min(x, p+q); 
    }
    cout << sum-x << endl;
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
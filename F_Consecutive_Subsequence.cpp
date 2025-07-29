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
    ll n;
    cin >> n;
    vi a(n);
    map<ll, ll> DP; // DP[i] = longest consecuitive subsequence's length ends in value i
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        DP[a[i]] = DP[a[i]-1]+1; 
    }
    ll k = 0, x; // count and the end number
    for(auto &[p, q]: DP){
        if(q > k){
            k = q;
            x = p;
        }
    }
    ll p = x-k+1; // starting number
    cout << k << endl;
    for(ll i = 0; i < n; i++){
        if(p == a[i]){
            cout << i+1 << " ";
            p++;
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
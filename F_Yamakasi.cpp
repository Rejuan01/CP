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
    ll n, s, x;
    cin >> n >> s >> x;
    vi a(n+1), pref(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    map<ll, ll> c;
    ll l = 1, ans = 0;
    for(ll r = 1; r <= n; r++){
        if(a[r] > x){
            c = map<ll, ll>(); // clear
            l = r+1;
            continue;
        }
        if(a[r] == x){
            while(l <= r){
                c[pref[l-1]]++; // only place where count updates 
                l++;
            }
        }
        ans += c[pref[r]-s]; // count of l such that : pref[r] - pref[l-1] = s
    }
    cout << ans << endl;
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
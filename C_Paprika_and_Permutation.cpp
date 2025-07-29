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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vi c(n+1, 0);
    ll p = 1;
    ll count = 0;
    
    for(ll i = 0; i < n; i++){
        while(c[p] == 1 && p < n) p++;
        if(a[i] <= n && c[a[i]] == 0){
            c[a[i]] = 1;
        }
        else if(2*p < a[i]){ // p < a[i]/2 means I can get p from a[i]
            p++;
            count++;
        }else{
            cout << -1 << endl;
            return;
        }
    }
    cout << count << endl;
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
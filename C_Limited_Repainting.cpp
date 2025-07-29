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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    ll l = -1, r = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        r = max(r, a[i]);
    }
    while(l + 1 < r){
        ll m = (l+r)/2, c = 0, i = 0;
        char last = 'R';
        while(i < n){
            if(a[i] <= m){ // ignore lower penalties
                i++;
                continue;
            }
            if(last == 'R' && s[i] == 'B') c++;
            last = s[i];
            i++;
        }
        if(c <= k){ // is it possible to keep penalty <= m withing k operations
            r = m;
        }else l = m;
    }
    cout << r << endl;
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
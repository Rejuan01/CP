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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for(ll i = 0; i < n; i++) cin >> s[i];
    vector<vi> a(n+1, vi(m+1));
    ll c = 0;
    for(ll i = 0; i <  n; i++){
        for(ll j = 0; j < m; j++){
            a[i+1][j+1] = a[i][j+1]+a[i+1][j]-a[i][j];
            if(s[i][j] == 'g'){
                c++;
                a[i+1][j+1]++;
            }
        }
    }
    ll l = c;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(s[i-1][j-1] != '.') continue;
            ll x1, x2, y1, y2;
            x1 = max(1LL, i-k+1);
            x2 = min(n, i+k-1);
            y1 = max(1LL, j-k+1);
            y2 = min(m, j+k-1);
            ll p = a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
            l = min(l, p);
        }
    }
    cout << c-l << endl;

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
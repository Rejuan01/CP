#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vi a(n);
    ll s = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    ll dd = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    ll d = sqrt(dd);
    if(s*s < dd){
        no; return;
    }
    ll k = *max_element(a.begin(), a.end());
    if(s-k+d < k){
            no; return;
        }
    yes;
    
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
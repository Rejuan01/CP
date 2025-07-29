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
    vp a, b, c;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        a.push_back({temp, i});
    }
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        b.push_back({temp, i});
    }
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        c.push_back({temp, i});
    }
    sort(a.begin(), a.end(), greater<pr>());
    sort(b.begin(), b.end(), greater<pr>());
    sort(c.begin(), c.end(), greater<pr>());
    ll ans = LONG_LONG_MIN;

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 3; j++){
            if(b[j].second == a[i].second) continue; // if same day continue
            for(ll k = 0; k < 3; k++){
                if(c[k].second == a[i].second || c[k].second == b[j].second) continue; // if same day continue
                ll sum = a[i].first + b[j].first + c[k].first;
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
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
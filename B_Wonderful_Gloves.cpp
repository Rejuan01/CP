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
    vi l(n), r(n);
    for(ll i = 0; i < n; i++) cin >> l[i];
    for(ll i = 0; i < n; i++) cin >> r[i];
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        if(l[i] > r[i]){
            sum += l[i];
            l[i] = 0;
        }else{
            sum += r[i];
            r[i] = 0;
        }
    }
    sort(l.begin(), l.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());
    ll i = 0, j = 0;
    k--;
    while(k--){
        if(l[i] > r[j]){
            sum += l[i];
            i++;
        }else{
            sum += r[j];
            j++;
        }
    }
    cout << sum+1 << endl;
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
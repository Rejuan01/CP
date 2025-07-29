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
    ll n, k, x;
    cin >> n >> k >> x;
    vi a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum < x){
        ll c = x/sum;
        if(x%sum) c++;
        if(c > k){
            cout << 0 << endl;
            return;
        }
        ll ss = c*sum;
        for(ll i = 0; i < n; i++){
            if(ss-a[i] < x){
                ll index = (k-c)*n + i + 1;
                cout << index << endl;
                return;
            }
            ss -= a[i];
        }
    }
    ll s = 0;
    ll p = 0;
    for(ll i = n-1; i >= 0; i--){
        p++;
        s += a[i];
        if(s >= x){
            cout << n*k-p+1 << endl;
            return;
        }
    }
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
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
    ll n, x;
    cin >> n >> x;
    vi a(n);
    if(n == 1){
        cout << x << endl; return;
    }
    for(ll i = 1; i < n; i++){
        a[i] = (a[i-1]|i);
    }
    if(a[n-1] == x){
        for(ll i = 0; i < n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    // for(auto it: a){
    //     cout << it << " ";
    // } cout << endl;
    ll l = 0, r = n;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll p = a[m], q = x;
        bool flag = 0;
        while(q || p){
            if(p%2 == 1 && q%2 == 0){
                flag = 1;
                break;
            }
            p >>= 1;
            q >>= 1;
        } 
        if(flag){
            r = m;
        }else l = m;
        //cout << l << " " << r << endl;
    }
    for(ll i = 0; i < n; i++){
        if(i <= l && i < n-1) cout << i << " ";
        else cout << x << " ";
    }cout << endl;
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
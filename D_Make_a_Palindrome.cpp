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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    if(k < 3){
        yes;
        return;
    }
    vi b = a;
    sort(b.begin(), b.end());
    vi v;
    ll p = b[k-1];
    for(auto it: a){
        if(it <= p) v.push_back(it);
    }
    ll c = v.size()-k+1; // maximum 'p' I can delete from v
    ll l = 0, r = v.size()-1;
    while(l < r){
        if(v[l] == v[r]){
            l++; r--;
            continue;
        }
        if(v[l] == p && c){
            l++; c--;
        }
        else if(v[r] == p && c){
            r--; c--;
        }else{
            no; 
            return;
        }
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
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
    vi b;
    for(ll i = 0; i < n; ){
        ll c = 0, j = i;
        while(j < n && a[j] > 0){
            c++; j++;
        }
        b.push_back(c); // count of +ve
        i = j+1;
    }
    if(a.back() < 0) b.push_back(0);
    vi pref(b.size()+1);
    ll oddSum = 0, evenSum = 0;
    ll x = 0;
    for(ll i = 1; i < pref.size(); i++){
        if(i&1){
            oddSum += b[i-1];
            pref[i] = oddSum;
        }else{
            evenSum += b[i-1];
            pref[i] = evenSum;
        }
    }
    //cout << pref.size() << " " << endl;
    for(ll i = 1; i < pref.size(); i++){
        //cout << pref[i] << endl;
        if(i&1){
            ll c = (pref.size()-i)/2;
            ll k = evenSum - pref[i-1];
            x += c*b[i-1]+k+k*b[i-1]+c;
            //cout << c << " " << k << " " << x << endl;
        }else{
            ll c = (pref.size()-i)/2;
            ll k = oddSum - pref[i-1];
            x += c*b[i-1]+k+k*b[i-1]+c;
        }
    }
    cout << x << " " << n*(n+1)/2 - x << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}
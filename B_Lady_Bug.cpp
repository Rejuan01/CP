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
    ll n;
    string a, b;
    cin >> n >> a >> b;
    ll c1 = 0, c2 = 0;
    ll s1 = 0, s2 = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] == '1'){
            if(i&1) c1++;
            else c2++;
        }
    }
    for(ll i = 0; i < n; i++){
        if(b[i] == '0'){
            if(i&1) s1++;
            else s2++;
        }
    }
    if(s2 >= c1 && s1 >= c2) yes;
    else no;

    
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
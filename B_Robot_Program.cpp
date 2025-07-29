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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll p = x;
    ll c = 0;
    ll ans = 0;
    for(char ch: s){
        c++;
        if(ch == 'L'){
            --p;
        }else{
            ++p;
        }
        if(p == 0){
            ans++;
            break;
        }
    }
    if(ans == 0){
        cout << ans << endl; return;
    }
    k -= c;
    c = 0;
    //bool flag = 
    for(char ch: s){
        c++;
        if(ch == 'L'){
            --p;
        }else{
            ++p;
        }
        if(p == 0){
            ans += k/c;
            break;
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
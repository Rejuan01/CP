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
    string x;
    cin >> n >> x;
    map<ll, ll, greater<ll>> mp;
    for(auto ch: x){
        ll k = ch - '0';
        if(k < 2) continue;
        // for(ll i = 2; i < k && i < 8; i++){
        //     mp[i]++;
        // } 
        if(k == 4){
            mp[2] += 2;
            k--;
        }
           // Increase the number of digits in these cases
        else if(k == 6){
            mp[3]++;
            k--;
        }
        else if(k == 8){
            mp[2] += 3;
            k--;
        }
        else if(k == 9){
            mp[3] += 2;
            mp[2]++;
            k -= 2;
        }
        mp[k]++;
    }
    
    ll c = 0;
    for(auto &[p, q] : mp){
        //cout << p << " " << q << endl;
        //q -= c;
        ll k = q;
        while(k--){
            cout << p;
        }
        //c += q;
    }
    cout << endl;
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
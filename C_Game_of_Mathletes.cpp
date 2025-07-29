#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll fun(map<ll, ll> &mp, ll &k){
    ll count = 0;
    for(auto &it : mp){
        if(!it.second) continue;
        int val = it.first;
        int z = k-val;
        if(mp.find(z) == mp.end()){
            count += it.second;
            mp[val] = 0;
        }else if(mp[z] < mp[val]){
            count += (mp[val] - mp[z]);
            mp[val] = mp[z];
        }else if(mp[z] > mp[val]){
            count += (mp[z] - mp[val]);
            mp[z] = mp[val];
        }
    }
    return count;
}
void solve(){
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
         ll temp;
         cin >> temp;
         mp[temp]++;
    }
    ll val = fun(mp, k);
    cout << (n-val)/2 << endl;
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
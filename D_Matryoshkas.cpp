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
    map<ll, ll> v;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v[temp]++;
    }
    ll count = 0; // count of sets
    while(v.size()){
        for(auto it = v.begin(); it != v.end(); ){
            it->second--;
            if(next(it) == v.end() || next(it)->first != it->first+1){
                count++;     // next size is not in sequence or no element left then end of a set
            } 
            if(it->second == 0){ 
                it = v.erase(it); continue;
            }
            ++it;
        }
    }
    cout << count << endl;
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
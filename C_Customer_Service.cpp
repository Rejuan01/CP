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
    vi res;
    for(ll i = 0; i < n; i++){
        ll count = 0;
        for(ll j = 0; j < n; j++){
            ll temp;
            cin >> temp;
            if(temp == 1){ // count of last consecuetive ones
                count++;
            }else{
                count = 0;
            }
        }
        if(count) res.push_back(count);
    }
    sort(res.begin(), res.end());
    ll q = 1;
    for(ll i = 0; i < res.size(); i++){
        if(res[i] >= q){
            q++;
        }
    }
    if(q == n+1){
        cout << n << endl;
    }else{              
        cout << q << endl;
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
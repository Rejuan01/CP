#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        a.push_back({temp, i});
    }
    sort(a.begin(), a.end(), [&](pair<ll, ll>x, pair<ll, ll>y){
        return x.first < y.first;
    });
    vi res(n, -1);
    ll count = -1, sum = 0;
    for(auto it = a.begin(); it != a.end(); ++it){
        auto temp = it;
        count++;
        sum += (temp->first);
        if(next(temp)!=a.end() && sum >= (next(temp)->first)) continue;
        while(temp != a.begin() && res[temp->second] == -1){
            res[temp->second] = count;
            --temp;
        }
        if(temp == a.begin() && res[temp->second] == -1){
            res[temp->second] = count;
        }
    }
    for(auto it : res){
        cout << it << " ";
    } cout << endl;

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
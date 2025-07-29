#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, x;
    cin >> n >> x;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        mp[temp]++;
    }
    vector<pair<ll, ll>> v;
    for(auto &it : mp){
        v.push_back(it); // map already sorted in ascending
    }
    ll h1 = v[0].first; // smallest height of wall
    ll w = 0; // water
    ll width = 0;
    for(ll i = 0; i < v.size()-1; i++){
        ll h = v[i+1].first - v[i].first; // add water till next level piller
        width += v[i].second;
        ll add = h*width;
        if(w+add >= x){
            h1 += (x-w)/width; // needed area(water)/ width = needed height
            cout << h1 << endl; return;
        }
        w += add;
        h1 = v[i+1].first; // h1 += h
    }
    ll need = x-w; // filled till the largest piller, still need more
    h1 += need/n;
    cout << h1 << endl;
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
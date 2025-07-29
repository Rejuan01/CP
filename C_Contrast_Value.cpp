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
    vi a;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(i == 0 || (i > 0 && (temp != a[a.size()-1]))){ // ignoring consecuitive equals
            a.push_back(temp);
        }
    }
    ll count = 1;
    ll i = 0;
    n = a.size();
    while(i < n-1){
        while(i < n-1 && a[i] < a[i+1]) i++;
        if(i < n && i > 0 && a[i-1] < a[i]){
            count++;
        }
        while(i < n-1 && a[i] > a[i+1]) i++; 
        if(i < n && i > 0 && a[i-1] > a[i]){
            count++;
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
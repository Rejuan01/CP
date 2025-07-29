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
    vector<string> g(n);
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }
    vi res;
    for(int i = 0; i < n; i++){
        res.push_back(i);
    }
    sort(res.begin(), res.end(), [&](ll a, ll b){
        // swapped if condition false
        if(g[a][b] == '1') return a < b;  // g[1][3] == '1' or g[3][1] == '1' means "3 must come before 1". (smaller value first)
        else return a > b;              // else first value is greater 
    });
    for(auto it: res){
        cout << it+1 << " ";
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
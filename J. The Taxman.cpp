#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
    double x; cin >> x; 
    double k = 0;
    if(x == 0) k = 12500;
    else if(x <= 7500){
        k = 12500+x*5;
    }
    else if(x <= 27500){
        k = 50000+(x-7500)/0.4;
    }
    else if(x <= 42500){
        k = 100000 + (x-27500)/0.6; 
    }
    else if(x <= 52500){
        k = 100000 + (x-27500- (12500*.4))/0.4;
    }
    else{
        k = 150000 + (x-47500 - (12500*0.4))/0.45;
    }
    cout << fixed << setprecision(6) << k << endl; return;
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
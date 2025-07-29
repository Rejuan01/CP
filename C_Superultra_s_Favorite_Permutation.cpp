#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n;
    cin >> n;
    if(n < 5){
        cout << -1 << endl;
        return;
    }
    vi ans;
    ans.push_back(2);
    for(int i = 6; i <= n; i+=2){
        ans.push_back(i);
    }
    ans.push_back(4);
    ans.push_back(5);
    ans.push_back(1);
    ans.push_back(3);
    for(int i = 7; i <= n; i+=2){
        ans.push_back(i);
    }
    for(int it: ans){ // all even(accept 4), 4, 5, all odd (accept 5)
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
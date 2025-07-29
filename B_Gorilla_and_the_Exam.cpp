#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vi f;
    //vi a;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        //a.push_back(temp);
        mp[temp]++;
    }
    int ans = mp.size();
    for(const auto &[v, c] : mp){
        f.push_back(c);
    }
    sort(f.begin(), f.end());
    for(int i = 0; i < f.size()-1; i++){
        if(f[i] <= k){
            k -= f[i];
            ans--;
        }else{
            break;
        }
    }
    cout << ans << endl;

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
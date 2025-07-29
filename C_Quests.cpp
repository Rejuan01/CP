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
    vi a, b;
    vector<ll> sum;
    ll s = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
        s += temp;
        sum.push_back(s);
    }
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    vi maxB(n);
    maxB[0] = b[0];
    for(int i = 1; i < n; i++){
        maxB[i] = max(maxB[i-1], b[i]);
    }
    ll maxExp = LLONG_MIN;
    for(int i = 1; i <= n && i <= k; i++){
        ll exp = sum[i-1];          // in the case of unlocking 'i' quests
        ll x = maxB[i-1];           // max second attempt exp for 0-i quests(unlocked quests)
        exp += (k-i)*x;
        maxExp = max(maxExp, exp);
    }
    cout << maxExp << endl;
}
int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
 return 0;
}
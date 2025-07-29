#include<bits/stdc++.h>
using namespace std;
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1); // dp[i] = min steps for i
    for(int i = 1; i <= n; i++){
        int x = i;
        int m = 1e9;
        while(x){
            int k = x%10;
            if(k) m = min(m, dp[i-k]);
            x /= 10;
        }
        dp[i] = m+1;
    }
    cout << dp[n] << endl;
    return 0;
}
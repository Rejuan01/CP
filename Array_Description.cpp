#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int32_t main(){
    int n, m; 
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    // vector<vector<int>> dp(n+1, vector<int>(m+2)); // dp[i][j] = no of ways to get i th element as j

    // SPACE OPTIMIZATION
    vector<int> prev(m+2); // dp[i-1]
    if(a[1] != 0) prev[a[1]] = 1;
    else for(int i = 1; i <= m; i++) prev[i] = 1;

    for(int i = 2; i <= n; i++){
        vector<int> current(m+2); // //dp[i]
        int x = a[i];
        if(x){
            current[x] = prev[x] + prev[x-1] + prev[x+1];
            current[x] %= mod;
        }
        else
        for(int j = 1; j <= m; j++){
            current[j] = prev[j] + prev[j-1] + prev[j+1];
            current[j] %= mod;
        }
        prev = current;
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) ans = (ans + prev[i])%mod; // no fo ways to ge any last element
    cout << ans << endl;
    return 0;
}
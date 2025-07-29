#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    vector<vector<int>> DP(n+1, vector<int>(x+1));

    for(int i = 0; i < n; i++) cin >> a[i];
    // sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) DP[i][0] = 1;
    for(int i = n-1; i >= 0; i--){
        for(int j = 1; j <= x; j++){
            DP[i][j] = DP[i+1][j];
            if(j >= a[i]) DP[i][j] += DP[i][j-a[i]]; 
            DP[i][j] %= mod;
        }
    }
    cout << DP[0][x] << endl;

}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+2, vector<int>(m+2, 0)); // extra outer layer of zeros
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x = max({a[i-1][j], a[i][j-1], a[i+1][j], a[i][j+1]});
            if(a[i][j] > x){
                a[i][j] = x;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        } cout << endl;
    }
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
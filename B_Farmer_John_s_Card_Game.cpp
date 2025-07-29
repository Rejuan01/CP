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
    vector<vector<int>> c(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }
    vi ans;
    for(int i = 0; i < n; i++){
        ans.push_back(i);
        sort(c[i].begin(), c[i].end());
    }
    for(int j = 0; j < m; j++){
        vector<int> v;
        for(int i = 0; i < n; i++){
            v.push_back(c[i][j]);
        }
        int min = *min_element(v.begin(), v.end());
        int max = *max_element(v.begin(), v.end());
        if(min != j*n || max != (j+1)*n-1){
            cout << -1 << endl;
            return;
        }
        vi temp = ans;
        sort(temp.begin(), temp.end(), [&](int a, int b){
            return c[a][j] < c[b][j];
        });
        if(j == 0) ans = temp;
        if(ans != temp){
            cout << -1 << endl;
            return;
        }
    }
    for(int it: ans){
        cout << it+1 << " ";
    }cout << endl;
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
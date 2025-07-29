#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vi b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    while(q--){
        int a;
        cin >> a;
        if(a < b[0]){
            cout << b[0]-1 << endl;
            continue;
        }else if(a > b[m-1]){
            cout << (n-1)-b[m-1]+1 << endl;
            continue;
        }
        auto it = lower_bound(b.begin(), b.end(), a);
        int y = *it;
        --it;
        int x = *it;
        cout << (y-x)/2 << endl;
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
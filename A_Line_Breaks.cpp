#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> vct(n);
        for(int i = 0; i < n; i++){
            cin >> vct[i];
        }
        int x = 0;
        for(int i = 0; i < n; i++){
            if(m - static_cast<int>(vct[i].size()) < 0){
                break;
            }
            m -= static_cast<int>(vct[i].size());
            
            x++;
        }
        cout << x<< endl;
    }
}
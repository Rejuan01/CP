#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> res;
        vector<bool> mark(n, 0);
        res.push_back(1);
        mark[0] = 1;
        for(int i = 2; i <= n; i++){
            if(mark[i-1]) continue;
            for(int j = i; j <= n; j*=2){
                res.push_back(j);
                mark[j-1] = 1;
            }
        }
        for(int it : res){
            cout << it << " ";
        }
        cout << endl;
    }
}
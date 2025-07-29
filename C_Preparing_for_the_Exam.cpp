#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        unordered_set<int> stA;
        vector<int> a(m);
        vector<int> q(k);
        for(int i = 0; i < m; i++){
            cin >> a[i];
            stA.insert(a[i]);
        }
        int ind;
        bool flag = true;
        for(int i = 0; i < k; i++){
            cin >> q[i];
            if(flag && i+1 != q[i]){
                ind = i+1;
                flag = false;
            }
        }
        if(flag){
            ind = n;
        }
        string result = "";
        if(k == n){
            for(int i = 0; i < m; i++){
                result.push_back('1');
            }
            cout << result << endl;
            continue;
        }
        for(int i = 0; i < m; i++){
            result.push_back('0');
        }
        if(k < n-1){
            cout << result << endl;
            continue;
        }

        if(stA.find(ind) != stA.end()){
            for(int i = 0; i < m; i++){
                if(a[i] == ind){
                    result[i] = '1';
                    break;
                }
            }
            cout << result << endl;
        }else{
            cout << result << endl;
        }


        
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int, int> count;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            count[temp]++;
        }
        bool flag = false;
        for(const auto &[v, c]: count){
            if(c > 1){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
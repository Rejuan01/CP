#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool flag = true;
        for(int i = 0; i < n-1 && flag; i++){
            if(a[i]*2 > a[i+1] && a[i+1]*2 > a[i]){
                flag = false;
            }
        }
        if(!flag){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
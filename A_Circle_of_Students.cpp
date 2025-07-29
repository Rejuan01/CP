#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> a(n);
        int start; // index for 1
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1){
                start = i;
            }
        }
        if(n == 1){
            cout << "YES" << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            a.push_back(a[i]);
        }
        bool flag = true;
        for(int i = start; i <= n; i++){
            if(is_sorted(a.begin()+i, a.begin()+i+n) || is_sorted(a.begin()+i, a.begin()+i+n, greater<int>())){
                cout << "YES" << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "NO" << endl;
        }
    }

}
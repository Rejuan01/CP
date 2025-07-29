#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        vector<int> p;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ptr1 = 0, ptr2 = 0;
        bool flag = false;
        while(ptr2 < n){
            if(ptr2 == n-1){
                flag = true;
                break;
            }
            while(ptr2 < n-1 && a[ptr2+1] == a[ptr1]){
                ptr2++;
            }
            if(ptr2 == ptr1){
                flag = true;
                break;
            }
            p.push_back(ptr2+1);
            while(ptr1 < ptr2){
                p.push_back(++ptr1);
            }
            ptr1 = ++ptr2;
        }
        if(flag){
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            cout << p[i] << " ";
        }
        cout << endl;
    }

}
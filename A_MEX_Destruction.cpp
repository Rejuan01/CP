#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        bool allZero = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(allZero && a[i]){
                allZero = false;
            }
        }
        if(allZero){
            cout << 0 << endl;
            continue;
        }
        int ptr1 = 0, ptr2 = n-1;
        while(a[ptr1] == 0){ // find first non-zero
            ptr1++;
        }
        while(a[ptr2] == 0){ // last non-zero
            ptr2--;
        }
        bool flag = false;
        while(ptr1 <= ptr2){ // if any zero in between them
            if(a[ptr1] == 0){
                flag = true;
                break;
            }
            ptr1++;
        }
        if(flag){
            cout << 2 << endl;
        }else{
            cout << 1 << endl;
        }
    }
}
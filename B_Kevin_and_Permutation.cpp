#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> num;
        for(int i = 0; i < n; i++){
            num.push_back(i+1);
        }
        int ptr1 = 0, ptr2 = n-1;
        //vector<int> result;
        while(ptr1 <= ptr2){
            int p = k-1;
            while(p-- && ptr2 > ptr1){
                //result.push_back(num[ptr2--]);
                cout << num[ptr2--] << " ";
            }
            //result.push_back(num[ptr1++]);
            cout << num[ptr1++] << " ";
        }
        // for(int i = 0; i < n; i++){
        //     cout << num[i] << " ";
        // }
        cout << endl;
    }
}
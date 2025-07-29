#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, d, w;
        cin >> n >> k >> d >> w;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int count = 0;
        int ptr = 0;
        int ptr2;
        while(ptr < n){
            ptr2 = ptr;
            while(ptr2+1 < n && ptr2 +1 - ptr <= k-1 && a[ptr2+1] - a[ptr] <= d + w){
                ptr2++;
                
            }
            count++;
            ptr = ptr2+1;
        }
        cout << count << endl;
    }
}
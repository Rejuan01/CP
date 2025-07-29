#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, d;
        cin >> n >> k >> d;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int min = d;
        for(int i = 0; i <= n-d; i++){
            bool flag[k] = {0};
            int temp = 0;
            for(int j = i; j < i+d; j++){
                if(!flag[a[j] - 1]){
                    flag[a[j] - 1] = true;
                    temp++;
                }
            }
            if(temp < min){
                min = temp;
            }
        }
        cout << min << endl;
    }
}
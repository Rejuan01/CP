#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string stripe;
        cin >> stripe;
        int count = 0;
        for(int j = 0; j < k; j++){
            if(stripe[j] == 'W'){
                count++;
            }
        }
        if(!count || n == k){
            cout << count << endl;
            continue;
        }
        int minCount = count;
        for(int i = 1; i <= n-k; i++){
            if(stripe[i-1] == 'W'){
                count--;
            }
            if(stripe[i+k-1] == 'W'){
                count++;
            }
            if(minCount > count){
                minCount = count;
            }
            if(!count){
                cout << 0 << endl;
                break;
            }
        }
        if(minCount){
            cout << minCount << endl;
        }
    }
}
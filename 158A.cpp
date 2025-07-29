#include<iostream>
using namespace std;
int main(){
    int n, k, count = 0;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > 0){count++;}
    }
    if(count <= k){ 
        cout << count << endl;
    }
    else{
        while(1){
            if(a[k-1] == a[k]){
                k++;
            }
            else{
                break;
            }
        }
        cout << k << endl;
    }
    
}
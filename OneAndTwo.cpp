#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t ; i ++){
        int n;
        int count = 0;
        cin >> n;
        int a[n];
        int T = 1, H = 1;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            if(a[i] == 2){
                count ++;
            }
        }
        if(count % 2 == 1){
            cout << -1 << endl;
            continue;
        }
        
        int c = 0;
        for(int j = 0; j < n-1; j++){
            if(a[j] == 2){ c++; }
            if(c == count/2){
                cout << j+1 << endl;
                break;
            }
        }
    }
    return 0;
}
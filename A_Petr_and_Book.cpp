#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin >> n;
    int a[7];
    int count = 0;
    for(int i = 0; i < 7; i++){
        cin >> a[i];
        count += a[i];
    }
    int x = n/count; 
    if(n%count == 0){
        x--;
    }
    for(int i = 0; i <= x ; i++){
        for(int j = 0; j < 7; j++){
            n -= a[j];
            if(n <= 0){
                cout << j+1 << endl;
                return 0;
            }
        }
    }
}
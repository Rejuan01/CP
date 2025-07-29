#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int flag = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 0){
            a[i] /= 2;
            cout << a[i] << endl;
        }
        else{
            if(flag){
                a[i]++;
                a[i] /= 2;
                flag = 0;
                cout << a[i] << endl;
            }
            else{
                a[i]--;
                a[i] /= 2;
                flag = 1;
                cout << a[i] << endl;
            }
        }
    }
}
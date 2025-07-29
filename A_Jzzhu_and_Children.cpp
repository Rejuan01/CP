#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int scale = 0; //max times need to repeat the process
    int index = 0;
    for(int i = 0; i < n; i++){
        if((a[i]-1)/m > scale){
            scale = (a[i]-1)/m;
            index = i;
        }
        else if((a[i]-1)/m == scale){
            index = i;    //though equal in scale, get the higher index
        }
    }
    cout << index+1 << endl;
}
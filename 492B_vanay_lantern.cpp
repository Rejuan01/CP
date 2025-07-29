#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, l;
    cin >> n >> l;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    int d = 0;
    for(int i = 0; i < n-1; i++){
        if((a[i+1]-a[i]) > d){
            d = a[i+1] - a[i];
        }
    }
    int m;
    if(a[0] > (l-a[n-1])){
        m = a[0];
    }
    else{
        m = l - a[n-1];
    }
    if(2*m > d){
        cout << m;
    }
    else{
        cout << fixed << setprecision(10)<< d/2.0;
    }
}
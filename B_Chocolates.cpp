#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long int sum = a[n-1];
    long long int taken = a[n-1];
    for(int i = n-2; i >=0 && taken > 0; i--){
        if(a[i] < taken){
            taken = a[i];
            sum += taken;
        }
        else{
            taken--;
            sum += taken;
        }
    }
    cout << sum << endl;
}
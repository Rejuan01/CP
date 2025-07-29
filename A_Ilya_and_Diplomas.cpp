#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, min1, min2, min3, max1, max2, max3;
    cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
    int t = min1+min2+min3;
    while(t < n && min1 < max1){
        t++;
        min1++;
    }
    while(t < n && min2 < max2){
        t++;
        min2++;
    }
    while(t < n && min3 < max3){
        t++;
        min3++;
    }
    cout << min1 << " " << min2 << " " << min3 << endl;
}
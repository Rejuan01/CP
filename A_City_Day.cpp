#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int minIndx = 0;
    for(int i = 1; i <= y && i < n; i++){
        if(a[i] < a[minIndx]){
            minIndx = i;
        }
    }
    if(minIndx == 0 || y >= n-1){
        cout << minIndx+1 << endl;
        return 0;
    }
    int ptr = y+1;

    while(ptr < n && ptr - minIndx < y+1){
        if(a[ptr] < a[minIndx]){
            minIndx = ptr;
        }
        ptr++;
    }
    cout << minIndx+1 << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[n-1] == 0){ // max zero means all zero
        cout << 0 << endl;
        return 0;
    }
    int ptr = 0;
    while(a[ptr] == 0){
        ptr++;
    }
    cout << a[ptr] << endl;
    int count = 1;
    while(count < k && ptr < n-1){
        if(a[ptr+1] - a[ptr]){
            cout << (a[ptr+1] - a[ptr]) << endl;
            count++;
        }
        ptr++;
    }
    while(count < k){
        cout << 0 << endl;
        count++;
    }
}
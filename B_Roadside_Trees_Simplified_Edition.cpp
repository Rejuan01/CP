#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int time = 0;
    int hgt = 0;
    for(int i = 0; i < n; i++){
        if(hgt < h[i]){
            time += (h[i] - hgt + 1);
            hgt = h[i];
        }
        else{
            time += (hgt - h[i] + 1);
            hgt = h[i];
        }
    }
    time += (n-1); // jump time;
    cout << time << endl;
}
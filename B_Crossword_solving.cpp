#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int minCount = INT_MAX;
    int index;
    for(int i = 0; i <= m-n; i++){
        int c = 0;
        for(int j = 0; j < n; j++){
            if(s[j] != t[i+j]){
                c++;
            }
        }
        if(c < minCount){
            minCount = c; // minimum mismatch
            index = i;    // corresponding starting index of t
        }
    }
    cout << minCount << endl;
    for(int j = 0; j < n; j++){ // find again and print indices of s
        if(s[j] != t[index+j]){
            cout << j+1 << " ";
        }
    }
    cout << endl;
}
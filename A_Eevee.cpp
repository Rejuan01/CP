#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string eevees[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int mark[8] = {0};
    for(int i = 0; i < 8; i++){
        if(eevees[i].size() != n){
            mark[i] = 1;        // mark if lenth mismatches
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.')
            continue;
        for(int j = 0; j < 8; j++){
            if(!mark[j] && eevees[j][i] != s[i]){ // check only unmarked elements
                mark[j] = 1; // mark if i th character doesn't match
            }
        }
    }
    for(int i = 0; i < 8; i++){
        if(!mark[i]){
            cout << eevees[i] << endl;
            break;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m; 
    cin >> m;
    vector<int> c;
    int total = 0;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        c.push_back(temp);
        total += temp;
    }
    int x, y;
    cin >> x >> y;
    int group1 = 0;
    int group2 = total; // consider all passed
    for(int i = 0; i < m; i++){
        group1 += c[i];
        group2 -= c[i];
        if(group1 >= x && group1 <= y && group2 >= x && group2 <= y){
            cout << i+2 << endl; // all till mark (i+1) are in group 1
            return 0;
        }
        if(group1 >= group2){ // without both coming in range g1 exceeds g2
            cout << 0 << endl;
            return 0;
        }

    }
}
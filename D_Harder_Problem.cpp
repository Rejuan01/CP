#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a;
        set<int> x; // all from 1 to n
        unordered_set<int> dst; // distinct
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            a.push_back(temp);
            x.insert(i+1);
            dst.insert(temp);
        }
        vector<int> b;
        for(int i = 0; i < n; i++){
             int temp = a[i];
            if(dst.find(temp) != dst.end()){
                dst.erase(temp);
                x.erase(temp);
                b.push_back(temp);
            }
        }
        for(int val : x){
            b.push_back(val);
        }
        for(int val : b){
            cout << val << " ";
        }
        cout << endl;

    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t; 
    while(t--){
        int n;
        cin >> n;
        //vector<int> a(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            mp[temp]++;
        }
        if(mp.size() > 2){
            cout << "No" << endl;
            continue;
        }
        if(mp.size() == 1){
            cout << "Yes" << endl;
            continue;
        }
        auto it = mp.begin();
        int x = it->second;
        ++it;
        int y = it->second;
        if(x-y > 1 || y-x > 1){
            cout << "No" << endl;
        }else{
            cout << "YesA_D" << endl;
        }
    }
}
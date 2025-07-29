#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin >> m;
    map<int, int> mp;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        mp[temp]++; // keeps the count of each element
    }
    vector<int> stair;
    for(auto it = mp.begin(); it != prev(mp.end()); it++){ // before the last value(max value) if frequency > 1 
        if(it->second > 1){
            stair.push_back(it->first);
        }
    }
    for(auto it = mp.rbegin(); it != mp.rend(); ++it){ //all from max to min once
        stair.push_back(it->first);
    }
    cout << stair.size() << endl;
    for(auto it : stair){
        cout << it << " ";
    }
    cout << endl;

}
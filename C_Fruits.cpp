#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> prize(n);
    for(int i = 0; i < n; i++){
        cin >> prize[i];
    }
    sort(prize.begin(), prize.end());
    unordered_map<string, int> fruit;
    for(int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        fruit[temp]++;
    }
    vector<int> count;
    for(const auto &item : fruit){
        count.push_back(item.second);
    }
    int minCost = 0;
    int maxCost = 0;
    sort(count.begin(), count.end(), greater<int>());
    for(int i = 0; i < count.size(); i++){
        minCost += count[i]*prize[i]; 
    }
    for(int i = 0; i < count.size(); i++){
        maxCost += count[i]*prize[n-1-i];
    }
    cout << minCost << " " << maxCost << endl;
        
    
}
#include<bits/stdc++.h>
using namespace std;

bool isProduct(vector<int> &x, unordered_set<int> &st, int n){
    if(st.find(n) != st.end()){
        return true;
    }
    for(int it: x){
        if(it == 1 || n%it != 0) continue;
        int n1 = n/it;
        if(isProduct(x, st, n1)){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    vector<int> x;
    x.push_back(1);
    for(int i = 0; x.size() < 31; i++){ // 31 possible binary decimal
        x.push_back(x[i]*10);
        x.push_back(x[i]*10+1);
    }
    unordered_set<int> st;
    for(auto it: x){
        st.insert(it);
    }
    while(t--){
        int n;
        cin >> n;
        if(isProduct(x, st, n)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
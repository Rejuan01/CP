#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int k;
    cin >> s;
    cin >> k;
    set<int> st;
    for(int i = 0; i < s.size(); i++){
        st.insert(s[i]);
    }
    if(s.size() < k){
        cout << "impossible" << endl;
        return 0;
    }
    if(st.size() >= k){
        cout << 0 << endl;
    }
    else{
        cout << k-st.size() << endl;
    }
}
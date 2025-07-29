#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> count;
    count.push_back(0); // min count
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        if(isupper(s[i]))
            continue;
        int j;
        for(j = i; j < n && islower(s[j]); j++){
            st.insert(s[j]);
        }
        int c = st.size(); // number of distinct lower letter within two upper or string limit
        count.push_back(c);
        st.clear();
        i = j; // will be ++ again in loop
    }
    int m = *max_element(count.begin(), count.end());
    cout << m << endl;
}
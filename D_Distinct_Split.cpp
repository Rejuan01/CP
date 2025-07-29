#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        vector<int> ans;
        unordered_set<char> st;
        int count = mp.size(); // total distinct characters
        for(auto ch: s){
            st.insert(ch);
            if(--mp[ch] == 0) count--; // if remaining right parts has no 'ch', distinct count for right decreases
            ans.push_back(count+st.size());
        }
        cout << *max_element(ans.begin(), ans.end()) << endl;
    }
}
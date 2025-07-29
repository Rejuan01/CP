#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> l(n);
        vector<int> r(n);
        vector<int> ck(2*n+1, 0);
        string res = "";
        set<int> st;
        vector<int> p; 
        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
            if(l[i] == r[i]){
                ck[l[i]]++;
                st.insert(l[i]);
            }
        }
        for(int it: st){
            p.push_back(it);
        }
        //sort(p.begin(), p.end());
        for(int i = 0; i < n; i++){
            if(l[i]==r[i]){
                if(ck[l[i]] > 1){
                    res.push_back('0');
                }else{
                    res.push_back('1');
                }continue;
            }
            int low=lower_bound(p.begin(),p.end(),l[i])-p.begin(); // first index >=l[i]
	        int up=lower_bound(p.begin(),p.end(),r[i]+1)-p.begin();// last index > r[i]
	        int len=up-low;
 
	        if(len==r[i]-l[i]+1){ // all values in the range exists in p
	            res.push_back('0');
	        }
	        else{
	            res.push_back('1');
	        }
        }
        cout << res << endl;
    }
}
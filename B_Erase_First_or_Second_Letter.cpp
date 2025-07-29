#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n;
    string s;
    cin >> n >> s;
    ll count = 0;
    unordered_set<int> st;
    for(char ch : s){
        st.insert(ch);
        count += st.size();
    }
    cout << count << endl;
}
int main(){
   int t;
   cin >> t;
   while(t--){
      solve();
   }
 return 0;
}
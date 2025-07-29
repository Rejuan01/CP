#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    int x = a1+a2;
    int y = a4-a2;
    int z = a5-a4;
    set<int> st;
    st.insert(x);
    st.insert(y);
    st.insert(z);
    if(st.size() == 1){
        cout << 3 << endl;
    }else if(st.size() == 2){
        cout << 2 << endl;
    }else{
        cout << 1 << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
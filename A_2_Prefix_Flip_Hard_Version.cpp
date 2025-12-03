#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void flip(char &c){
    if(c == '0') c++;
    else c--;
}
void solve(){
    ll n, c = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if(n == 1){
        if(a == b) cout << 0 << endl;
        else cout << "1 1" << endl; 
        return;
    }
    vi ans;
    deque<char> q;
    for(ll i = 1; i < n; i++) q.push_back(a[i]);
    for(ll i = n-1; i >= 0; i--){
        char ai;
        if(i == 0) ai = a[0];
        else if(c&1){
            ai = q.front();
            q.pop_front();
            flip(ai);
        }
        else{
            ai = q.back();
            q.pop_back();
        }
        // cout << "  " << b[i] << endl;
        // cout << a[0] << " " << ai << endl;
        if((ai == b[i] && a[0] == ai) || (ai != b[i] && a[0] != ai)){
            ans.pb(1);
        }
        ans.pb(i+1);    // always do this to make track of a[i] easily
        flip(ai);
        a[0] = ai;
        c++;
    }
    cout << ans.size() << " ";
    for(auto &it: ans) cout << it << " ";
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
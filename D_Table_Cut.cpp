#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    vi s(m);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
            s[j] += a[i][j];
            sum += a[i][j];
        }
    }
    cout << (sum+1)/2*(sum/2) << endl;
    sum /= 2;
    ll x = 0, i = 0, j = 0;
    while(x < sum){
        if(x+s[j] <= sum){
            x += s[j++];
            cout << 'R';
        }
        else{
            ll d = s[j]-(sum-x);
            while(d){
                d -= a[i++][j];
                cout << 'D';
            }
            cout << 'R';
            j++;
            break;
        }
    }
    while(i < n){
        cout << 'D';
        i++;
    }
    while(j < m){
        cout << 'R';
        j++;
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}
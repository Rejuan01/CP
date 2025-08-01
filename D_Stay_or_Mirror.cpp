#include<bits/stdc++.h>
using namespace std;
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
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(ll k = 1; k <= n; k++){
        ll c = 0; // how many numbers before k are greater than k
        ll i = 0;
        while(i < n && a[i] != k){
            if(a[i] && a[i] > k) c++;
            i++;
        }
        ans += min(c, n-k-c);  // min inversion for k and 2n-k
        a[i] = 0; // inversion with k need not to be considered later
    }
    cout << ans << endl;
}
// in every step, k is the minimum and 2n-k is the maximum among all possibilities in the remaining permutation
// so inversion for k is the number of its left elements and inversion for 2n-k is the number of it's right elements
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
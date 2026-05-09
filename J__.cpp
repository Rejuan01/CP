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
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    vi p;
    vector<long double> a(8), b(8);
    for(ll i = 0; i < 8; i++) cin >> a[i] >> b[i];
    for(ll i = 0; i < 8; i++) p.pb(i);
    long double ans = 0.000000000000;
    do{
        // for(auto it: p) cout << it << " ";
        // cout << endl;
        vi tm(8);
        for(ll i = 0; i < 8; i++) tm[i] = i;
        sort(tm.begin(), tm.end(), [&](ll i, ll j){
            return p[i] < p[j];
        });
        
        vector<long double> a1(8), a2(8), a3(8); // probability to win the 1st, 2nd & 3rd match
        // first
        for(ll i = 0; i < 8; i++){                  
            if(i&1){
                a1[tm[i]] = b[tm[i]]/(a[tm[i-1]]+b[tm[i]]);
            }
            else a1[tm[i]] = a[tm[i]]/(a[tm[i]]+b[tm[i+1]]);
        }

        // second
        // a2[tm[0]] = (a1[tm[2]]*(a[tm[0]]/(a[tm[0]]+b[tm[2]])) + a1[tm[3]]*(a[tm[0]]/(a[tm[0]]+b[tm[3]])))*a1[tm[0]];
        // a2[tm[1]] = (a1[tm[2]]*(a[tm[1]]/(a[tm[1]]+b[tm[2]])) + a1[tm[3]]*(a[tm[1]]/(a[tm[1]]+b[tm[3]])))*a1[tm[1]];

        // a2[tm[2]] = (a1[tm[0]]*(b[tm[2]]/(a[tm[0]]+b[tm[2]])) + a1[tm[1]]*(b[tm[2]]/(a[tm[1]]+b[tm[2]])))*a1[tm[2]];
        // a2[tm[3]] = (a1[tm[0]]*(b[tm[3]]/(a[tm[0]]+b[tm[3]])) + a1[tm[1]]*(b[tm[3]]/(a[tm[1]]+b[tm[3]])))*a1[tm[3]];

        // a2[tm[4]] = (a1[tm[6]]*(a[tm[4]]/(a[tm[4]]+b[tm[6]])) + a1[tm[7]]*(a[tm[4]]/(a[tm[4]]+b[tm[7]])))*a1[tm[4]];
        // a2[tm[5]] = (a1[tm[6]]*(a[tm[5]]/(a[tm[5]]+b[tm[6]])) + a1[tm[7]]*(a[tm[5]]/(a[tm[5]]+b[tm[7]])))*a1[tm[5]];

        // a2[tm[6]] = (a1[tm[4]]*(b[tm[6]]/(a[tm[4]]+b[tm[6]])) + a1[tm[5]]*(b[tm[6]]/(a[tm[5]]+b[tm[6]])))*a1[tm[6]];
        // a2[tm[7]] = (a1[tm[4]]*(b[tm[7]]/(a[tm[4]]+b[tm[7]])) + a1[tm[5]]*(b[tm[7]]/(a[tm[5]]+b[tm[7]])))*a1[tm[7]];

        for(ll i = 0; i < 2; i++){
            for(ll j = 2; j < 4; j++){
                a2[tm[i]] += a1[tm[j]]*(a[tm[i]]/(a[tm[i]]+b[tm[j]]));  
            }
            a2[tm[i]] *= a1[tm[i]];
        }
        for(ll i = 2; i < 4; i++){
            for(ll j = 0; j < 2; j++){
                a2[tm[i]] += a1[tm[j]]*(b[tm[i]]/(a[tm[j]]+b[tm[i]]));  
            }
            a2[tm[i]] *= a1[tm[i]]; 
        }

        for(ll i = 4; i < 6; i++){
            for(ll j = 6; j < 8; j++){
                a2[tm[i]] += a1[tm[j]]*(a[tm[i]]/(a[tm[i]]+b[tm[j]]));  
            }
            a2[tm[i]] *= a1[tm[i]];
        }
        for(ll i = 6; i < 8; i++){
            for(ll j = 4; j < 6; j++){
                a2[tm[i]] += a1[tm[j]]*(b[tm[i]]/(a[tm[j]]+b[tm[i]]));  
            }
            a2[tm[i]] *= a1[tm[i]]; 
        }

        // third
        for(ll i = 0; i < 4; i++){
            for(ll j = 4; j < 8; j++){
                a3[tm[i]] += a2[tm[j]]*(a[tm[i]]/(a[tm[i]]+b[tm[j]]));  
            }
            a3[tm[i]] *= a2[tm[i]];
        }
        for(ll i = 4; i < 8; i++){
            for(ll j = 0; j < 4; j++){
                a3[tm[i]] += a2[tm[j]]*(b[tm[i]]/(a[tm[j]]+b[tm[i]]));  
            }
            a3[tm[i]] *= a2[tm[i]];  
        }
        ans = max(ans, a3[0]);
    }
    while(next_permutation(p.begin(), p.end()));

    cout << fixed << setprecision(9) << ans << endl; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
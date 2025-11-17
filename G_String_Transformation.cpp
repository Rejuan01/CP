#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define yes cout << "YES" << endl 
#define no cout << "NO" << endl 
#define pb push_back
#define l_b lower_bound
#define u_b upper_bound
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set; //order_of_key(), find_by_order()


/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

void solve()
{
    // Do your thing here :)
 	string s;
 	cin >> s;
 		
 	ll ans = 0, n = s.size();
 	for(char c='a'; c<='z'; c++) {
        // cout << c << endl;
 		vl seg;
 		int i=0;
 		while(i<n) {
            int len = 0;
            // cout << i << " : " << endl;
            int j=i;
            for(; j<n; j++) {
                if(s[j]!=c) {
                    // cout << j << endl;
                    break;
                }
                else len++;
            }
            if(len) {
                seg.push_back(len);
                // cout << len << endl;
            }
 			i = j+1;
 		}
 		ll tmp = 0;
        //cout << seg.size() << endl;
        for(int k=seg.size()-1; k>=0; k--) {
            ans += seg[k];
            ans += (tmp*seg[k]);
            tmp += seg[k];
        }
 			//cout << ans << endl;
 	}   
 	cout << ans+1 << endl;
}

/* Hey you should check this out
    * int overflow, array bounds
    * reset global array and variable
    * look for special cases (n=1?)
    * Think about multiple minimum and maximum
    * do something instead of nothing and stay organized
    * bruteforce to find pattern
    * DON'T GET STUCK ON ONE APPROACH
    * Think the problem backwards
    * In practice time don't see failing test case
*/

int main()
{

    _fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
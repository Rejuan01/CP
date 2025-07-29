#include <bits/stdc++.h>
using namespace std;

long long int maxProf(long long int a, long long int  b, long long int  n, long long int  k)
{
    return (n - k) * a + k * (b + 1) - k * (k + 1) / 2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, a, b;
        cin >> n >> a >> b;
        if (b <= a)
        {
            cout << n * a << endl;
            continue;
        }
        else
        {
            long long int m1 = maxProf(a, b, n, b - a);
            long long int m2 = maxProf(a, b, n, b - a + 1);
            cout << max(m1, m2) << endl;
        }
    }
    return 0;
}
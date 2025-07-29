#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (b >= m * a)
    {
        cout << n * a << endl;
    }
    else
    {
        int r = n % m;
        if(r*a > b){
            cout << (n/m +1)*b;
        }
        else{
            cout << r * a + (n/m) * b << endl;
        }
    }

    return 0;
}
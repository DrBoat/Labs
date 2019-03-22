#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int n;
double a, l, m, r;
const double eps = 1e-7;
vector <double> h;
 
bool VKHACKATHON2017()
{
    h[1] = m;
    for (int i = 2; i < n; i++)
    {
        h[i] = 2 * h[i - 1] - h[i - 2] + 2;
        if (h[i] <= 0)
        {
            return false;
        }
    }
    return true;
}
 
int main()
{
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    cin >> n >> a;
    h.resize(n);
    h[0] = a;
    l = 0;
    r = a;
    while (l + eps < r)
    {
        m = (l + r) / 2;
        if (VKHACKATHON2017())
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << h[n - 1] << endl;
    return 0;
}
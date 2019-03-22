#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

int main()
{
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    long long n, m, s = 0;
    cin >> n;
    m = n - 1;
    vector <long long> fac(n + 1);
    fac[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    vector <bool> pr(n + 1);
    pr[0] = true;
    for (long long i = 0; i < n - 1; i++)
    {
        int tmp;
        cin >> tmp;
        int ans = 0;
        for (long long j = 1; j <= n; j++)
        {
            if (!pr[j])
                ans++;
            if (j == tmp)
            {
                s = s + fac[m--] * (ans - 1);
                pr[j] = true;
                break;
            }
        }
    }
    cout << s;
}

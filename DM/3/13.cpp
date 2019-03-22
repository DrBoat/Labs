#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    vector <long long> fac(n + 1);
    vector <bool> pr(n + 1);
    fac[0] = 1;
    for (long long i = 1; i <= n ; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    pr[0] = true;
    long long m = n - 1 ;
    for (long long i = 0; i < n - 1 ; i++)
    {
        int ans = 0;
        int c = (k / fac[m]) + 1;
        for (long long j = 1; j <= n ; j++)
        {
            if (!pr[j])
            {
                ans++;
                if (c == ans)
                {
                    c = j;
                    pr[j] = true;
                    break;
                }
            }
        }
        k %= fac[m--];
        cout << c << " ";
    }
    for (long long i = 1; i <= n ; i++)
    {
        if (!pr[i])
        {
            cout << i << " ";
            break;
        }
    }

}

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

inline long long Choose(int n, int k)
{
    if ((n == k) || (k == 0))
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }
    return Choose(n - 1, k) + Choose(n - 1, k - 1);
}

int main()
{
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    long long n, k, m, last = 0;
    cin >> n >> k >> m;
    m++;
    for (int i = 1; i <= k; i++)
    {
        for (int j = last + 1; j <= n; j++)
        {
            int c = Choose(n - j, k - i);
            if (m <= c)
            {
                cout << j << " ";
                last = j;
                break;
            }
            else
            {
                m -= c;
            }
        }
    }
    return 0;
}
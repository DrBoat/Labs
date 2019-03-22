#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

long long d[101][101];

int main()
{
    freopen("num2brackets.in", "r", stdin);
    freopen("num2brackets.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    k++;
    string ans = "";
    d[0][0] = 1;
    for (long long i = 1; i < 101; i++)
    {
        for (long long j = 0; j < 100; j++)
        {
            long long d1;
            if (j < 1) d1 = 0;
            else d1 = d[i - 1][j - 1];
            d[i][j] = d1 + d[i - 1][j + 1] ;
        }
    }
    int depth = 0;
    for (int i = n * 2 - 1; i >= 0; i--)
    {
        if (depth + 1 <= n && d[i][depth + 1] >= k)
        {
            ans += '(';
            ++depth;
        }
        else {
            ans += ')';
            if (depth+1 <= n)
            {
                k -= d[i][depth + 1];
            }
            --depth;
        }
    }
    cout << ans;
    return 0;
}
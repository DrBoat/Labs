#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

long long d[101][101];

int main()
{
    freopen("brackets2num.in", "r", stdin);
    freopen("brackets2num.out", "w", stdout);
    string psp;
    cin >> psp;
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
    long long n = 0;
    for (long long i = 0; i < psp.size(); i++)
    {
        if(psp[i] == '(') n++;
    }
    long long dep = 0, ans = 0;
    for (long long i = 0; i < psp.size(); i++)
    {
        if(psp[i] == '(') dep++;
        else
        {
            ans += d[2 * n - i - 1][dep + 1];
            dep--;
        }
    }
    cout << ans;
    return 0;
}
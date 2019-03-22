#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

long long d[101][101];

int main()
{
    freopen("num2brackets2.in", "r", stdin);
    freopen("num2brackets2.out", "w", stdout);
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
    long long depth = 0;
    vector <char> stack(n * 2);
    long long stacksz = 0;
    for (long long i = n * 2 - 1; i >= 0; i--)
    {
        long long cur;
        // '('
        if (depth+1 <= n)
            cur = d[i][depth+1] << ( (i-depth-1)/2 );
        else
            cur = 0;
        if (cur >= k) {
            ans += '(';
            stack[stacksz++] = '(';
            ++depth;
            continue;
        }
        k -= cur;
        // ')'
        if (stacksz > 0 && stack[stacksz-1] == '(' && depth-1 >= 0)
            cur = d[i][depth-1] << ( (i-depth+1)/2 );
        else
            cur = 0;
        if (cur >= k) {
            ans += ')';
            --stacksz;
            --depth;
            continue;
        }
        k -= cur;
        // '['
        if (depth+1 <= n)
            cur = d[i][depth+1] << ( (i-depth-1)/2 );
        else
            cur = 0;
        if (cur >= k) {
            ans += '[';
            stack[stacksz++] = '[';
            ++depth;
            continue;
        }
        k -= cur;
        // ']'
        ans += ']';
        --stacksz;
        --depth;
    }
    cout << ans;
    return 0;
}
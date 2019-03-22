#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;

long long n, m;

bool chek_prof(long long a, long long b)
{
	for (int i = 1; i < n; i++)
	{
		if (a & (1 << i) && a & (1 << (i - 1)) && b & (1 << i) && b & (1 << (i - 1))) return false;
		if (!(a & (1 << i) || a & (1 << (i - 1)) || b & (1 << i) || b & (1 << (i - 1)))) return false;
	}
	return true;
}

const int mxn = 1 << 6;
int d[mxn][mxn], a[40][mxn];


int main()
{
    freopen("nice.in", "r", stdin);
    freopen("nice.out", "w", stdout);
    cin >> n >> m;
    if (n > m) swap(n, m);
    for (long long i = 0; i < (1 << n); i++)
    {
    	for (long long j = 0; j < (1 << n); j++)
    	{
    		if (chek_prof(i, j))
    		{
    			d[i][j] = 1;
    		}
    		else
    		{
    			d[i][j] = 0;
    		}
    	}
    }
    for (long long i = 0; i < (1 << n); i++)
    {
    	a[0][i] = 1;
    }
    for (long long k = 1; k < m; k++)
    {
    	for (long long i = 0; i < (1 << n); i++)
    	{
    		for (long long j = 0; j < (1 << n); j++)
    		{
    			a[k][i] += a[k - 1][j]*d[j][i];
    		}
    	}
    }
    long long ans = 0;
    for (long long i = 0; i < (1 << n); i++)
    {
    	ans += a[m - 1][i];
    }
    cout << ans;
}
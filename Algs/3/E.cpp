#include <iostream>
#include <string>
#include <vector>
#include <cassert>
 
using namespace std;

const int INF = 1e9+7;

class str
{
public:
	str() : val(0), k1(0), k2(0) {}
	int val;
	int k1;
	int k2;
	vector<int> a;
};

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        cout << endl;
        cout << 0 << ' ' << 0;
        return 0;
    }
    vector <int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
    	cin >> p[i];
    }
    vector <vector <str>> dp(n + 1, vector<str>(n + 1));
    for (int i = 1; i < n + 1; i++)
    {
    	dp[0][i].val = INF;
    }
    for (int i = 1; i <= n; i++)
    {
    	for (int j = 0; j <= n; j++)
    	{
    		if (p[i] > 100)
    		{
    			if (j == n)
    			{
    				dp[i][j].val = dp[i - 1][j - 1].val + p[i];
    				dp[i][j].k1 = dp[i - 1][j - 1].k1 + 1;
    				dp[i][j].k2 = dp[i - 1][j - 1].k2;
    				dp[i][j].a = dp[i - 1][j - 1].a;
    			}
    			else if (j == 0)
    			{
    				dp[i][j].val = dp[i - 1][j + 1].val;
    				dp[i][j].k1 = dp[i - 1][j + 1].k1;
    				dp[i][j].k2 = dp[i - 1][j + 1].k2 + 1;
    				dp[i][j].a = dp[i - 1][j + 1].a;
    				dp[i][j].a.push_back(i);
    			}
    			else
    			{
    				if (dp[i - 1][j - 1].val + p[i] <= dp[i - 1][j + 1].val)
    				{
    					dp[i][j].val = dp[i - 1][j - 1].val + p[i];
    					dp[i][j].k1 = dp[i - 1][j - 1].k1 + 1;
    					dp[i][j].k2 = dp[i - 1][j - 1].k2;
    					dp[i][j].a = dp[i - 1][j - 1].a;
    				}
    				else
    				{
    					dp[i][j].val = dp[i - 1][j + 1].val;
    					dp[i][j].k1 = dp[i - 1][j + 1].k1;
    					dp[i][j].k2 = dp[i - 1][j + 1].k2 + 1;
    					dp[i][j].a = dp[i - 1][j + 1].a;
    					dp[i][j].a.push_back(i);
    				}
    			}
    		}
    		else
    		{
    			if (j == n)
    			{
    				dp[i][j].val = dp[i - 1][j].val + p[i];
    				dp[i][j].k1 = dp[i - 1][j].k1;
    				dp[i][j].k2 = dp[i - 1][j].k2;
    				dp[i][j].a = dp[i - 1][j].a;
    			}
    			else
    			{
    				if (dp[i - 1][j].val + p[i] <= dp[i - 1][j + 1].val)
    				{
    					dp[i][j].val = dp[i - 1][j].val + p[i];
    					dp[i][j].k1 = dp[i - 1][j].k1;
    					dp[i][j].k2 = dp[i - 1][j].k2;
    					dp[i][j].a = dp[i - 1][j].a;
    				}
    				else
    				{
    					dp[i][j].val = dp[i - 1][j + 1].val;
    					dp[i][j].k1 = dp[i - 1][j + 1].k1;
    					dp[i][j].k2 = dp[i - 1][j + 1].k2 + 1;
    					dp[i][j].a = dp[i - 1][j + 1].a;
    					dp[i][j].a.push_back(i);
    				}
    			}
    		}
    	}
    }
    int ans = INF, ind = -1;
    for (int i = 0; i <= n; i++)
    {
    	if (dp[n][i].val <= ans)
    	{
    		ans = dp[n][i].val;
    		ind = i;
    	}
    }
    cout << ans << endl;
    cout << dp[n][ind].k1 - dp[n][ind].k2 << ' ' << dp[n][ind].k2 << endl;
    for (int i = 0; i < dp[n][ind].a.size(); i++)
    {
    	cout << dp[n][ind].a[i] << endl;
    }
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("vectors.in", "r", stdin);
	freopen("vectors.out", "w", stdout);
	long long n;
	cin >> n;
	vector <string> ans;
	string cur_str = "";
	int prev_bit = 0;
	int k = 1 << n;
	for (int i = 0; i < k; i++)
	{
		bool good = true;
		for (int j = n - 1; j >= 0; j--)
		{
			if ((i & (1 << j)))
			{
				if (prev_bit)
				{
					good = false;
					break;
				}
				cur_str += '1';
				prev_bit = 1;
			}
			else
			{
				cur_str += '0';
				prev_bit = 0;
			}
		}
		if (good) ans.push_back(cur_str);
		cur_str = "";
		prev_bit = 0;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
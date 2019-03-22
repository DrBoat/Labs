#include <iostream>
#include <string>

using namespace std;

string s;

bool decode ()
{
	bool ans = false;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i - 1] == s[i])
		{
			ans = true;
			s.erase(i - 1, 2);
			i -= 2;
		}
	}
	return ans;
}

int main()
{
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	cin >> s;
	while (decode());
	cout << s;
	return 0;
}
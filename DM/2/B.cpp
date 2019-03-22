#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string left_shift(string s)
{
    int n = s.size();
    char tmp = s[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
    	s[i] = s[i - 1];
    }
    s[0] = tmp;
    return s;
}

int main()
{
	freopen("bwt.in", "r", stdin);
	freopen("bwt.out", "w", stdout);
	string s;
	cin >> s;
	vector<string> shifts(s.size());
	shifts[0] = s;
	for (int i = 1; i < s.size(); i++)
	{
		shifts[i] = left_shift(shifts[i - 1]);
	}
	sort(shifts.begin(), shifts.end());
	for (int i = 0; i < shifts.size(); i++)
	{
		string tmp = shifts[i];
		cout << tmp[s.size() - 1];
	}
}
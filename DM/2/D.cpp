#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> dictionary(26);

int finder(string s, int ans)
{
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (dictionary[i] == s)
		{
			ans = i;
		}
	}
	return ans;
}

int main()
{
	freopen("lzw.in", "r", stdin);
	freopen("lzw.out", "w", stdout);
	string w, k, wk;
	for (char c = 'a', i = 0; c <= 'z'; c++, i++)
	{
		dictionary[i] = c;
	}
	string s;
	cin >> s;
	int find1 = -1, find2 = -1;
	w = s[0];
	for (int i = 1; i < s.size(); i++)
	{
		k = s[i];
		wk = w + k;
		find1 = finder(wk, find1);
		if (find1 != -1)
		{
			find1 = -1;
			w = wk;
		}
		else
		{
			find2 = finder(w, find2);
			cout << find2 << ' ';
			dictionary.push_back(wk);
			w = k;
		}
	}
	find1 = finder(w, find1);
	cout << find1 << '\n';
}
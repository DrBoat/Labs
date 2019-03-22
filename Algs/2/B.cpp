#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	stack <char> s;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		char cur = str[i];
		if (!s.empty())
		{
			if ((s.top() == '(' && cur == ')') || (s.top() == '[' && cur == ']') || (s.top() == '{' && cur == '}'))
			{
				s.pop();
			}
			else if (cur == ')' || cur == ']' || cur == '}')
			{
				cout << "NO" << endl;
				return 0;
			}
			else
			{
				s.push(cur);
			}
		}
		else
		{
			s.push(cur);
		}
	}
	if (s.empty())
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
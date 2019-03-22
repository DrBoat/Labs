#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	freopen("postfix.in", "r", stdin);
	freopen("postfix.out", "w", stdout);
	stack <int> s;
	string str;
	while (cin >> str)
	{
		if (str == "+")
		{
			int snd = s.top();
			s.pop();
			int fst = s.top();
			s.pop();
			s.push((fst + snd));
		}
		else if (str == "-")
		{
			int snd = s.top();
			s.pop();
			int fst = s.top();
			s.pop();
			s.push((fst - snd));
		}
		else if (str == "*")
		{
			int snd = s.top();
			s.pop();
			int fst = s.top();
			s.pop();
			s.push((fst * snd));
		}
		else
		{
			s.push(stoi(str));
		}
	}
	cout << s.top();
	return 0;
}
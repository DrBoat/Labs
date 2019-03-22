#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
	freopen("stack-min.in", "r", stdin);
	freopen("stack-min.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack <int> s, minim;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int command;
		cin >> command;
		if (command == 1)
		{
			int el;
			cin >> el;
			s.push(el);
			if (minim.empty())
			{
				minim.push(el);
			}
			else
			{
				int mn = min(minim.top(), el);
				minim.push(mn);
			}
			
		}
		else if (command == 2)
		{
			s.pop();
			minim.pop();
		}
		else if (command == 3)
		{
			cout << minim.top() << endl;
		}
	}
	return 0;
}
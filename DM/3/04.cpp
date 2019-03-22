#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map <string, bool> result;
vector <string> ans;

bool in_result(string (s))
{
	if (result.count(s) == 0)
	{
		return false;
	}
	return true;
}

void chain_code(unsigned int n)
{
	string current = "";
	for (unsigned int i = 0; i < n; i++)
	{
		current += '0';
	}
	ans.push_back(current);
	result.insert(pair <string, bool> (current, true));
	unsigned int i = 0;
	unsigned int tmp = (1 << n);
 	while (i < tmp)
	{
		string prefix = "";
		for (unsigned int i = 1; i < n; i++)
		{
			prefix += current[i];
		}
		string pr1 = prefix + '1';
		string pr0 = prefix + '0';
		if (!in_result(pr1))
	    {
	    	current = pr1;
	    	ans.push_back(current);
	    	result.insert(pair <string, bool> (current, true));
	    }
	    else if (!in_result(pr0))
	    {
	    	current = pr0;
	    	ans.push_back(current);
	    	result.insert(pair <string, bool> (current, true));
	    }
	    else
	    {
	    	break;
	    }
	    i++;
	}
    for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
  

int main()
{
	freopen("chaincode.in", "r", stdin);
	freopen("chaincode.out", "w", stdout);
	unsigned int n;
	cin >> n;
	chain_code(n);
	return 0;
}
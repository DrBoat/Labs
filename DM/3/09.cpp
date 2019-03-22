#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
 
using namespace std;

vector <char> items;

bool good (vector <char> const &v)
{
    int cmp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == '(')
        {
            cmp++;
        }
        else
        {
            cmp --;
        }
        if (cmp < 0) return false; 
    }
    if (cmp == 0) return true;
    return false;
}
 
void printPermutations ()
{
    vector<char> v;
    for (int i=0; i < items.size(); i++)
    {
    	v.push_back(items[i]); 
    }
 
    while (next_permutation(v.begin(), v.end())) 
    { 
        if (good (v))
        {
            copy(v.begin(), v.end(), ostream_iterator<char>(cout, ""));
            cout << endl;
        }
        
    }
}
 
 
int main() 
{ 
    freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		items.push_back('(');
		cout << '(';
	}
    for (int i = 0; i < n; i++)
    {
        items.push_back(')');
        cout << ')';
    }
	cout << endl;
    printPermutations();
    return 0;
}
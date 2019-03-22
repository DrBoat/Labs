#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main()
{
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    string s;
    cin >> s;
    int l = 0, r = 0;
    bool m = false;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            r++;
        }
        else
        {
            l++;
            if (l < r)
            {
                s[i] = ')';
                m = true;
                break;
            }
        }
    }
    if (!m)
    {
        cout << "-";
    }
    else
    {
        string s1 = s.substr(0, s.size() - l - r + 1);
        s = s1;
        r--;
        while (r > 0)
        {
            if (l > 0)
            {
                s1 += '(';
                l--;
            }
            else
            {
                s1 += ')';
                r--;
            }
        }
        cout << s1;
    }
}
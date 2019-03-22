#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
 
using namespace std;

int main()
{
    freopen("nextvector.in","r",stdin);
    freopen("nextvector.out","w",stdout);
    string prev;
    cin >> prev;
    string next = prev;
    bool ct = false;
    for (int i = prev.size(); i >= 0; i--)
    {
        if (prev[i] == '1')
        {
            prev[i] = '0';
            for (int j = i + 1; j < prev.size(); j++)
            {
                prev[j] = '1';
            }
            cout << prev;
            ct = true;
            break;
        }
    }
    if (!ct)
    {
        cout << '-';
    }
    cout << endl;
    ct = false;
    for (int i = next.size(); i >= 0; i--)
    {
        if (next[i] == '0')
        {
            next[i] = '1';
            for (int j = i + 1; j < next.size(); j++)
            {
                next[j] = '0';
            }
            cout << next;
            ct = true;
            break;
        }
    }
    if (!ct)
    {
        cout << '-';
    }
}

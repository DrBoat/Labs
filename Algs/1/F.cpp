#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main()
{
    freopen("style.in", "r", stdin);
    freopen("style.out", "w", stdout);
    vector <int> a, b;
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    pair <int, int> ans;
    int ai = 0;
    int bi = 0;
    ans.first = a[ai];
    ans.second = b[bi];
    int c = abs(ans.first - ans.second);
    while (ai < a.size() && bi < b.size())
    {
        if (abs(a[ai] - b[bi]) < c)
        {
            ans.first = a[ai];
            ans.second = b[bi];
            c = abs(ans.first - ans.second);
        }
        if (a[ai] < b[bi])
        {
            ai++;
        }
        else
        {
            bi++;
        }
 
    }
    cout << ans.first << ' ' << ans.second;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
vector <int> a;
 
int l_bin_search(int key)
{
    if (key < a[0] || key > a[a.size() - 1]) return -1;
    int l = -1;
    int r = a.size();    
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (a[m] < key)
            l = m;
        else
            r = m;
    }
    if(a[r] == key)
    {
        return r + 1;
    }
    else
    {
        return -1;
    }
}
 
int r_bin_search(int key)
{
    if (key < a[0] || key > a[a.size() - 1]) return -1;
    int l = -1;
    int r = a.size();    
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (a[m] <= key)
            l = m;
        else
            r = m;
    }
    if(a[l] == key)
    {
        return l + 1;
    }
    else
    {
        return -1;
    }
}
 
int main()
{
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        cout << l_bin_search(k) << ' ' << r_bin_search(k) << endl;
    }
    return 0;
}
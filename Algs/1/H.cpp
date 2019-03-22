#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
 
using namespace std;
 
vector <int> a(2);
 
int n, k, aa, bb, cc;
 
int partition(int l, int r)
{
    int res = rand() % (r - l);
    return res;
}
 
void stat(int k, int l, int r)
{
    if (l == r)
        return;
    int i = l, j = r, v = a[l + partition(l, r)];
    while (i <= j)
    {
        while (a[i] < v)
        {
            i++;
        }
        while (a[j] > v)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i++], a[j--]);
        }
    }
    if (k > j && k < i)
    {
        return;
    }
    if (j > l && k <= j)
    {
        stat(k, l, j);
    }
    if (i < r && k >= i)
    {
        stat(k, i, r);
    }
}
 
int main()
{
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    cin >> n >> k >> aa >> bb >> cc >> a[0] >> a[1];
    a.resize(n);
    for (int i = 2; i < n; i++)
    {
        a[i] = aa * a[i - 2] + bb * a[i - 1] + cc;
    }
    stat(k - 1, 0, n - 1);
    cout << a[k - 1];
    return 0;
}
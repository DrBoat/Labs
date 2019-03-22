#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
vector <int> a, b, c, d;
int kep, mai, hta, bot;
int k, m, h, o;
int i, j, v, w;
int mn = 1e6, x, y;
 
int maxim()
{
    return max(max(a[i], b[j]), max(c[v], d[w]));
}
 
 
void minim()
{
    if (min(min(a[i], b[j]), min(c[v], d[w])) == a[i])
    {
        x = a[i];
        y = maxim();
        if ((y - x) < mn)
        {
            mn = y - x;
            kep = a[i];
            mai = b[j];
            hta = c[v];
            bot = d[w];
        }
        i++;
    }
    else if (min(min(a[i], b[j]), min(c[v], d[w])) == b[j])
    {
        x = b[j];
        y = maxim();
        if ((y - x) < mn)
        {
            mn = y - x;
            kep = a[i];
            mai = b[j];
            hta = c[v];
            bot = d[w];
        }
        j++;    
    }
    else if (min(min(a[i], b[j]), min(c[v], d[w])) == c[v])
    {
        x = c[v];
        y = maxim();
        if ((y - x) < mn)
        {
            mn = y - x;
            kep = a[i];
            mai = b[j];
            hta = c[v];
            bot = d[w];
        }
        v++;    
    }
    else
    {
        x = d[w];
        y = maxim();
        if ((y - x) < mn)
        {
            mn = y - x;
            kep = a[i];
            mai = b[j];
            hta = c[v];
            bot = d[w];
        }
        w++;    
    }
}
 
int main()
{
    freopen("style.in", "r", stdin);
    freopen("style.out", "w", stdout);
    cin >> k;
    a.resize(k);
    for (int q = 0; q < k; q++)
    {
        cin >> a[q];
    }
    cin >> m;
    b.resize(m);
    for (int q = 0; q < m; q++)
    {
        cin >> b[q];
    }
    cin >> h;
    c.resize(h);
    for (int q = 0; q < h; q++)
    {
        cin >> c[q];
    }
    cin >> o;
    d.resize(o);
    for (int q = 0; q < o; q++)
    {
        cin >> d[q];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    i = 0, j = 0, v = 0, w = 0;
    while (i != k && j != m && v != h && w != o && mn != 0)
    {
        minim();
    }
    cout << kep << ' ' << mai << ' ' << hta << ' ' << bot << endl;
}
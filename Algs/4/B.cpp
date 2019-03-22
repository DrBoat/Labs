#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector <long long> t;
 
void build(vector <long long> &a, int v, int tl, int tr)
{
    if (tl  == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build (a, v * 2 + 1, tl, tm);
        build (a, v * 2 + 2, tm + 1, tr);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
}

void modify(int v, int tl, int tr, int pos, int val)
{
    if(tl > tr)
    {
        return;
    }
    if(tl == tr)
    {
      t[v] = val;
      return;
    }
    long long tm =  tl + (tr - tl) / 2;
    if (pos <= tm)
    {
        modify (v * 2 + 1 , tl, tm, pos, val);
    }
    else
    {
        modify(v * 2 + 2, tm+1, tr, pos, val);
    }
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

long long sum(int v, int tl, int tr, long long l, long long r)
{
    if (l > r || tl > tr)
    {
        return 0;
    }
    if (l == tl && r == tr)
    {
        return t[v];
    }
    long long tm = (tl + tr) / 2;
    return sum (v * 2 + 1, tl, tm, l, min(tm, r)) + sum (v * 2 + 2, tm + 1, tr, max(tm + 1,l), r);
}

int main()
{
    freopen("rsq.in", "r", stdin);
    freopen("rsq.out", "w", stdout);
    int n;
    cin >> n;
    t.resize(4 * n + 4);
    vector <long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(a, 0, 0, n - 1);
    string command;
    long long x, y;
    while (cin >> command)
    {
        if (command == "sum")
        {
            cin >> x >> y;
            cout << sum(0, 0, n - 1, x - 1, y - 1) << endl;
        }
        if(command == "set")
        {
            cin >> x >> y;
            modify(0, 0, n - 1, x - 1, y);
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;

vector <int> s, sz, lit, big;

int get(int a)
{
    if (a == s[a])
        return a;
    return s[a] = get(s[a]);
}

void union_()
{
    int a, b;
    cin >> a >> b;
    a = get(a);
    b = get(b);
    if (a != b)
    {
        if (sz[a] > sz[b])
            swap(a, b);
        sz[b] += sz[a];
        if (big[b] < big[a])
            big[b] = big[a];
        if (lit[b] > lit[a])
            lit[b] = lit[a];
        s[a] = s[b];
    }
}

int main()
{
    freopen("dsu.in", "r", stdin);
    freopen("dsu.out", "w", stdout);
    int n;
    cin >> n;
    s.resize(n + 1);
    sz.resize(n + 1, 1);
    lit.resize(n + 1);
    big.resize(n + 1);
    for (int i = 1; i <= n; i += 1)
    {
        s[i] = i;
        lit[i] = i;
        big[i] = i;
    }
    string str;
    while (cin >> str)
    {
        if (str == "union")
        {
            union_();
        }
        else
        {
            int a;
            cin >> a;
            a = get(a);
            cout << lit[a] << " " << big[a] << " " << sz[a] << endl;
        }
    }
    return 0;
}

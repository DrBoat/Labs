#include <iostream>
#include <queue>

using namespace std;

queue<int> bur;

int main()
{
    freopen("bureaucracy.in", "r", stdin);
    freopen("bureaucracy.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int k = m/n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp <= k)
        {
            m -= tmp;
        }
        else
        {
            tmp -= k;
            m -= k;
            bur.push(tmp);
        }
    }
    if (bur.empty())
    {
        cout << -1;
        return 0;
    }
    n = bur.size();
    while (m > n)
    {
        int k = m / n;
        for (int i = 0; i < n; i++)
        {
            int tmp = bur.front();
            bur.pop();
            if (tmp <= k)
            {
                m -= tmp;
            }
            else
            {
                tmp -= k;
                m -= k;
                bur.push(tmp);
            }
        }
        n = bur.size();
        if (bur.empty())
        {
            cout << -1;
            return 0;
        }
    }
    if (bur.empty())
    {
        cout << -1;
        return 0;
    }
    while (m)
    {
        int tmp = bur.front();
        int k = 1;
        bur.pop();
        if (tmp <= k)
        {
            m -= tmp;
        }
        else
        {
            tmp -= k;
            m -= k;
            bur.push(tmp);
        }
        if (bur.empty())
        {
            cout << -1;
            return 0;
        }
    }
    if (bur.empty())
    {
        cout << -1;
        return 0;
    }
    n = bur.size();
    cout << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        int tmp = bur.front();
        bur.pop();
        cout << tmp << ' ';
    }
}

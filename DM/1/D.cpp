#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long a[6];
long long table[33][6];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long m;
    cin >> m;
    if (m == 0)
    {
        cout << "1&~1";
        return 0;
    }
    long long c;
    for (long long i = 0; i < n; i++)
    {
        c = a[i];
        for (long long j = 0; j < 33; j++)
        {
            table [j][i] = c % 2;
            c = c/2;
        }
    }
    c = m;
    for (long long j = 0; j < 33; j++)
    {
        table [j][5] = c % 2;
        c = c / 2;
    }
    for (long long i = 0; i < 32; i++)
    {
        for (long long j = i + 1; j < 33; j++)
        {
            long long h = 0;
            for (long long k = 0; k < n; k++)
            {
                if (table [i][k] == table[j][k])
                {
                   h++;
                }
            }
            if (h == n && table[i][5] != table[j][5])
            {
                cout << "Impossible";
                return 0;
            }
        }
    }
    vector <string> v;
    for (long long i = 0; i < 33; i++)
    {
        string s = "";
        if (table[i][5] == 1)
        {
            s += '(';
            for(long long j = 0; j < n;j++ )
            {
                if (table[i][j] == 1)
                {
                    s += j + 49;
                }
                else
                {
                    s += '~';
                    s += j + 49;
                }
                if (j != n - 1)
                {
                    s += '&';
                }
            }
            s += ')';
            v.push_back(s);

        }
    }
    for(long long i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << "|";
        }
    }
}


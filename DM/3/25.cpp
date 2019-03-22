#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> a(k), maxval(k);
    bool b = true;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        maxval[i] = n - k + i + 1;
    }
    int m = -1;
    for (int i = k - 1; i >= 0; i--)
    {
        if (a[i] < maxval[i])
        {
            m = i;
            a[i]++;
            break;
        }
    }
    if (m == -1)
    {
        cout << -1;
        return 0;
    }
    else
    {
        if (m < k - 1)
        {
            for (int j = m + 1; j < k ; j++)
            {
                a[j] = a[m] + j - m;
            }
            for (int j = 0; j < k; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < k ; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;

        }

    }

}



#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int tab[33000][16];

void ms(int h, int n)
{
    int q = 0;
    for (int i = (1 << (n - 1)); i > 0; i = i / 2)
    {
        if (h & i)
        {
            tab[h][q] = 1;
            q++;
        }
        else
        {
            tab[h][q] = 0;
            q++;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int t = (1 << n);
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        int q1, q2;
        cin >> q1 >> q2;
        int y = 0;
        if (v.size() > 0)
        {
            for (int i = 0; i < v.size() - 1; i += 2)
            {
                if((q1 == v[i] && q2 == v[i + 1]) || (q1 == v[i + 1] && q2 == v[i]))
                {
                    y++;
                }
            }
            if (y == 0)
            {
                v.push_back(q1);
                v.push_back(q2);
            }
        }
        else
        {
            v.push_back(q1);
            v.push_back(q2);
        }
    }
    for (int i = 0; i < 1 << n; i++)
    {
        ms(i, n);
    }
    bool b = false, w = false;
    for(int i = 0; i < (1 << n); i++)
    {
        int k = 0;
        w = false;
        while(k < v.size())
        {
            if(v[k] > 0 && v[k + 1] > 0)
            {
                if((tab[i][v[k] - 1] || tab[i][v[k + 1] - 1]) == 0)
                {
                    w = true;
                    break;
                }
            }
            else if(v[k] > 0 && v[k + 1] < 0)
            {
                if((tab[i][v[k] - 1] || !tab[i][-1*v[k + 1] - 1]) == 0)
                {
                    w = true;
                    break;
                }
            }
            else if(v[k] < 0 && v[k + 1] < 0)
            {
                if((!tab[i][-1*v[k] - 1] || !tab[i][-1*v[k + 1] - 1]) == 0)
                {
                    w = true;
                    break;
                }
            }
            else if(v[k] < 0 && v[k + 1] > 0)
            {
                if((!tab[i][-1*v[k] - 1] || tab[i][v[k + 1] - 1]) == 0)
                {
                    w = true;
                    break;
                }
            }
            k += 2;
        }
        if(!w)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class schm;
vector<schm> schema;
vector<int> nul;

class schm
{
public:
    int result;
    int s;
    int deep;
    int a[5];
    int res[32];
    schm()
    {
        deep = 0;
        s = 0;
    }
    schm(int mm, int knum[], int kt[])
    {
        s = mm;
        for (int i = 0; i < mm; i++)
        {
            a[i] = knum[i];
        }
        for (int i = 0; i < (1 << mm); i++)
        {
            res[i] = kt[i];
        }
        deep = 0;
        for (int i = 0; i < mm; i++)
        {
            deep = max(deep, schema[a[i] - 1].deep);
        }
        deep++;
    }
    void gtrst()
    {
        if (s)
        {
            int k = 0;
            for (int i = 0; i < s; i++)
            {
                k *= 2;
                k += schema[a[i] - 1].result;
            }
            result = res[k];
        }
    }
};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m == 0)
        {
            nul.push_back(schema.size());
            schema.push_back(schm());
        }
        else
        {
            int num[m];
            int t[(1 << m)];
            for (int j = 0; j < m; j++)
            {
                cin >> num[j];
            }
            for (int j = 0; j < (1 << m); j++)
            {
                cin >> t[j];
            }
            schema.push_back(schm(m, num, t));
        }
    }
    cout << schema[n - 1].deep << endl;
    string ans = "";
    for (int i = 0; i < (1 << nul.size()); i++)
    {
        int tmp = i;
        for (int j = 0; j < nul.size(); j++)
        {
            schema[nul[nul.size() - 1 - j]].result = (tmp % 2);
            tmp /= 2;
        }
        for (int j = 0; j < n; j++)
        {
            schema[j].gtrst();
        }
        ans += char(schema[n - 1].result + '0');
    }
    cout << ans;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector < vector <int> > dis(m);
    vector <int> length(m);
    for (int i = 0; i < m; i++)
    {
        dis[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> dis[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dis[i][j] != -1)
            {
                length[i]++;
            }
        }
    }
    vector <int> ans(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (length[j] == 1)
            {
                for (int l = 0; l < n; l++)
                {
                    int tmp;
                    if (dis[j][l] != -1)
                    {
                        tmp = dis[j][l];
                        for (int k = 0; k < m; k++)
                        {
                            if (ans[k] == 0)
                            {
                                if (dis[k][l] == tmp)
                                {
                                    length[k] = 0;
                                    ans[k] = 1;
                                }
                                if (dis[k][l] != -1)
                                {
                                    length[k]--;
                                }
                            }
                            dis[k][l] = -1;
                        }
                    }
                }
                j = m;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[j] == 0 && length[j] == 0)
            {
                cout << "YES" << endl;
                return(0);
            }
        }
    }
    cout << "NO" << endl;
    return(0);
}


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = (1 << n);
    vector <int> ans(m);
    vector <string> out(m);
    for (int i = 0; i < m; i++)
    {
        cin >> out[i] >> ans[i];
    }
    for (int i = 0; i < m - 1; i++)
    {
        int l = ans[i];
        for (int j = i + 1; j < m; j++)
        {
            int r = ans[j];
            ans[j] = (r + l) % 2;
            l = r;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << out[i] << ' ' << ans[i] << endl;
    }
}

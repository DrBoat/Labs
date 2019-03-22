#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
long long update_cost(char from, char to)
{
   return from == to ? 0 : 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    long long n = s1.size(), m = s2.size();
    vector <vector <long long>> d(n + 1, vector<long long>(m + 1));
    d[0][0] = 0;
    for (long long j = 0; j < m; j++)
    {
        d[0][j + 1] = d[0][j] + 1; 
    }
    for (long long i = 0; i < n; i++)
    {
        d[i + 1][0] = d[i][0] + 1;
    }
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            d[i + 1][j + 1] = min(d[i + 1][j] + 1, d[i][j + 1] + 1);
            d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + update_cost(s1[i], s2[j]));
        }
    }
    cout << d[s1.size()][s2.size()];
}
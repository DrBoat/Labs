#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool t0_c, t1_c, s_c, m_c, l_c;

bool t0_f(int k, string table)
{
    if  (table[0] == '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool t1_f(int k, string table)
{
    if (table[table.size() - 1]  == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool m_f (int k, string table)
{

    for (int i = 0 ; i < table.length();  i++)
    {
        for (int j = 1; j  < table.length(); j <<= 1)
        {
            if (((i & j) != j) && (table[i | j] < table[i]))
            {
                return false;
            }
        }
    }
    return true;
}
bool s_f (int k, string table)
{
    for (int i = 0; i <= table.length() / 2; i++)
    {
        if (table[i] == table[table.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool l_f (int k, string table)
{
    int m = table.length();
    vector <int> s(m);
    for (int i = 0; i < m ; i++) {
        s[i] = table[i] - 48;
    }
    for(int i = 1; i < table.length(); i++)
    {
        for (int j = 0; j < table.length() - i; j++)
        {
            s[j] = (s[j] + s[j+1]) % 2;
        }
        if(((i & (i - 1)) != 0) && s[0] == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        string table;
        cin >> k >> table;
        if (!t0_f(k, table)) t0_c = true;
        if (!t1_f(k, table)) t1_c = true;
        if (!s_f(k, table)) s_c = true;
        if (!m_f(k, table)) m_c = true;
        if (!l_f(k, table)) l_c = true;
    }
    if (t0_c && t1_c && s_c && m_c && l_c)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <sstream>

using namespace std;

map<char, vector<string>> productions;
map<char, bool> used;

bool check_S(const string &s, const set<char> &st)
{
    for (char C : s)
    {
        if ((('A' <= C && C <= 'Z') && st.count(C) == 0) || ('a' <= C && C <= 'z')) {
            return false;
        }
    }
    return true;
}

void dfs(set<char> &st, char v) {
    
    if (used.count(v) > 0)
    {
        return;
    }
    st.insert(v);
    used[v] = true;
    for (auto S : productions[v]) {
        for (auto C : S) {
            if ('A' <= C && C <= 'Z') {
                dfs(st, C);
            }
        }
    }
}

set<char> del()
{
    set<char> st;
    for (auto R : productions)
    {
        for (auto S : R.second)
        {
            if (check_S(S, st))
            {
                st.insert(R.first);
            }
        }
    }
    bool tmp = true;
    while (tmp) {
        bool check = false;
        for (auto R : productions)
        {
            if (st.count(R.first) == 0)
            {
                for (auto S : R.second)
                {
                    if (check_S(S, st))
                    {
                        check = true;
                        st.insert(R.first);
                        break;
                    }
                }
            }
        }
        tmp = check;
    }
    return st;
}

int main()
{
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
    int n;
    char start;
    cin >> n >> start;
    {
        string tmp;
        getline(cin, tmp);
    }
    for (int i = 0; i < n; i++)
    {
        char from;
        string tmp, to = "";
        getline(cin, tmp);
        stringstream ss(tmp);
        ss >> from;
        if ((int)tmp.size() != 4)
        {
            ss >> tmp >> to;
        }
        productions[from].push_back(to);
    }
    set<char> d1 = del(), d2;
    dfs(d2, start);
    for (auto R : productions)
    {
        if (d1.count(R.first) > 0)
        {
            cout << R.first << ' ';
        }
    }
    cout << endl;
}
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <sstream>

using namespace std;

map<char, vector<string>> productions;
map<char, bool> used;
set<char> terminals;

bool check_S(const string &s, const set<char> &st)
{
    for (char C : s)
    {
        if ('A' <= C && C <= 'Z' && st.count(C) == 0)
        {
            return false;
        }
    }
    return true;
}

void dfs(set<char> &st, set<char> &way, char v) {
    
    if (way.count(v) == 0)
    {
        return;
    }
    if (used.count(v) > 0)
    {
        return;
    }
    st.insert(v);
    used[v] = true;
    for (auto S : productions[v]) {
        if (check_S(S, way))
        for (auto C : S) {
            if ('A' <= C && C <= 'Z') {
                dfs(st, way, C);
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
	freopen("useless.in", "r", stdin);
	freopen("useless.out", "w", stdout);
	int n;
	char start;
	cin >> n >> start;
	terminals.insert(start);
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
		terminals.insert(from);
		for (auto T : to)
		{
            if ('A' <= T && T <= 'Z')
            {
                terminals.insert(T);
            }
        }
        productions[from].push_back(to);
	}
	set<char> d1 = del(), d2;
    dfs(d2, d1, start);
    for (auto T : terminals)
    {
        if (d2.count(T) == 0)
        {
            cout << T << ' ';
        }
    }
    cout << endl;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

vector<bool> is_terminal;

bool walk(int v, map <char, int> *state, const string &word, int pos)
{
	if (pos == word.size())
	{
		return is_terminal[v];
	}
	if (state[v].find(word[pos]) != state[v].end())
	{
		return walk(state[v][word[pos]], state, word, (pos + 1));
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("problem1.in", "r", stdin);
	freopen("problem1.out", "w", stdout);
	string s;
	cin >> s;
	int n, m, k;
	cin >> n >> m >> k;
	is_terminal.resize(n + 1);
	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		is_terminal[tmp] = true;

	}
	map <char, int> *states = new map <char, int> [n + 1];
	for (int i = 0; i < m; i++)
	{
		int from, to;
		char c;
		cin >> from >> to >> c;
		states[from][c] = to;
	}
	if (walk(1, states, s, 0))
	{
		cout << "Accepts";
	}
	else
	{
		cout << "Rejects";
	}

}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

const long long INF = 1e9+8;

struct item
{
	long long l, r, x, y;
	item() { }
	item(long long x) : x(x), y(RAND_MAX * rand() + rand()), l(0), r(0) { }
};

long long root = 0;
vector<item> tree;

pair<long long, long long> split(long long v, long long x)
{
	if (v == 0) return make_pair(0, 0);
	else if (tree[v].x <= x)
	{
		pair<long long, long long> p = split(tree[v].r, x);
		tree[v].r = p.first;
		return make_pair(v, p.second);
	}
	else
	{
		pair<long long, long long> p = split(tree[v].l, x);
		tree[v].l = p.second;
		return make_pair(p.first, v);
	}
}

long long merge(long long l, long long r)
{
	if (l == 0 || r == 0) return l + r;
	else if (tree[l].y > tree[r].y)
	{
		tree[l].r = merge(tree[l].r, r);
		return l;
	}
	else
	{
		tree[r].l = merge(l, tree[r].l);
		return r;
	}
}

bool exist(long long v, long long x)
{
	if (v == 0) return false;
	else if (tree[v].x == x) return true;
	else if (tree[v].x < x) return exist(tree[v].r, x);
	else return exist(tree[v].l, x);
}

void insert (long long v, long long x)
{
	if (exist(root, x)) return;
	item k(x);
	long long insert_root = tree.size();
	tree.push_back(k);
	pair<long long, long long> t = split(v, x);
	t.first = merge(t.first, insert_root);
	root = merge(t.first, t.second);
}

void erase (long long v, long long x)
{
	if (!exist(root, x)) return;
	pair<long long, long long> t = split(root, x);
	pair<long long, long long> t1 = split(t.first, x - 1);
	root = merge(t1.first, t.second);
}

long long next(long long x)
{
	pair<long long, long long> t = split(root, x);
	if (t.second == 0)
	{
		root = merge(t.first, t.second);
		return INF;
	}
	else
	{
		long long tmp = t.second;
		while (tree[tmp].l)
		{
			tmp = tree[tmp].l;
		}
		tmp = tree[tmp].x;
		root = merge(t.first, t.second);
		return tmp;
	}
}

long long prev(long long x)
{
	pair<long long, long long> t = split(root, x - 1);
	if (t.first == 0)
	{
		root = merge(t.first, t.second);
		return INF;
	}
	else
	{
		long long tmp = t.first;
		while (tree[tmp].r)
		{
			tmp = tree[tmp].r;
		}
		tmp = tree[tmp].x;
		root = merge(t.first, t.second);
		return tmp;
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	item nul;
	nul.l = 0;
	nul.r = 0;
	nul.x = 0;
	nul.y = 0;
	tree.push_back(nul);
	string s;
	long long tmp;
	while (cin >> s >> tmp)
	{
		if (s == "insert")
		{
			insert(root, tmp);
		}
		else if (s == "delete")
		{
			erase(root, tmp);
		}
		else if (s == "exists")
		{
			if (exist(root, tmp)) cout << "true" << endl;
			else cout << "false" << endl;
		}
		else if (s == "next")
		{
			tmp = next(tmp);
			if (tmp == INF) cout << "none" << endl;
			else cout << tmp << endl;
		}
		else if (s == "prev")
		{
			tmp = prev(tmp);
			if (tmp == INF) cout << "none" << endl;
			else cout << tmp << endl;
		}
	}
	return 0;
}
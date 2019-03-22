#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

const int INF = 1e9+8;

struct item
{
	int l, r, s, y, val;
	bool free_child;
	item(int val = 0, int s = 1, bool free_child = true) : l(0), r(0), s(s), y(RAND_MAX * rand() + rand()), val(val), free_child(free_child) { }
};

vector<item> tree;
int root;

void update (int v)
{
	if (v == 0) return;
	tree[v].s = tree[tree[v].l].s + tree[tree[v].r].s + 1;
	if (tree[tree[v].l].free_child || tree[tree[v].r].free_child || (tree[v].val == 0)) tree[v].free_child = true;
	else tree[v].free_child = false;
}

int merge(int l, int r)
{
	if (l == 0 || r == 0)
	{
		return l + r;
	}
	if (tree[l].y > tree[r].y)
	{
		tree[l].r = merge(tree[l].r, r);
		update(l);
		return l;
	}
	else
	{
		tree[r].l = merge(l, tree[r].l);
		update(r);
		return r;
	}
}

pair<int, int> split(int v, int s)
{
	if (v == 0) return make_pair(0, 0);
	if (s <= tree[tree[v].l].s)
	{
		//left
		pair<int, int> cur = split(tree[v].l, s);
		tree[v].l = cur.second;
		update(v);
		return make_pair(cur.first, v);
	}
	else
	{
		//right
		pair<int, int> cur = split(tree[v].r, s - tree[tree[v].l].s - 1);
		tree[v].r = cur.first;
		update(v);
		return make_pair(v, cur.second);

	}
}

void init()
{
	tree.push_back(item(1, 0, false));
	root = 0;
	for (int i = 1; i <= 131072; i++)
	{
		tree.push_back(item());
		root = merge(root, tree.size() - 1);
	}
}

int find(int v)
{
	if (!tree[v].free_child) return -1;
	if (tree[tree[v].l].free_child) return find(tree[v].l);
	if (tree[v].val == 0) return tree[tree[v].l].s;
	return tree[tree[v].l].s + 1 + find(tree[v].r);
}

void insert (int pos, int val)
{
	pair<int, int> cut = split(root, pos - 1);
	int cur = tree.size();
	tree.push_back(item(val, 1, false));
	cut.first = merge (cut.first, cur);
	int free_pos = find(cut.second);
	if (free_pos != -1)
	{
		pair<int, int> tmp = split(cut.second, free_pos);
		pair<int, int> tmp1 = split(tmp.second, 1);
		cut.second = merge(tmp.first, tmp1.second);
	}
	root = merge(cut.first, cut.second);
}

void walk(int v, vector<int>& ans)
{
	if (v == 0) return;
	walk(tree[v].l, ans);
	ans.push_back(tree[v].val);
	walk(tree[v].r, ans);
}

int main()
{
	init();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		insert(tmp, i);
	}
	vector<int> ans;
	walk(root, ans);
	while (!ans.empty() && ans.back() == 0)
	{
		ans.pop_back();
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
}
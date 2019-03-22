#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

const long long INF = 1e9+8;

struct item
{
	long long l, r, x, y, p, i;
	item() { }
	item(long long x, long long y, long long i) : x(x), y(y), l(0), r(0), p(0), i(i) { }
	item(long long x, long long y, long long i, long long p) : x(x), y(y), l(0), r(0), p(p), i(i) { }
};

struct input_data
{
	long long x, y, i;
};

long long root = 0;
item last_item;
vector<item> tree;

bool comp_input_data(const input_data& a, const input_data& b)
{
	return a.x < b.x;
}

bool comp_item(const item& a, const item& b)
{
	return a.i < b.i;
}

int main()
{
	//init
	
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	item nul;
	nul.l = 0;
	nul.r = 0;
	nul.x = 0;
	nul.y = 0;
	nul.p = 0;
	nul.i = 0;
	tree.push_back(nul);
	
	//input

	long long n;
	cin >> n;
	vector<input_data> inp(n);
	for (long long i = 0; i < n; i++)
	{
		cin >> inp[i].x >> inp[i].y;
		inp[i].i = i + 1;
	}

	//code

	sort(inp.begin(), inp.end(), &comp_input_data);
	last_item = item (inp[0].x, inp[0].y, inp[0].i);
	tree.push_back(last_item);
	root = 1;
	for (long long i = 1; i < n; i++)
	{
		long long cur = tree.size() - 1;
		if (inp[i].y > tree[cur].y)
		{
			tree[cur].r = tree.size();
			last_item = item (inp[i].x, inp[i].y, inp[i].i, cur);
			tree.push_back(last_item);
		}
		else
		{
			while (inp[i].y < tree[cur].y && cur != 0)
			{
				cur = tree[cur].p;
			}
			if (cur == 0)
			{
				last_item = item (inp[i].x, inp[i].y, inp[i].i, 0);
				last_item.l = root;
				tree[root].p = tree.size();
				root = tree.size();
				tree.push_back(last_item);
			}
			else
			{
				last_item = item (inp[i].x, inp[i].y, inp[i].i, cur);
				last_item.l = tree[cur].r;
				tree[tree[cur].r].p = tree.size();
			    tree[cur].r = tree.size();
			    tree.push_back(last_item);
			}
		}
	}
	vector<long long> l(n + 1), r(n + 1), p(n + 1);
	for (int i = 1; i <= n; i++)
	{
		l[tree[i].i] = tree[tree[i].l].i;
		r[tree[i].i] = tree[tree[i].r].i;
		p[tree[i].i] = tree[tree[i].p].i;
	}

	//output

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << p[i] << ' ' << l[i] << ' ' << r[i] << endl;
	}
	return 0;
}

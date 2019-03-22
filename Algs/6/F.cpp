#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct dinosaur
{
    int height = 0, parent = 0;
    bool removed = false;
    vector<int> children;
    dinosaur() : height(0), parent(0), removed(false) { }
    dinosaur(int parent, int height) : parent(parent), height(height), removed(false) { }
};

const int MAXN = 2e5 + 5;
int n = 1;

vector<dinosaur> tree(n);
int binup[20][MAXN];

int find_parent(int v)
{
    if (v == tree[v].parent)
    {
        return v;
    }
    return tree[v].parent = find_parent(tree[v].parent);
}

void born(int v)
{
    int u = n++;
    tree[v].children.push_back(u);
    tree.push_back(dinosaur(u, tree[v].height + 1));
    binup[0][u] = v;
    for (int i = 1; i < 20; i++)
    {
        binup[i][u] = binup[i - 1][binup[i - 1][u]];
    }
}

void die(int v)
{
    tree[v].removed = true;
    tree[v].parent = find_parent(binup[0][v]);
}

int lca(int u, int v)
{
    if(tree[u].height > tree[v].height)
    {
        swap(u, v);
    }
    int delta = tree[v].height - tree[u].height;
    for (int i = 0; delta > 0; i++)
    {
        if (delta % 2 == 1)
        {
            v = binup[i][v];
        }
        delta = delta >> 1;
    }
    int lca;
    if(v == u)
    {
        lca = v;
    }
    else
    {
        int k = 19;
        while (k >= 0)
        {
            while (k >= 0 && binup[k][u] == binup[k][v])
            {
                k--;
            }
            if(k != -1)
            {
                u = binup[k][u];
                v = binup[k][v];
            }
        }
        lca = binup[0][u];
    }
    if (tree[lca].removed)
    {
        lca = find_parent(lca);
    }
    return lca + 1;
}

int main()
{
    int m = 0;
    cin >> m;
    binup[0][0] = binup[1][0] = 0;
    for (int i = 0; i < m; i++) 
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int v;
            cin >> v;
            --v;
            born(v);
        }
        else if (c == '-')
        {
            int v;
            cin >> v;
            --v;
            die(v);
        }
        else if (c == '?')
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            cout << lca(u, v) << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAXN = 50010;
const int MAXLOG = 17;
const int INF = (int) 1e9;
 
vector<int> ch[MAXN];
vector<int> g[MAXN];
int tin[MAXN], tout[MAXN];
int binup[MAXLOG][MAXN];
int h[MAXN];
int s[MAXN];
int cur_time = 0;
int path_number[MAXN], path_pos[MAXN];
 
struct SegTree {
  SegTree() {}
 
  SegTree(const vector<int>& path, int num) {
    tree_path = path;
    int psz = path.size();
    for (int i = 0; i < psz; ++i) {
      path_pos[path[i]] = i;
      path_number[path[i]] = num;
    }
 
    int sz = 1;
    while (sz < psz) {
      sz <<= 1;
    }
 
    tree.resize(sz * 2, -INF);
    for (int i = 0; i < psz; ++i) {
      tree[sz + i] = h[path[i]];
    }
    for (int i = sz - 1; i > 0; --i) {
      tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
  }
 
  int get_rec_max(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
      return -INF;
    }
    if (l <= vl && vr <= r) {
      return tree[v];
    }
    int vm = (vl + vr) / 2;
    return max(get_rec_max(v * 2, vl, vm, l, r), get_rec_max(v * 2 + 1, vm + 1, vr, l, r));
  }
 
  int get_max(int a, int b) {
    int l = min(path_pos[a], path_pos[b]);
    int r = max(path_pos[a], path_pos[b]);
    return get_rec_max(1, 0, tree.size() / 2 - 1, l, r);
  }
 
  void update(int v, int new_h) {
    h[v] = new_h;
    int pos = path_pos[v];
    int sz = tree.size() / 2;
    pos += sz;
    tree[pos] = new_h;
    pos >>= 1;
    while (pos != 0) {
      tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
      pos >>= 1;
    }
  }
 
  int get_fst() const {
    return tree_path[0];
  }
 
  vector<int> tree;
  vector<int> tree_path;
};
 
vector<SegTree> paths;
 
void make_tree(int v, int p) {
  tin[v] = cur_time++;
  s[v] = 1;
  binup[0][v] = p;
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    ch[v].push_back(u);
    make_tree(u, v);
    s[v] += s[u];
  }
  tout[v] = cur_time++;
}
 
bool is_par(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}
 
int get_lca(int a, int b) {
  if (is_par(a, b)) {
    return a;
  }
  if (is_par(b, a)) {
    return b;
  }
 
  for (int i = MAXLOG - 1; i >= 0; --i) {
    if (!is_par(binup[i][a], b)) {
      a = binup[i][a];
    }
  }
  return binup[0][a];
}
 
void make_hld(int v, vector<int>& path) {
  path.push_back(v);
  if (ch[v].size() == 0) {
    int num = paths.size();
    paths.push_back(SegTree(path, num));
    return;
  }
 
  int mx = 0;
  int mv = -1;
  for (int u : ch[v]) {
    if (mx < s[u]) {
      mx = s[u];
      mv = u;
    }
  }
  for (int u : ch[v]) {
    if (u == mv) {
      make_hld(u, path);
    } else {
      vector<int> tmp;
      make_hld(u, tmp);
    }
  }
}
 
int get_path_max(int v, int anc) {
  if (path_number[v] == path_number[anc]) {
    return paths[path_number[v]].get_max(v, anc);
  }
 
 
  int fst = paths[path_number[v]].get_fst();
  int cans = paths[path_number[v]].get_max(fst, v);
  return max(cans, get_path_max(binup[0][fst], anc));
}
 
void set_h(int v, int new_h) {
  paths[path_number[v]].update(v, new_h);
}
 
int get_max(int a, int b) {
  int l = get_lca(a, b);
  return max(get_path_max(a, l), get_path_max(b, l));
}
 
int main() {
  ios_base::sync_with_stdio(false);
 
  freopen("mail.in", "r", stdin);
  freopen("mail.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
 
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
 
  make_tree(0, 0);
 
  for (int i = 1; i < MAXLOG; ++i) {
    for (int j = 0; j < n; ++j) {
      binup[i][j] = binup[i - 1][binup[i - 1][j]];
    }
  }
 
  vector<int> path;
  make_hld(0, path);
 
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    char c;
    int a, b;
    cin >> c >> a >> b;
 
    if (c == '!') {
      --a;
      set_h(a, b);
    } else {
      --a, --b;
      cout << get_max(a, b) << "\n";
    }
  }
  return 0;
}
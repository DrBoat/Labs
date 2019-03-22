#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 131072;
const int INF = (int) 1e9;
 
vector<pair<int, int>> reqs;
map<pair<int, int>, vector<int>> link, cut;
vector<pair<int, int>> tree[2 * MAXN];
int n, m;
 
int par[MAXN], rnk[MAXN], comp_size[MAXN];
 
void init() {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rnk[i] = 0;
    comp_size[i] = 1;
  }
}
 
inline int get_par(int v) {
  return (par[v] == v) ? (v) : (get_par(par[v]));
}
 
struct Commands {
  Commands() {}
  Commands(int np_, int nc_, bool wl_) : np(np_), nc(nc_), wl(wl_) {}
 
  int np, nc;
  bool wl;
};
 
vector<Commands> logger;
 
inline void apply_command(int a, int b) {
  int pa = get_par(a);
  int pb = get_par(b);
 
  bool flag = false;
  if (rnk[pa] == rnk[pb]) {
    rnk[pa]++;
    flag = true;
  }
  if (rnk[pa] > rnk[pb]) {
    logger.push_back(Commands(pa, pb, flag));
    par[pb] = pa;
    comp_size[pa] += comp_size[pb];
  } else {
    logger.push_back(Commands(pb, pa, flag));
    par[pa] = pb;
    comp_size[pb] += comp_size[pa];
  }
}
 
inline int get_size(int v) {
  return comp_size[get_par(v)];
}
 
inline void roll_back() {
  Commands c = logger.back();
  logger.pop_back();
  par[c.nc] = c.nc;
  comp_size[c.np] -= comp_size[c.nc];
  if (c.wl) {
    --rnk[c.np];
  }
}
 
void add_command(int v, int vl, int vr, int l, int r, pair<int, int> e) {
  if (r < vl || vr < l) {
    return;
  }
  if (l <= vl && vr <= r) {
    tree[v].push_back(e);
    return;
  }
  int vm = (vl + vr) / 2;
  add_command(v * 2, vl, vm, l, r, e);
  add_command(v * 2 + 1, vm + 1, vr, l, r, e);
}
 
bool walk_tree(int v) {
  for (pair<int, int> e : tree[v]) {
    apply_command(e.first, e.second);
  }
 
  if (v >= MAXN) {
    if (v - MAXN >= (int) reqs.size()) {
      return false;
    }
    printf("%d\n", get_size(reqs[v - MAXN].second));
  } else {
    if (!walk_tree(2 * v)) {
      return false;
    }
 
    if (!walk_tree(2 * v + 1)) {
      return false;
    }
  }
 
  int sz = tree[v].size();
  for (int i = 0; i < sz; ++i) {
    roll_back();
  }
  return true;
}
 
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    char str[10];
    int u, v;
    scanf("%s %d", str, &u);
    --u;
    switch (str[0]) {
      case 's':
        reqs.push_back({i, u});
        break;
      case 'l':
        scanf("%d", &v);
        --v;
        link[{min(u, v), max(u, v)}].push_back(i);
        break;
      case 'c':
        scanf("%d", &v);
        --v;
        cut[{min(u, v), max(u, v)}].push_back(i);
        break;
    }
  }
 
  if (reqs.size() == 0) {
    return 0;
  }
 
  init();
 
  for (auto& p : link) {
    vector<int> &l = p.second;
    vector<int> &c = cut[p.first];
    if (c.size() < l.size()) {
      c.push_back(m);
    }
 
    int sz = l.size();
    for (int i = 0; i < sz; ++i) {
      int posl = lower_bound(reqs.begin(), reqs.end(), make_pair(l[i], INF)) - reqs.begin();
      int posr = lower_bound(reqs.begin(), reqs.end(), make_pair(c[i], -INF)) - reqs.begin();
      --posr;
      if (posl > posr) {
        continue;
      }
 
      add_command(1, 0, MAXN - 1, posl, posr, p.first);
    }
  }
 
  walk_tree(1);
 
  return 0;
}
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
 
using namespace std;
 
const size_t MAX_MEM = 240 * 1024 * 1024;
char mem[MAX_MEM];
size_t cur_mem = 0;
 
void *operator new(size_t p) {
  cur_mem += p;
  return mem + cur_mem - p;
}
void operator delete(void *) {}
void operator delete(void *, long unsigned int) {}
 
void *operator new[](size_t p) {
  cur_mem += p;
  return mem + cur_mem - p;
}
void operator delete[](void *) {}
void operator delete[](void *, long unsigned int) {}
 
 
const int MAXN = 50010;
 
int n, m, k;
 
bool is_term[MAXN];
map<char, int> steps[MAXN];
 
vector<pair<int, char>> ans[MAXN];
 
unordered_set<int> p[MAXN];
int p_cnt;
int cls[MAXN], cnt[MAXN], twin[MAXN];
map<char, vector<int>> rev[MAXN];
vector<char> alp;
 
vector<int> g[MAXN], grev[MAXN];
int used[MAXN];
int mp[MAXN];
 
void scan() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int a;
    scanf("%d", &a);
    --a;
    is_term[a] = true;
  }
 
  for (int i = 0; i < m; ++i) {
    int a, b;
    char c;
    scanf("%d%d %c", &a, &b, &c);
    --a, --b;
    g[a].push_back(b);
    grev[b].push_back(a);
    steps[a][c] = b;
    alp.push_back(c);
  }
 
  sort(alp.begin(), alp.end());
  alp.resize(unique(alp.begin(), alp.end()) - alp.begin());
}
 
void preminimize();
 
void minimize() {
  preminimize();
 
 
  for (int i = 0; i < n; ++i) {
    if (used[i] != 2) {
      continue;
    }
 
    if (is_term[i]) {
      p[0].insert(i);
      cls[i] = 0;
    } else {
      p[1].insert(i);
      cls[i] = 1;
    }
  }
  p_cnt = 2;
 
  if (p[1].size() == 0) {
    --p_cnt;
  }
  if (p[0].size() == 0) {
    swap(p[0], p[p_cnt - 1]);
    --p_cnt;
  }
 
  if (p_cnt == 0) {
    printf("0 0 0\n");
    return;
  }
 
  queue<pair<int, char>> q;
  for (int i = 0; i < p_cnt; ++i) {
    for (char c : alp) {
      q.push({i, c});
    }
  }
 
  memset(twin, -1, sizeof(twin));
  for (int i = 0; i < n; ++i) {
    if (used[i] != 2) {
      continue;
    }
 
    for (pair<char, int> nxt : steps[i]) {
      rev[nxt.second][nxt.first].push_back(i);
    }
  }
 
  while (!q.empty()) {
    pair<int, char> splitter = q.front();
    q.pop();
    vector<int> inv;
    for (int v : p[splitter.first]) {
      for (int r : rev[v][splitter.second]) {
        int id = cls[r];
        if (cnt[id] == 0) {
          inv.push_back(id);
        }
        ++cnt[id];
      }
    }
 
    for (int id : inv) {
      if (cnt[id] < (int) p[id].size()) {
        twin[id] = p_cnt;
        ++p_cnt;
      }
    }
 
    unordered_set<int> temp = p[splitter.first];
    for (int v : temp) {
      for (int r : rev[v][splitter.second]) {
        int id = cls[r];
        int tid = twin[id];
        if (tid != -1) {
          p[id].erase(r);
          p[tid].insert(r);
        }
      }
    }
    for (int id : inv) {
      int tid = twin[id];
      if (tid != -1) {
        if (p[tid].size() > p[id].size()) {
          swap(p[id], p[tid]);
        }
        for (int v : p[tid]) {
          cls[v] = tid;
        }
        for (char c : alp) {
          q.push({tid, c});
        }
      }
      cnt[id] = 0;
      twin[id] = -1;
    }
  }
   
  int new_sz = p_cnt;
 
 
  if (cls[0] != 0) {
    int zcls = cls[0];
    swap(p[zcls], p[0]);
    for (int v : p[0]) {
      cls[v] = 0;
    }
    for (int v : p[zcls]) {
      cls[v] = zcls;
    }
  }
 
 
  m = 0;
  vector<int> term;
  for (int i = 0; i < new_sz; ++i) {
    int v = *(p[i].begin());
    if (is_term[v]) {
      term.push_back(i);
    }
 
    for (pair<char, int> u : steps[v]) {
      if (used[u.second] == 2) {
        ans[i].push_back({cls[u.second], u.first});
        ++m;
      }
    }
  }
 
 
  printf("%d %d %d\n", new_sz, m, (int) term.size());
  for (int i = 0; i < (int) term.size(); ++i) {
    printf("%d ", term[i] + 1);
  } 
  printf("\n");
 
  for (int i = 0; i < new_sz; ++i) {
    for (pair<int, char> nxt : ans[i]) {
      printf("%d %d %c\n", i + 1, nxt.first + 1, nxt.second);
    }
  }
}
 
void dfs(int);
void rev_dfs(int);
 
void preminimize() {
  for (int i = 0; i < n; ++i) {
    if (is_term[i]) {
      rev_dfs(i);
    }
  }
 
  dfs(0);
}
 
void dfs(int v) {
  if (used[v] == 0 || used[v] == 2) {
    return;
  }
  used[v] = 2;
  for (int u : g[v]) {
    dfs(u);
  }
}
 
void rev_dfs(int v) {
  if (used[v] == 1) {
    return;
  }
  used[v] = 1;
  for (int nxt : grev[v]) {
    rev_dfs(nxt);
  }
}
 
int main() {
  freopen("fastminimization.in", "r", stdin);
  freopen("fastminimization.out", "w", stdout);
 
  scan();
  minimize();
 
  return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 100010;
const int MAXLOG = 19;
 
int root;
int depth[MAXN];
vector<int> ch[MAXN];
int cur_time = 0;
int tin[MAXN];
int req[MAXN];
int walk_pos = 0;
int first_in[MAXN];
int powers[2 * MAXN];
pair<int, int> sparse[MAXLOG][2 * MAXN];
 
void dfs(int v, int d) {
  tin[v] = cur_time++;
  depth[v] = d;
  first_in[v] = walk_pos;
  sparse[0][walk_pos++] = {d, v};
  for (int u : ch[v]) {
    dfs(u, d + 1);
    sparse[0][walk_pos++] = {d, v};
  }
}
 
bool comp(int a, int b) {
  return tin[a] < tin[b];
}
 
int lca(int a, int b) {
  int l = min(first_in[a], first_in[b]);
  int r = max(first_in[a], first_in[b]);
  int len = r - l + 1;
  int pw = powers[len];
 
  pair<int, int> ans = min(sparse[pw][l], sparse[pw][r - (1 << pw) + 1]);
  return ans.second;
}
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == -1) {
      root = i;
    } else {
      --a;
      ch[a].push_back(i);
    }
  }
 
  dfs(root, 1);
 
   
 
  for (int i = 1; i < MAXLOG; ++i) {
    int shift = 1 << (i - 1);
    for (int j = 0; j + shift < walk_pos; ++j) {
      sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + shift]);
    }
  }
  powers[0] = 0;
  for (int i = 1; i < 2 * MAXN; ++i) {
    powers[i] = powers[i - 1];
    if ((1 << (powers[i] + 1)) < i) {
      ++powers[i];
    }
  }
 
  int g;
  scanf("%d", &g);
  for (int i = 0; i < g; ++i) {
    int k;
    scanf("%d", &k);
    if (k == 0) {
      printf("0\n");
      continue;
    }
 
    for (int j = 0; j < k; ++j) {
      scanf("%d", &req[j]);
      --req[j];
    }
 
    sort(req, req + k, &comp);
 
    int ans = depth[req[0]];
    for (int j = 1; j < k; ++j) {
      ans += depth[req[j]];
      int l = lca(req[j - 1], req[j]);
      ans -= depth[l];
    }
    printf("%d\n", ans);
  }
 
  return 0;
}
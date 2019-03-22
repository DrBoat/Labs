#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
 
using namespace std;
 
typedef long long LL;
 
const int MAXN = 100010;
const LL MOD = (LL) 1e9 + 7;
 
bool is_term[MAXN];
vector<int> grev[MAXN], g[MAXN];
bool used[MAXN], start_used[MAXN];
int color[MAXN];
LL dp[MAXN];
 
void rev_dfs(int v) {
  if (used[v]) {
    return;
  }
  used[v] = true;
  for (int nxt : grev[v]) {
    rev_dfs(nxt);
  }
}
 
bool find_cycle(int v) {
  color[v] = 1;
  for (int nxt : g[v]) {
    if (!used[nxt] || color[nxt] == 2) {
      continue;
    }
    if (color[nxt] == 1) {
      return true;
    }
    if (find_cycle(nxt)) {
      return true;
    }
  }
  color[v] = 2;
  return false;
}
 
LL calc(int v) {
  if (dp[v] != -1) {
    return dp[v];
  }
  if (!used[v]) {
    dp[v] = 0;
    return 0;
  }
  LL ans = 0;
  for (int nxt : g[v]) {
    ans += calc(nxt);
  }
  if (is_term[v]) {
    ++ans;
  }
  ans %= MOD;
  dp[v] = ans;
  return ans;
}
 
int main() {
  freopen("problem3.in", "r", stdin);
  freopen("problem3.out", "w", stdout);
 
  int n, m, k;
  cin >> n >> m >> k;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
    --a;
    is_term[a] = true;
  }
 
  for (int i = 0; i < m; ++i) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    --a, --b;
    grev[b].push_back(a);
    g[a].push_back(b);
  }
 
  for (int i = 0; i < n; ++i) {
    if (is_term[i]) {
      rev_dfs(i);
    }
  }
 
  if (!used[0]) {
    cout << 0 << endl;
    return 0;
  }
 
  if (find_cycle(0)) {
    cout << -1 << endl;
    return 0;
  }
 
  cout << calc(0) << endl;
  return 0;
}
#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long LL;
 
const int MAXN = 10000;
const int MAXL = 1010;
 
const LL MOD = (LL) 1e9 + 7;
 
map<char, vector<int>> steps[MAXN];
map<char, int> det_steps[MAXN];
bool is_term[MAXN];
bool det_term[MAXN];
 
int cnt = 0;
map<vector<int>, int> mapping;
int dp[MAXL][MAXN];
 
 
void determine(vector<int>& state) {
  int u = mapping[state];
  for (char c = 'a'; c <= 'z'; ++c) {
    vector<int> new_state;
    for (int v : state) {
      new_state.insert(new_state.end(), steps[v][c].begin(), steps[v][c].end());
    }
 
    if (new_state.size() == 0) {
      continue;
    }
 
    sort(new_state.begin(), new_state.end());
    new_state.resize(unique(new_state.begin(), new_state.end()) - new_state.begin());
     
    if (mapping.find(new_state) == mapping.end()) {
      for (int dv : new_state) {
        if (is_term[dv]) {
          det_term[cnt] = true;
          break;
        }
      }
      mapping[new_state] = cnt++;
 
      determine(new_state);
    }
 
    det_steps[u][c] = mapping[new_state];
  }
}
 
int main() {
  freopen("problem5.in", "r", stdin);
  freopen("problem5.out", "w", stdout);
 
  int n, m, k, l;
  cin >> n >> m >> k >> l;
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
    steps[a][c].push_back(b);
  }
 
  vector<int> init(1, 0);
  mapping[init] = cnt++;
  if (is_term[0]) {
    det_term[0] = true;
  }
 
 
  determine(init);
 
  int sz = cnt;
  for (int i = 0; i < sz; ++i) {
    if (det_term[i]) {
      dp[0][i] = 1;
    }
  }
 
  for (int i = 1; i <= l; ++i) {
    for (int j = 0; j < sz; ++j) {
      LL sum = 0;
      for (pair<char, int> nxt : det_steps[j]) {
        sum += dp[i - 1][nxt.second];
      }
      sum %= MOD;
      dp[i][j] = sum;
    }
  }
 
  cout << dp[l][0] << endl;
 
  return 0;
}
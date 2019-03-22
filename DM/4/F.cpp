#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
const int MAXN = 100010;
bool is_term[2][MAXN];
map<char, int> steps[2][MAXN];
int mp[MAXN];
bool used[MAXN];
 
bool isomorphism(int v1, int v2) {
  if (used[v1]) {
    return true;
  }
 
  used[v1] = true;
  for (pair<char, int> step : steps[0][v1]) {
    char c = step.first;
    if (steps[1][v2].find(c) == steps[1][v2].end()) {
      return false;
    }
 
    mp[step.second] = steps[1][v2][c];
    if (!isomorphism(step.second, mp[step.second])) {
      return false;
    }
  }
  return true;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  freopen("isomorphism.in", "r", stdin);
  freopen("isomorphism.out", "w", stdout);
 
  int n[2], m[2], k[2];
 
  for (int i = 0; i < 2; ++i) {
    cin >> n[i] >> m[i] >> k[i];
    for (int j = 0; j < k[i]; ++j) {
      int a;
      cin >> a;
      --a;
      is_term[i][a] = true;
    }
 
    for (int j = 0; j < m[i]; ++j) {
      int a, b;
      char c;
      cin >> a >> b >> c;
      --a, --b;
      steps[i][a][c] = b;
    }
  }
 
  if (n[0] != n[1] || m[0] != m[1] || k[0] != k[1]) {
    cout << "NO" << endl;
    return 0;
  }
 
  memset(mp, -1, sizeof(mp));
  mp[0] = 0;
 
  if (isomorphism(0, 0)) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n[0]; ++i) {
      if (used[mp[i]]) {
        cout << "NO" << endl;
        return 0;   
      }
      used[mp[i]] = true;
    }
 
    for (int i = 0; i < n[0]; ++i) {
      if (is_term[0][i] != is_term[1][mp[i]]) {
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
 
 
  return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <queue>
 
using namespace std;
 
const int MAXN = 1010;
 
bool is_term[2][MAXN];
map<char, int> steps[2][MAXN];
int n[2], m[2], k[2];
bool used[MAXN][MAXN];
 
 
bool is_eq() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    pair<int, int> st = q.front();
    q.pop();
    if (is_term[0][st.first] != is_term[1][st.second]) {
      return false;
    }
    used[st.first][st.second] = true;
 
    for (char c = 'a'; c <= 'z'; ++c) {
      int nxt0 = steps[0][st.first][c];
      int nxt1 = steps[1][st.second][c];
 
      if (!used[nxt0][nxt1]) {
        q.push({nxt0, nxt1});
      }
    }
  }
  return true;
}
 
int main() {
  freopen("equivalence.in", "r", stdin);
  freopen("equivalence.out", "w", stdout);
 
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
 
    for (int j = 0; j < n[i]; ++j) {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (steps[i][j].find(c) == steps[i][j].end()) {
          steps[i][j][c] = n[i];
        }
      }
    }
 
    for (char c = 'a'; c <= 'z'; ++c) {
      steps[i][n[i]][c] = n[i];
    }
    ++n[i];
  }
   
  if (is_eq()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
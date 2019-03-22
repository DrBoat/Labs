#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
const int MAXN = 110;
 
bool is_term[MAXN];
map<char, vector<int>> steps[MAXN];
 
bool walk(vector<int>& state, int pos, const string& str) {
  if (state.size() == 0) {
    return false;
  }
 
  if (pos == (int) str.size()) {
    for (int v : state) {
      if (is_term[v]) {
        return true;
      }
    }
    return false;
  }
 
  vector<int> new_state;
  char c = str[pos];
  for (int v : state) {
    new_state.insert(new_state.end(), steps[v][c].begin(), steps[v][c].end());
  }
  sort(new_state.begin(), new_state.end());
  new_state.resize(unique(new_state.begin(), new_state.end()) - new_state.begin());
  return walk(new_state, pos + 1, str);
}
 
int main() {
  ios_base::sync_with_stdio(false);
  freopen("problem2.in", "r", stdin);
  freopen("problem2.out", "w", stdout);
 
  string str;
  cin >> str;
 
  int n, m, k;
  cin >> n >> m >> k;
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
  if (walk(init, 0, str)) {
    cout << "Accepts" << endl;
  } else {
    cout << "Rejects" << endl;
  }
  return 0;
}
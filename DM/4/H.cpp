#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
 
using namespace std;
 
class Aut {
 public:
  Aut() {}
 
  void scan() {
    int n, m, k;
    cin >> n >> m >> k;
    sz = n;
    is_term.resize(n, 0);
    steps.resize(n);
    for (int i = 0; i < k; ++i) {
      int a;
      cin >> a;
      --a;
      is_term[a] = 1;
    }
 
    for (int i = 0; i < m; ++i) {
      int a, b;
      char c;
      cin >> a >> b >> c;
      --a, --b;
      steps[a][c] = b;
    }
  }
 
  void print() const {
    int m = 0, k = 0, n = sz;
    for (int i = 0; i < sz; ++i) {
      m += steps[i].size();
      if (is_term[i] == 1) {
        ++k;
      }
    }
 
    cout << sz << " " << m << " " << k << "\n";
    for (int i = 0; i < sz; ++i) {
      if (is_term[i] == 1) {
        cout << i + 1 << " ";
      }
    }    
    cout << "\n";
    for (int i = 0; i < n; ++i) {
      for (pair<char, int> nxt : steps[i]) {
        cout << i + 1 << " " << nxt.second + 1 << " " << nxt.first << "\n";
      }
    }
    //cout << endl;
  }
 
  void minimize() {
    preminimize();
 
    //print();
 
    if (sz == 0) {
      return;
    }
 
    vector<unordered_set<int>> p(2);
    vector<int> cls(sz);
    for (int i = 0; i < sz; ++i) {
      if (is_term[i] == 1) {
        p[0].insert(i);
        cls[i] = 0;
      } else {
        p[1].insert(i);
        cls[i] = 1;
      }
    }
 
    if (p[1].size() == 0) {
      p.pop_back();
    }
    if (p[0].size() == 0) {
      swap(p[0], p.back());
      p.pop_back();
    }
 
 
    queue<pair<int, char>> q;
    for (int i = 0; i < (int) p.size(); ++i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        q.push({i, c});
      }
    }
 
    vector<int> count(2 * sz, 0);
    vector<int> twin(2 * sz, -1);
    vector<map<char, vector<int>>> rev(2 * sz);
    for (int i = 0; i < sz; ++i) {
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
          if (count[id] == 0) {
            inv.push_back(id);
          }
          ++count[id];
        }
      }
 
      for (int id : inv) {
        if (count[id] < (int) p[id].size()) {
          twin[id] = p.size();
          p.push_back(unordered_set<int>());
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
          for (char c = 'a'; c <= 'z'; ++c) {
            q.push({tid, c});
          }
        }
        count[id] = 0;
        twin[id] = -1;
      }
    }
/*
    cout << "------" << endl;
    for (auto st : p) {
      for (int v : st) {
        cout << v << " ";
      }
      cout << endl;
    }
    cout << "------" << endl;*/
 
    int new_sz = p.size();
    vector<map<char, int>> new_steps(new_sz);
    vector<int> new_is_term(new_sz, 0);
 
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
 
    for (int i = 0; i < sz; ++i) {
      if (is_term[i]) {
        new_is_term[cls[i]] = 1;
      }
    }
 
    for (int i = 0; i < new_sz; ++i) {
      int v = *(p[i].begin());
      for (pair<char, int> u : steps[v]) {
        new_steps[i][u.first] = cls[u.second];
      }
    }
 
 
    sz = new_sz;
    steps = new_steps;
    is_term = new_is_term;
  }
 
  void preminimize() {
    vector<int> used(sz, 0);
    vector<vector<int>> grev(sz);
    for (int i = 0; i < sz; ++i) {
      for (pair<char, int> nxt : steps[i]) {
        grev[nxt.second].push_back(i);
      }
    }
 
    for (int i = 0; i < sz; ++i) {
      if (is_term[i] == 1) {
        rev_dfs(i, grev, used);
      }
    }
 
    dfs(0, used);
    // used[0] = 2;
 
    int new_sz = 0;
    vector<map<char, int>> new_steps;
    vector<int> new_is_term;
    vector<int> mp(sz, -1);
    vector<int> useful;
    for (int i = 0; i < sz; ++i) {
      if (used[i] == 2) {
        mp[i] = new_sz;
        useful.push_back(i);
        ++new_sz;
        new_is_term.push_back(is_term[i]);
      }
    }
    new_steps.resize(new_sz);
 
    for (int v : useful) {
      int to = mp[v];
      for (pair<char, int> u : steps[v]) {
        if (used[u.second] == 2) {
          new_steps[to][u.first] = mp[u.second];
        }
      }
    }
 
    sz = new_sz;
    steps = new_steps;
    is_term = new_is_term;
  }
 
  void dfs(int v, vector<int>& used) {
    if (used[v] == 0 || used[v] == 2) {
      return;
    }
    used[v] = 2;
    for (pair<char, int> u : steps[v]) {
      dfs(u.second, used);
    }
  }
 
  void rev_dfs(int v, const vector<vector<int>>& grev, vector<int>& used) {
    if (used[v] == 1) {
      return;
    }
    used[v] = 1;
    for (int nxt : grev[v]) {
      rev_dfs(nxt, grev, used);
    }
  }
 
  int sz;
  vector<map<char, int>> steps;
  vector<int> is_term;
};
 
int main() {
  ios_base::sync_with_stdio(false);
 
  freopen("minimization.in", "r", stdin);
  freopen("minimization.out", "w", stdout);
 
  Aut a;
  a.scan();
  a.minimize();
  a.print();
  return 0;
}
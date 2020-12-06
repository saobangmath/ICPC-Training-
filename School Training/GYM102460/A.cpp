#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

using vii = vector<vector<int>>;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  map<vii, int> f;
  map<vii, vii> trace;
  vii S(6, vector<int>(6));
  REP(i, 6) REP(j, 6) cin >> S[i][j];
  f[S] = 0;
  queue<vii> q;
  q.emplace(S);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    if (u[2][5] == 1) {
      cout << 2 + f[u];
      return 0;
    }
    if (f[u] == 9) break;
    if (f[u] == 8) continue;
    vector<char> vis(11);
    REP(i, 6) REP(j, 6) if (u[i][j] && !vis[u[i][j]]) {
      vis[u[i][j]] = 1;
      // same j
      if (i < 5 && u[i][j] == u[i + 1][j]) {
        int pi = i < 4 && u[i][j] == u[i + 2][j] ? i + 2 : i + 1;
        // up
        if (i && !u[i - 1][j]) {
          auto v = u;
          v[i - 1][j] = u[i][j], v[pi][j] = 0;
          if (!f.count(v)) {
            f[v] = f[u] + 1;
            q.emplace(v);
          }
        }
        // down
        if (pi < 5 && !u[pi + 1][j]) {
          auto v = u;
          v[pi + 1][j] = u[i][j], v[i][j] = 0;
          if (!f.count(v)) {
            f[v] = f[u] + 1;
            q.emplace(v);
          }
        }
      }
      // same i
      if (j < 5 && u[i][j] == u[i][j + 1]) {
        int pj = j < 4 && u[i][j] == u[i][j + 2] ? j + 2 : j + 1;
        // left
        if (j && !u[i][j - 1]) {
          auto v = u;
          v[i][j - 1] = u[i][j], v[i][pj] = 0;
          if (!f.count(v)) {
            f[v] = f[u] + 1;
            q.emplace(v);
          }
        }
        // right
        if (pj < 5 && !u[i][pj + 1]) {
          auto v = u;
          v[i][pj + 1] = u[i][j], v[i][j] = 0;
          if (!f.count(v)) {
            f[v] = f[u] + 1;
            q.emplace(v);
          }
        }
      }
    }
  }
  cout << -1;
}
/*
 2 2 0 0 0 7
 3 0 0 5 0 7
 3 1 1 5 0 7
 3 0 0 5 0 0
 4 0 0 0 8 8
 4 0 6 6 6 0

 0 2 0 6 6 0
 0 2 0 0 7 0
 0 3 1 1 7 0
 0 3 4 4 8 0
 0 5 5 5 8 0
 0 0 0 0 0 0
 */
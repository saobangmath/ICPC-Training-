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

const int maxn = 11234;

int n, m, comp[maxn], c[maxn];
int f[maxn][maxn / 2];
vector<int> G[maxn], cc[maxn][2];
int ans[maxn];

bool dfs(int u, int i, int col) {
  comp[u] = i;
  c[u] = col;
  cc[i][col].eb(u);
  for (auto v : G[u]) {
    if (comp[v] && c[v] == c[u]) return false;
    if (!comp[v] && !dfs(v, i, col ^ 1)) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  if (m == 0) {
    FOR(i, 1, n) printf("%d ", i);
    return 0;
  }
  if (n & 1) {
    puts("-1");
    return 0;
  }
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].eb(b);
    G[b].eb(a);
  }
  reset(c, -1);
  int cnt = 0;
  FOR(i, 1, n) if (!comp[i] && !dfs(i, ++cnt, 0)) {
    puts("-1");
    return 0;
  }
  reset(f, -1);
  f[0][0] = 0;
  int tot = 0;
  REP(i, cnt) {
    REP(j, n / 2 + 1) if (f[i][j] != -1) {
      int k = tot - j;
      if (k > n / 2) continue;
      int nj = j + cc[i + 1][0].size(), nk = k + cc[i + 1][1].size();
      if (nj <= n / 2 && nk <= n / 2) f[i + 1][nj] = j;
      nj = j + cc[i + 1][1].size(), nk = k + cc[i + 1][0].size();
      if (nj <= n / 2 && nk <= n / 2) f[i + 1][nj] = j;
    }
    tot += cc[i + 1][0].size() + cc[i + 1][1].size();
  }
  if (f[cnt][n / 2] == -1) {
    puts("-1");
    return 0;
  }
  int even = 2, odd = 1;
  int j = n / 2;
  ROF(i, cnt, 1) {
    int nj = f[i][j];
    if (cc[i][0].size() == j - nj) {
      for (auto x : cc[i][0]) {
        ans[even] = x;
        even += 2;
      }
      for (auto x : cc[i][1]) {
        ans[odd] = x;
        odd += 2;
      }
    } else {
      for (auto x : cc[i][1]) {
        ans[even] = x;
        even += 2;
      }
      for (auto x : cc[i][0]) {
        ans[odd] = x;
        odd += 2;
      }
    }
    j = nj;
  }
  FOR(i, 1, n) printf("%d ", ans[i]);
}

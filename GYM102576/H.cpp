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

const int maxn = 312;

int n, m;
ll x[maxn], y[maxn];
bool G[maxn][maxn], vis[maxn][maxn][2];
double f[maxn][maxn][2];

double get(int i, int j) {
  return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

double dfs(int i, int j, bool d) {
  if(vis[i][j][d]) return f[i][j][d];
  vis[i][j][d] = true;
  double ret = 0;
  if(!d) {
    FOR(k, i + 1, (j > i ? j : j + n) - 1) if(G[j][k % n])
      chkmax(ret, get(j, k % n) + max(dfs(j, k % n, true), dfs(i, k % n, false)));
  } else {
    FOR(k, j + 1, (i > j ? i : i + n) - 1) if(G[j][k % n])
      chkmax(ret, get(j, k % n) + max(dfs(j, k % n, false), dfs(i, k % n, true)));
  }
  return f[i][j][d] = ret;
}

void solve() {
  scanf("%d", &n);
  REP(i, n) REP(j, n) {
    G[i][j] = false;
    reset(vis[i][j], 0);
  }
  REP(i, n) scanf("%lld%lld", x + i, y + i);
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G[u][v] = G[v][u] = true;
  }
  double ans = 0;
  REP(i, n) FOR(j, i + 1, n - 1) if (G[i][j])
    chkmax(ans, get(i, j) + max({dfs(i, j, true), dfs(i, j, false), dfs(j, i, true), dfs(j, i, false)}));
  printf("%.10lf\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}
/*
2
4
0 0
1 0
1 1
0 1
3
1 3
2 4
3 4
4
0 0
1 0
1 1
0 1
4
1 4
4 3
3 2
2 1
 */
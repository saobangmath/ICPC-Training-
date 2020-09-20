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

const int maxn = 112345;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n;
vector<int> G[maxn];
int f[maxn], sz[maxn], g[maxn];
int u[maxn], v[maxn], w[maxn];

void dfs(int x, int par) {
  for (auto i : G[x]) {
    int y = u[i] ^ v[i] ^ x;
    if (y == par) continue;
    dfs(y, x);
    f[x] = add(f[x], f[y]);
    f[x] = add(f[x], mul(mul(sz[x], sz[y]), w[i]));
    f[x] = add(f[x], mul(g[x], sz[y]));
    f[x] = add(f[x], mul(g[y], sz[x]));
    sz[x] += sz[y];
    g[x] = add(g[x], add(g[y], mul(sz[y], w[i])));
  }
}

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) G[i].clear();
  FOR(i, 1, n) f[i] = g[i] = 0, sz[i] = 1;
  FOR(i, 1, n - 1) {
    scanf("%d%d%d", u + i, v + i, w + i);
    G[u[i]].eb(i); G[v[i]].eb(i);
  }
  dfs(1, 0);
  int ans = 0;
  FOR(i, 1, n) ans = add(ans, f[i]);
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  FOR(i, 1, T) {
    printf("Case %d: ", i);
    solve();
  }
}

/*
2

 7
 1 2 3
 1 3 2
 2 4 1
 2 5 4
 3 6 6
 3 7 8

 6
 1 2 3
 1 3 2
 1 4 4
 3 5 7
 3 6 1
 */
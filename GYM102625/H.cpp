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

int n, q, clk;
int a[maxn], in[maxn], out[maxn], f[maxn][18], bits[maxn], seq[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  in[u] = ++clk;
  for (auto v : G[u]) if (v != par) dfs(v, u);
  out[u] = clk;
}

int query(int l, int r) {
  if (l > r) return -1;
  int k = bits[r - l + 1];
  return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", a + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  dfs(1, 0);
  bits[1] = 0;
  FOR(i, 2, n) bits[i] = bits[i / 2] + 1;
  FOR(i, 1, n) seq[in[i]] = a[i];
  FOR(i, 1, n) f[i][0] = seq[i];
  FOR(j, 1, 17) FOR(i, 1, n - (1 << j) + 1) f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
  while (q--) {
    int k; scanf("%d", &k);
    int L, R; scanf("%d", &L);
    R = out[L];
    L = in[L] + 1;
    vector<int> s;
    REP(i, k - 1) {
      int x; scanf("%d", &x);
      if (in[x] > R || out[x] < L) continue;
      s.eb(x);
    }
    if (L > R) {
      puts("-1");
      continue;
    }
    if (s.empty()) {
      printf("%d\n", query(L, R));
      continue;
    }
    sort(all(s), [&](int i, int j) { return in[i] < in[j]; });
    if (in[s[0]] < L) {
      puts("-1");
      continue;
    }
    int ans = -1;
    for (auto x : s) {
      if (in[x] > L) chkmax(ans, query(L, in[x] - 1));
      chkmax(L, out[x] + 1);
    }
    if (L <= R) chkmax(ans, query(L, R));
    printf("%d\n", ans);
  }
}

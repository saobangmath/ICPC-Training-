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

const int MOD = 1e9 + 7;
const int maxn = 1123;
const int maxk = 65;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int n, m, K;
int f[maxn][maxk][maxk], g[maxn][maxk][maxk], h[maxn][maxk][maxk];

int main() {
  scanf("%d%d%d", &n, &m, &K);
  chkmin(m, K);
  f[0][m][0] = h[0][m][0] = 1;
  REP(j, m + 1) g[0][j][0] = 1;
  FOR(i, 1, n + 1) ROF(j, m, 0) ROF(k, K, 0) {
    int d = min(j, k);
    f[i][j][k] = add(add(h[i - 1][j - d][k - d], MOD - h[i - 1][j][k]), g[i - 1][j][k]);
    g[i][j][k] = h[i][j][k] = f[i][j][k];
    if (j != m) g[i][j][k] = add(g[i][j][k], g[i][j + 1][k]);
    if (j != m && k != K) h[i][j][k] = add(h[i][j][k], h[i][j + 1][k + 1]);
  }
  int ans = 0;
  REP(k, K + 1) ans = add(ans, f[n + 1][m][k]);
  printf("%d", ans);
}

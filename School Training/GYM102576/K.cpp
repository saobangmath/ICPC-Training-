#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(kk) ((kk) * (kk))
#define all(kk) (kk).begin(), (kk).end()
#define reset(kk, y) memset(kk, y, sizeof(kk))
#define uni(kk) (kk).erase(unique(all(kk)), (kk).end())
#define BUG(kk) cerr << #kk << " = " << (kk) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 12;
const int MOD = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

int n, m, k;
int fac[maxn * maxn + 5], ifac[maxn * maxn + 5], f[2][1 << maxn][maxn * maxn / 2 + 5], p2[maxn * maxn + 5];
char mat[maxn * maxn + 5][maxn * maxn + 5];

void solve() {
  scanf("%d%d%d", &n, &m, &k);
  int tot = 0;
  REP(i, n) {
    scanf("%s", mat[i]);
    REP(j, m) tot += mat[i][j] == '.';
  }
  if (n < m) {
    REP(i, m) REP(j, i) swap(mat[i][j], mat[j][i]);
    swap(n, m);
  }
  reset(f, 0);
  int now = 0;
  f[now][0][0] = 1;
  REP(i, n) REP(j, m) {
    now = 1 - now;
    int pre = 1 - now;
    reset(f[now], 0);
    REP(mask, 1 << m) REP(kk, k + 1) {
      f[now][mask][kk] = add(f[now][mask][kk], f[pre][mask & ~(1 << j)][kk]);
      if (kk) {
        if (j && mat[i][j] == '.' && mat[i][j - 1] == '.' && (mask >> (j - 1) & 3) == 0)
          f[now][mask][kk] = add(f[now][mask][kk], f[pre][mask | 1 << (j - 1)][kk - 1]);
        if (i && mat[i][j] == '.' && mat[i - 1][j] == '.' && (mask >> j & 1) == 0)
          f[now][mask][kk] = add(f[now][mask][kk], f[pre][mask | 1 << j][kk - 1]);
      }
    }
  }
  int ans = 0;
  REP(kk, k + 1) {
    int sig = kk & 1 ? MOD - 1 : 1;
    int cur = mul(mul(p2[kk], f[now][0][kk]), mul(fac[k], ifac[k - kk]));
    cur = mul(cur, mul(fac[tot - 2 * kk], ifac[tot - 2 * k]));
    ans = add(ans, mul(sig, cur));
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  fac[0] = ifac[0] = p2[0] = 1;
  FOR(i, 1, 144) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = pow_mod(fac[i], MOD - 2);
    p2[i] = add(p2[i - 1], p2[i - 1]);
  }
  while (T--) solve();
}
/*
2
2 2 2
..
..
4 4 3
X.X.
....
.X..
...X


1
12 12 72
............
............
............
............
............
............
............
............
............
............
............
............
 */
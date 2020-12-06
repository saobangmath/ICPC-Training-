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

const int maxn = 20;

ll f[maxn][maxn * maxn], fac[maxn], g[maxn * maxn];
int id[maxn * maxn], lis[maxn];
int n, a, b, c, d;

void solve() {
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  int s = n * (n - 1) / 2;
  REP(i, s + 1) {
    g[i] = min(a * i, a * (s - i) + b);
    id[i] = i;
  }
  sort(id + 1, id + s + 1, [&](int i, int j) { return g[i] < g[j]; });
  ll sum = 0, rem = fac[n], nom = 0, den = 0;
  double mv = 1e18;
  REP(_i, s) {
    int i = id[_i];
    sum += g[i] * f[n][i];
    rem -= f[n][i];
    ll fi = sum + rem * c, se = fac[n] - rem;
    if (!se) continue;
    double v = double(fi) / se;
    if (g[i] <= v + c && g[id[_i + 1]] >= v + c) {
      fi += se * c;
      ll aux = gcd(fi, se);
      nom = fi / aux, den = se / aux;
      mv = v;
      break;
    }
  }
  while (d--) {
    FOR(i, 1, n) scanf("%d", lis + i);
    int inv = 0;
    FOR(i, 1, n - 1) FOR(j, i + 1, n) inv += lis[i] > lis[j];
    if (g[inv] <= mv + c) printf("%lld/1\n", g[inv]);
    else printf("%lld/%lld\n", nom, den);
  }
}

int main() {
  f[0][0] = fac[0] = 1;
  FOR(i, 1, 16) REP(j, i * (i - 1) / 2 + 1) REP(k, min(i, j + 1)) f[i][j] += f[i - 1][j - k];
  FOR(i, 1, 16) fac[i] = fac[i - 1] * i;
  int T; scanf("%d", &T);
  while (T--) solve();
}
/*
1
6 1 1 1 3
1 2 3 4 5 6
5 4 3 2 1 6
6 4 2 1 3 5
 */
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

const double eps = 1e-15;

double n, r, p;

inline int dcmp(double x) {
  if (abs(x) <= eps) return 0;
  return x > 0 ? 1 : -1;
}

double pow(double a, int pw) {
  double ret = 1;
  while (pw) {
    if (pw & 1) ret = ret * a;
    a = a * a;
    pw >>= 1;
  }
  return ret;
}

void solve() {
  scanf("%lf%lf%lf", &n, &r, &p);
  r = 1 + 0.01 * r;
  int lo = 0, hi = 4400;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (dcmp(n * pow(r, mi) - p) >= 0) hi = mi;
    else lo = mi + 1;
  }
  printf("%d\n", lo);
}

int main() {
  int T; scanf("%d", &T);
  FOR(i, 1, T) {
    printf("Case %d: ", i);
    solve();
  }
}

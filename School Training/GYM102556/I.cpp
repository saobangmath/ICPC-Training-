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

struct Point {
  ll x, y;
  ll operator * (const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
  Point operator - (const Point &rhs) const {
    return {x - rhs.x, y - rhs.y};
  }
} pts[maxn];

int n;
bitset<maxn> L[maxn][maxn], R[maxn][maxn];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%lld%lld", &pts[i].x, &pts[i].y);
  REP(i, n) REP(j, n) REP(k, n) if (i != j && j != k && i != k) {
    if ((pts[j] - pts[i]) * (pts[k] - pts[i]) > 0) L[i][j].set(k);
    else R[i][j].set(k);
  }
  ll ans = 0;
  auto C3 = [&](ll sz) {
    return sz * (sz - 1) * (sz - 2) / 6;
  };
  REP(i, n) FOR(j, i + 1, n - 1) FOR(k, j + 1, n - 1) {
    int sz = (L[i][j] & L[j][k] & L[k][i]).count() + (R[i][j] & R[j][k] & R[k][i]).count();
    ans += C3(sz);
  }
  printf("%lld", ans);
}

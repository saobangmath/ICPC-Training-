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

const int maxn = 4123;
const double eps = 1e-11;

int n, vf, vp, vh;
tuple<int, int, int> pts[maxn];
double f[maxn];

void solve() {
  int Sx, Sy, Tx, Ty;
  cin >> Sx >> Sy >> Tx >> Ty;
  cin >> vf >> vp >> vh;
  cin >> n;
  pts[n + 1] = make_tuple(0, Tx, Ty);
  REP(i, n + 1) {
    int x, y, v;
    cin >> x >> y >> v;
    pts[i] = make_tuple(v, x, y);
  }
  sort(pts + 1, pts + n + 1);
  fill(f + 1, f + n + 2, 1e18);
  f[0] = 0;
  set<pair<double, int>> q;
  q.emplace(0, 0);
  FOR(i, 1, n + 1) {
    auto [_, xi, yi] = pts[i];
    REP(j, i) {
      auto [v, xj, yj] = pts[j];
      if (v <= vp) continue;
      double dis = sqrt(sqr(xi - xj) + sqr(yi - yj));
      double cost = dis / vh + dis / vh * vp / (v - vp);
      chkmin(f[i], f[j] + cost);
    }
  }
  cout << fixed << setprecision(20) << f[n + 1] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}

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

const int maxn = 212;
const double eps = 1e-12;
const double delta = 1e-7;

int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

int n;
int w[2][maxn], b[2];

void solve() {
  cin >> n;
  REP(j, 2) {
    REP(i, n) cin >> w[j][i];
    cin >> b[j];
  }
  if (b[0] * b[1] < 0) {
    REP(i, n) cout << 0 << ' ';
    cout << '\n';
    return;
  }
  vector<double> ans(n);
  bool good = false;
  REP(i, n) {
    double x;
    auto f = [&](int k, int b) {
      return dcmp(k * x + b);
    };
    if (w[0][i]) {
      x = double(-b[0]) / w[0][i] + delta;
      if (f(w[0][i], b[0]) * f(w[1][i], b[1]) < 0) {
        ans[i] = x;
        good = true;
        break;
      }
      x = double(-b[0]) / w[0][i] - delta;
      if (f(w[0][i], b[0]) * f(w[1][i], b[1]) < 0) {
        ans[i] = x;
        good = true;
        break;
      }
    }
    if (w[1][i]) {
      x = double(-b[1]) / w[1][i] + delta;
      if (f(w[0][i], b[0]) * f(w[1][i], b[1]) < 0) {
        ans[i] = x;
        good = true;
        break;
      }
      x = double(-b[1]) / w[1][i] - delta;
      if (f(w[0][i], b[0]) * f(w[1][i], b[1]) < 0) {
        ans[i] = x;
        good = true;
        break;
      }
    }
  }
  if (good) {
    cout << fixed << setprecision(11);
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  } else cout << "No\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
/*
 2
 2
 1 -1 1
 1 -1 -1
 2
 1 -1 0
 2 -2 0
 */
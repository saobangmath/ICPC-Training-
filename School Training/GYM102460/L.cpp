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

struct Point {
  ll x, y;

  bool operator==(const Point &rhs) const {
    return x == rhs.x && y == rhs.y;
  }

  bool operator<(const Point &rhs) const {
    return x == rhs.x ? y < rhs.y : x < rhs.x;
  }

  Point operator-(const Point &rhs) const {
    return {x - rhs.x, y - rhs.y};
  }
};
using Vector = Point;

ll getCross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

vector<Point> convexHull(vector<Point> p) {
  sort(all(p)); uni(p);
  int n = p.size(), m = 0;
  vector<Point> ch(n + 1);
  REP(i, n) {
    while (m > 1 && getCross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  ROF(i, n - 2, 0) {
    while (m > k && getCross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
    ch[m++] = p[i];
  }
  if (n > 1) m--;
  ch.resize(m);
  return ch;
}

void solve() {
  int n; cin >> n;
  vector<Point> p(n);
  map<Point, int> cnt;
  REP(i, n) {
    cin >> p[i].x >> p[i].y;
    cnt[p[i]]++;
  }
  auto ch = convexHull(p);
  if (ch.size() <= 2) {
    cout << 0 << '\n';
    return;
  }
  ll ans = 0;
  if (ch.size() == 3) {
    ll A1 = abs(getCross(ch[1] - ch[0], ch[2] - ch[0]));
    auto check = [&](int i) {
      if (none_of(all(ch), [&](Point x) { return x == p[i]; })) return true;
      return cnt[p[i]] > 1;
    };
    REP(i, n) if (check(i)) {
      REP(j, 3) {
        int k1 = j, k2 = (j + 1) % 3;
        ll A2 = getCross(ch[k1] - p[i], ch[k2] - p[i]);
        chkmax(ans, A1 - A2);
      }
    }
  } else {
    n = ch.size();
    REP(i, n) {
      int k1 = (i + 1) % n, k2 = (i + 3) % n;
      for (int j = (i + 2) % n; j != (i - 1 + n) % n; j = (j + 1) % n) {
        Vector dia = ch[j] - ch[i];
        while (abs(getCross(ch[(k1 + 1) % n] - ch[i], dia)) >= abs(getCross(ch[k1] - ch[i], dia))) k1 = (k1 + 1) % n;
        while (abs(getCross(ch[(k2 + 1) % n] - ch[i], dia)) >= abs(getCross(ch[k2] - ch[i], dia))) k2 = (k2 + 1) % n;
        ll A = abs(getCross(ch[k1] - ch[i], dia)) + abs(getCross(ch[k2] - ch[i], dia));
        chkmax(ans, A);
      }
    }
  }
  cout << ans / 2;
  if (ans % 2 == 1) cout << ".5";
  cout << '\n';
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
3
 5
 0 0
 1 0
 3 1
 1 2
 0 1
 4
 0 0
 4 0
 0 4
 1 1
 4
 0 0
 1 1
 2 2
 1 1

 1
 4
 0 0
 1 0
 0 1
 3 2
 */
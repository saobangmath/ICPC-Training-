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

const double eps = 1e-9;

struct Point {
  double x, y;

  Point operator-(const Point &rhs) const {
    return {x - rhs.x, y - rhs.y};
  }
};
using Vector = Point;

struct Segment {
  Point a, b;
};

double getCross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

double getDot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}

int dcmp(double x) {
  if (abs(x) <= eps) return 0;
  return x > 0 ? 1 : -1;
}

bool onSegment(Point p, Segment s) {
  Vector A = s.a - p, B = s.b - p;
  return dcmp(getCross(A, B)) == 0 && dcmp(getDot(A, B)) <= 0;
}

bool onLine(Point p, Point a, Point b) {
  Vector A = a - p, B = b - p;
  return dcmp(getCross(A, B)) == 0;
}

double proj(Point p, Point a) {
  return p.x + (a.x - p.x) / (p.y - a.y) * p.y;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Point> pts(n);
  REP(i, n) cin >> pts[i].x >> pts[i].y;
  vector<Segment> segs(m);
  REP(i, m) {
    cin >> segs[i].a.x >> segs[i].a.y >> segs[i].b.x >> segs[i].b.y;
    if (segs[i].a.x > segs[i].b.x) swap(segs[i].a, segs[i].b);
  }
  vector<pair<double, int>> events;
  auto handle = [&](Point p) {
    vector<pair<double, double>> intervals;
    REP(i, m) {
      if (onSegment(p, segs[i])) {
        intervals.clear();
        intervals.eb(-1e18, 1e18);
        break;
      }
      if (onLine(p, segs[i].a, segs[i].b) || dcmp(p.y - min(segs[i].a.y, segs[i].b.y)) <= 0) continue;
      if (dcmp(p.y - max(segs[i].a.y, segs[i].b.y)) >= 0) {
        double x1 = proj(p, segs[i].a), x2 = proj(p, segs[i].b);
        if (x1 > x2) swap(x1, x2);
        intervals.eb(x1, x2);
      } else {
        Point a = segs[i].a, b = segs[i].b;
        if (a.y > b.y) swap(a, b);
        if (dcmp(getCross(a - p, b - p)) < 0) intervals.eb(-1e18, proj(p, a));
        else intervals.eb(proj(p, a), 1e18);
      }
    }
    sort(all(intervals));
    int n = intervals.size();
    for (int i = 0; i < n; ) {
      int j = i;
      double r = intervals[i]._2;
      while (j + 1 < n && intervals[j + 1]._1 <= r) {
        chkmax(r, intervals[j + 1]._2);
        j++;
      }
      events.eb(intervals[i]._1, 1);
      events.eb(r, -1);
      i = j + 1;
    }
  };
  REP(i, n) handle(pts[i]);
  sort(all(events));
  double ans = 0;
  int cnt = 0;
  REP(i, events.size()) {
    cnt += events[i]._2;
    if (cnt == n) {
      ans += events[i + 1]._1 - events[i]._1;
    }
  }
  if (ans > 1e9 - eps) cout << -1 << '\n';
  else cout << fixed << setprecision(20) << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}

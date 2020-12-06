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

const ll inf = 1e18;
const int maxn = 212345;

inline ll f(pair<ll, ll> coeff, ll x) {
  return coeff._1 * x + coeff._2;
}

inline bool check(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
  double u = double(b._2 - a._2) / (a._1 - b._1);
  double v = double(b._2 - c._2) / (c._1 - b._1);
  return u <= v;
}

struct Hull {
  vector<pair<ll, ll>> q;

  void add(ll k, ll b) {
    if (!q.empty() && q.back()._1 == k) {
      chkmin(b, q.back()._2);
      q.pop_back();
    }
    while (q.size() > 1 && !check(q[q.size() - 2], q.back(), {k, b})) q.pop_back();
    q.eb(k, b);
  }

  ll query(ll x) {
    if (q.empty()) return inf;
    int lo = 0, hi = q.size() - 1;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (f(q[mi], x) > f(q[mi + 1], x)) lo = mi + 1;
      else hi = mi;
    }
    return f(q[lo], x);
  }
};

int n;
ll s[maxn], pre[maxn], prei[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", s + i);
  FOR(i, 1, n) {
    pre[i] = pre[i - 1] + s[i];
    prei[i] = prei[i - 1] + i * s[i];
  }
  ll ans = 0;
  Hull hull;
  hull.add(0, 0);
  FOR(i, 1, n) {
    chkmax(ans, prei[i] - hull.query(-pre[i]));
    hull.add(-i, prei[i] - i * pre[i]);
  }
  printf("%lld", ans);
}
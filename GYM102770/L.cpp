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

const int maxa = 1123456;

int vis[maxa];

struct Int {
  vector<int> v;
  ll id;

  Int() = default;

  Int(int x, ll id) : id(id) {
    v.clear();
    while (x > 1) {
      v.eb(vis[x]);
      x /= vis[x];
    }
  }

  bool operator<(const Int &rhs) const {
    int n = min(v.size(), rhs.v.size());
    REP(i, n) if (v[i] != rhs.v[i]) return v[i] > rhs.v[i];
    return v.size() == rhs.v.size() ? id < rhs.id : v.size() < rhs.v.size();
  }

  bool operator==(const Int &rhs) const {
    return v == rhs.v;
  }

  Int operator*(const Int &rhs) const {
    Int ret;
    ret.v.resize(v.size() + rhs.v.size());
    REP(i, v.size()) ret.v[i] = v[i];
    REP(i, rhs.v.size()) ret.v[v.size() + i] = rhs.v[i];
    sort(all(ret.v));
    ret.id = id * ll(1e5 + 1) + rhs.id;
    return ret;
  }
};

int n, m;
ll k;

void solve() {
  cin >> n >> m >> k;
  vector<Int> a(n + 1), b(m + 1);
  FOR(i, 1, n) {
    int x; cin >> x;
    a[i] = Int(x, i);
  }
  FOR(i, 1, m) {
    int x; cin >> x;
    b[i] = Int(x, i);
  }
  sort(a.begin() + 1, a.end()); sort(b.begin() + 1, b.end());
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  vector<int> l(n + 1, 1), r(n + 1, m);
  while (true) {
    ll cnt = 0;
    FOR(i, 1, n) if (l[i] <= r[i]) cnt += r[i] - l[i] + 1;
    ll need = uniform_int_distribution<ll>(1, cnt)(rng);
    Int now;
    FOR(i, 1, n) if (l[i] <= r[i]) {
      if (need > r[i] - l[i] + 1) {
        need -= r[i] - l[i] + 1;
        continue;
      }
      now = a[i] * b[l[i] + need - 1];
      break;
    }
    ll acc = 0;
    for (int i = 1, j = m; i <= n; i++) {
      while (j && !(a[i] * b[j] < now)) j--;
      acc += j;
    }
    if (acc == k - 1) {
      ll ans = 1;
      for (auto x : now.v) ans *= x;
      cout << ans << '\n';
      return;
    }
    if (acc < k - 1) {
      for (int i = 1, j = m; i <= n; i++) {
        while (j && !(a[i] * b[j] < now)) j--;
        l[i] = j + 1;
      }
    } else {
      for (int i = 1, j = m; i <= n; i++) {
        while (j && now < a[i] * b[j]) j--;
        r[i] = j;
      }
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  FOR(i, 2, 1e6) if (!vis[i]) {
    vis[i] = i;
    for (int j = i + i; j <= 1e6; j += i) if (!vis[j]) vis[j] = i;
  }
  int T; cin >> T;
  while (T--) solve();
}
/*
 2
 3 3 6
 7 5 7
 3 2 7

 2 3 2
 7 7
 3 2 7
 */
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

int lowbit(int x) {
  return x & -x;
}

template<class T>
struct FenwickTree {
  int n;
  vector<T> fen;

  FenwickTree(int n) : n(n) {
    fen = vector<T>(n + 1);
  }

  void update(int x, T v) {
    while (x <= n) {
      fen[x] += v;
      x += lowbit(x);
    }
  }

  T sum(int x) {
    T ret = 0;
    while (x > 0) {
      ret += fen[x];
      x -= lowbit(x);
    }
    return ret;
  }

  T query(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};

const int maxn = 112345;

int n, q;
int a[maxn], l[maxn], r[maxn], k[maxn];
int L[maxn], R[maxn];
ll ans[maxn];
vector<int> query[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  cin >> q;
  FOR(i, 1, q) cin >> l[i] >> r[i] >> k[i];
  vector<pii> tmp;
  FOR(i, 1, n) tmp.eb(a[i], i);
  sort(all(tmp), greater<>());
  FOR(i, 1, q) {
    L[i] = 0;
    R[i] = n - 1;
  }
  while (true) {
    bool f = false;
    FenwickTree<int> fen(n);
    REP(i, n) query[i].clear();
    FOR(i, 1, q) if (L[i] < R[i]) {
      int mi = L[i] + R[i] >> 1;
      query[mi].eb(i);
      f = true;
    }
    if (!f) break;
    REP(i, n) {
      fen.update(tmp[i]._2, 1);
      for (auto id : query[i]) {
        if (fen.query(l[id], r[id]) >= k[id]) R[id] = i;
        else L[id] = i + 1;
      }
    }
  }
  REP(i, n + 1) query[i].clear();
  FOR(i, 1, q) query[L[i]].eb(i);
  FenwickTree<ll> fen(n);
  REP(i, n) {
    fen.update(tmp[i]._2, tmp[i]._1);
    for (auto id : query[i]) ans[id] = fen.query(l[id], r[id]);
  }
  FOR(i, 1, q) {
    ll d = r[i] - l[i] + 1;
    cout << ans[i] + d * (d + 1) * (2 * d + 1) / 6 << '\n';
  }
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
 1
 5
 1 2 3 4 5
 3
 1 3 2
 1 5 5
 3 3 1
 */
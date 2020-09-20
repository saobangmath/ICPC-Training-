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

const int maxn = 1123456;

struct Seg {
  int l, r;
  int mx;
} T[maxn << 2];

void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
}

void build(int o, int l, int r, int C) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].mx = C;
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi, C);
    build(o << 1 | 1, mi + 1, r, C);
    push_up(o);
  }
}

int query(int o, int x) {
  if (T[o].l == T[o].r) return T[o].l;
  if (T[o << 1].mx >= x) return query(o << 1, x);
  return query(o << 1 | 1, x);
}

void update(int o, int x, int v) {
  if (T[o].l == T[o].r) T[o].mx -= v;
  else {
    int mi = T[o].l + T[o].r >> 1;
    if (x <= mi) update(o << 1, x, v);
    else update(o << 1 | 1, x, v);
    push_up(o);
  }
}

void solve() {
  int n, C;
  cin >> n >> C;
  build(1, 1, n + 1, C);
  set<pii> s;
  FOR(i, 1, n) {
    int a;
    cin >> a;
    auto it = s.lower_bound(mp(a, 0));
    if (it == s.end()) {
      s.emplace(C - a, s.size() + 1);
    } else {
      auto [rem, id] = *it;
      s.erase(it);
      s.emplace(rem - a, id);
    }
    int id = query(1, a);
    update(1, id, a);
  }
  cout << query(1, C) - 1 << ' ' << s.size() << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}

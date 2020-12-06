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

const int maxn = 212345;

bool vis[maxn * 2];

struct Seg {
  int l, r;
  int v[4];

  Seg operator+(const Seg &rhs) const {
    Seg ret;
    ret.l = l, ret.r = rhs.r;
    fill(ret.v, ret.v + 4, 4e5);
    REP(i, 4) REP(j, 4) {
      if (i % 2 == 0 && j < 2 && vis[r] != vis[rhs.l]) continue;
      chkmin(ret.v[i / 2 * 2 + j % 2], v[i] + rhs.v[j]);
    }
    return ret;
  }

  int val() {
    return *min_element(v, v + 4);
  }
} T[maxn << 3];

void build(int o, int l, int r) {
  if (l == r) {
    T[o].l = T[o].r = l;
    T[o].v[1] = T[o].v[2] = 4e5;
    T[o].v[3] = 1;
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    T[o] = T[o << 1] + T[o << 1 | 1];
  }
}

void update(int o, int x) {
  if (T[o].l == T[o].r) return;
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) update(o << 1, x);
  else update(o << 1 | 1, x);
  T[o] = T[o << 1] + T[o << 1 | 1];
}

Seg query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o];
  int mi = T[o].l + T[o].r >> 1;
  if (r <= mi) return query(o << 1, l, r);
  if (l > mi) return query(o << 1 | 1, l, r);
  return query(o << 1, l, r) + query(o << 1 | 1, l, r);
}

int n, m;
int a[maxn];
vector<int> pos[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) {
    cin >> a[i];
    pos[a[i]].eb(i);
  }
  build(1, 1, 2 * n);
  FOR(i, 1, m) {
    if (pos[i].empty()) {
      cout << -1 << ' ';
      continue;
    }
    int ans = n - pos[i].size();
    for (auto u : pos[i]) {
      vis[u] = vis[u + n] = true;
      update(1, u); update(1, u + n);
    }
    pos[i].eb(pos[i].front() + n);
    FOR(j, 1, int(pos[i].size()) - 1) {
      int l = pos[i][j - 1] + 1, r = pos[i][j] - 1;
      if (l <= r) ans += query(1, l, r).val();
    }
    cout << ans << ' ';
  }
}

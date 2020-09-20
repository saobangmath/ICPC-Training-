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
  int v[21];
  bool flip;
} T[maxn << 2];

int n, m;
int a[maxn];

void push_down(int o) {
  if (!T[o].flip) return;
  reverse(T[o].v, T[o].v + 21);
  T[o].flip = false;
  if (T[o].l < T[o].r) {
    T[o << 1].flip ^= true;
    T[o << 1 | 1].flip ^= true;
  }
}

void push_up(int o) {
  push_down(o << 1); push_down(o << 1 | 1);
  REP(i, 21) T[o].v[i] = T[o << 1].v[i] ? T[o << 1].v[i] : T[o << 1 | 1].v[i];
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].flip = false;
  if (l == r) {
    a[l] = __builtin_popcount(a[l]);
    reset(T[o].v, 0);
    T[o].v[a[l]] = l;
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

void update(int o, int l, int r) {
  push_down(o);
  if (l <= T[o].l && T[o].r <= r) {
    T[o].flip ^= true;
    push_down(o);
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(o << 1, l, r);
  if (r > mi) update(o << 1 | 1, l, r);
  push_up(o);
}

pii query(int o, int l, int r, int x) {
  pii ret = {1e9, 0};
  push_down(o);
  if (l <= T[o].l && T[o].r <= r) {
    REP(i, 21) if (T[o].v[i]) {
      pii now = mp(abs(x - i), T[o].v[i]);
      chkmin(ret, now);
    }
    return ret;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) chkmin(ret, query(o << 1, l, r, x));
  if (r > mi) chkmin(ret, query(o << 1 | 1, l, r, x));
  return ret;
}

void solve() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  build(1, 1, n);
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      printf("%d\n", query(1, l, r, __builtin_popcount(x))._2);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      update(1, l, r);
    }
  }
}

int main() {
  int T; scanf("%d", &T);
  FOR(i, 1, T) {
    printf("Case %d:\n", i);
    solve();
  }
}

/*
1
 6 2
 2 5 3 15 6 8
 1 1 6 7
 1 1 3 1024

 2
 4 3
 1 5 8 2
 2 3 4
 1 1 4 0
 1 1 2 1

 5 1
 21 26 16 19 71
 1 2 4 71
 */
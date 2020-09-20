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

int n, m;
ll a[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%lld", a + i);
  while (m--) {
    int op; scanf("%d", &op);
    if (op) {
      int l, r;
      scanf("%d%d", &l, &r);
      int ans = 0;
      FOR(i, l, r) if (a[i] <= 0) ans++;
      printf("%d\n", ans);
    } else {
      int l, r, e;
      scanf("%d%d%d", &l, &r, &e);
      FOR(i, l, r) a[i] -= e;
    }
  }
}
/*
 3 6
 1 2 3
 0 2 3 1
 1 1 3
 0 2 2 1
 1 1 3
 0 1 3 1
 1 1 2
 */
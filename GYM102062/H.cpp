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

const int maxn = 6123;

char s[maxn];
int f[maxn][maxn];

void solve() {
  int n, q;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(len, 2, n) FOR(i, 1, n - len + 1) {
    int j = i + len - 1;
    f[i][j] = f[i + 1][j - 1] + abs(s[i] - s[j]);
  }
  scanf("%d", &q);
  while (q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    int lo = 0, hi = (r - l + 1) / 2;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (f[l + mi][r - mi] <= x) hi = mi;
      else lo = mi + 1;
    }
    printf("%d\n", r - l + 1 - 2 * lo);
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}
/*
 2
 thunder
 2
 3 3 10
 2 6 50
 thunder
 2
 3 3 10
 2 6 50
 */
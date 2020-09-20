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

const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int f[17][17][1 << 16];
int n, a[17], c[17];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", c + i);
  f[0][0][0] = 1;
  REP(i, n + 1) REP(j, i + 1) ROF(mask, (1 << i) - 1, 0) {
    if (i != n) add(f[i + 1][j][mask | (1 << i)], f[i][j][mask]);
    if (!mask) continue;
    int hi = i; while ((mask & (1 << hi - 1)) == 0) hi--;
    if (c[j + 1] == -1 || a[hi] == c[j + 1]) add(f[i][j + 1][mask ^ (1 << hi - 1)], f[i][j][mask]);
  }
  printf("%d", f[n][n][0]);
}

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

bool solve() {
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  if (x == 1 || y == m) return false;
  n--, m--, x--, y--;
  int a = x + y, b = x - y;
  if (a % (2 * n) == 0 || a % (2 * m) == 0) return false;
  if (b % (2 * n) == 0 && b <= 0) return false;
  return !(b % (2 * m) == 0 && b >= 0);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) puts(solve() ? "Farewell" : "BestWishes");
}
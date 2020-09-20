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

ll m;
vector<pair<ll, int>> fac;

void dfs(int pos, ll req, ll have, ll ans) {
  if (pos == fac.size()) {
    if (req == have) {
      printf("%lld", ans);
      exit(0);
    }
  }
  ll now = 1;
  int cnt = 0, pw = 0;
  auto [p, q] = fac[pos];
  while (cnt <= q) {
    if (1e16 / now < p || 1e16 / ans < p) break;
    cnt++, pw += cnt;
    now *= p, ans *= p;
    if (q % pw == 0) {
      if (req == -1 || req == ll(q) / pw * (cnt + 1)) dfs(pos + 1, ll(q) / pw * (cnt + 1), have * (cnt + 1), ans);
    }
  }
}

int main() {
  scanf("%lld", &m);
  if (m == 1) {
    puts("1");
    return 0;
  }

  for (ll i = 2; sqr(i) <= m; i++) if (m % i == 0) {
    int cnt = 0;
    while (m % i == 0) m /= i, cnt++;
    fac.eb(i, cnt);
  }
  if (m > 1) fac.eb(m, 1);
  dfs(0, -1, 1, 1);
  puts("-1");
}

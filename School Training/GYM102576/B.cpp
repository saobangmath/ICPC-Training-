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

int n, a[maxn], cnt[maxn];
ll f[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  fill(cnt + 1, cnt + int(1e6) + 1, 0);
  fill(f + 1, f + int(1e6) + 1, 0);
  FOR(i, 1, n) cnt[a[i]]++;
  FOR(i, 1, 1e6) f[i] = cnt[i];
  ll ans = 0;
  for (int j = 0; (1 << j) <= 1e6; j++) FOR(mask, 1, 1e6) if (mask & (1 << j)) f[mask] += f[mask ^ (1 << j)];
  FOR(i, 1, 1e6) ans += cnt[i] * f[i];
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}
/*
 2
 3
 1 5 6
 3
 1 1 1
 */
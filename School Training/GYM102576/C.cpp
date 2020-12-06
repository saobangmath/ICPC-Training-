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

int T;
int n, d;
ll c[maxn];

void solve() {
  scanf("%d%d", &n, &d);
  FOR(i, 1, n) scanf("%lld", c + i);
  sort(c + 1, c + n + 1);
  multiset<ll> s{0};
  ll ans = 0;
  FOR(i, 1, n) {
    ll cur = c[i] - ll(i - 1) * d;
    if (cur > 0) {
      s.emplace(cur);
      s.emplace(cur);
    }
    ans += *s.rbegin() - cur;
    if (s.size() > 1) s.erase(prev(s.end()));
  }
  printf("%lld\n", ans);
}

int main() {
  scanf("%d", &T);
  while (T--) solve();
}
/*
2
4 1
0 0 0 0
4 10
1 100 5 10
 */
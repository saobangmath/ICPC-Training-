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

ll p[10], q[10], C[10][10];

ll pw(ll x, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1) ret *= x;
    x = sqr(x);
    k >>= 1;
  }
  return ret;
}

void solve() {
  int d, n;
  scanf("%d%d", &d, &n);
  REP(i, d + 1) {
    q[i] = d + i + 1;
    p[i] = pw(n - 2, i) * pw(2, d - i) * C[d][i];
  }
  ll P = 0, Q = 1;
  REP(i, d + 1) Q = lcm(Q, q[i]);
  REP(i, d + 1) P += p[i] * (Q / q[i]);
  printf("%lld/%lld\n", P / gcd(P, Q), Q / gcd(P, Q));
}

int main() {
  int T; scanf("%d", &T);
  C[0][0] = 1;
  FOR(i, 1, 9) {
    C[i][0] = 1;
    FOR(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  FOR(cs, 1, T) {
    printf("Case %d: ", cs);
    solve();
  }
}
/*
3
 1 6
 2 10
 3 2
 */
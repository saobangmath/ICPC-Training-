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
const int MOD = 1e9 + 7;
const int iv2 = 5e8 + 4;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n;
char s[maxn];
int f[maxn];

void solve() {
  scanf("%d%s", &n, s + 1);
  int ans = 0;
  FOR(i, 1, n) ans = add(ans, mul(s[i], add(f[n], MOD - add(f[i - 1], f[n - i]))));
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  FOR(i, 1, 1e6) f[i] = add(f[i - 1], mul(mul(i, i + 1), iv2));
  FOR(cs, 1, T) {
    printf("Case %d: ", cs);
    solve();
  }
}
/*
2
 1
 a
 2
 ac
 */
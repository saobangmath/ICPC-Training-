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

const int maxn = 1123;
const int MOD = 1e9 + 7;

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

int n, m, k;
int cnt[maxn], fac[maxn], ifac[maxn];
vector<int> G[maxn];

int C(int x, int y) {
  if (y < 0 || y > x) return 0;
  return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, n) {
    int a; scanf("%d", &a);
    cnt[a]++;
  }
  fac[0] = ifac[0] = 1;
  FOR(i, 1, n) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = pow_mod(fac[i], MOD - 2);
  }
  FOR(i, 1, m) G[cnt[i]].eb(i);
  FOR(i, 1, n) {
    int tot = G[i].size() * i;
    if (tot <= k) {
      k -= tot;
      continue;
    }
    printf("%d", C(tot, k));
    return 0;
  }
  puts("1");
}
/*
 10 3 4
 1 1 1 2 2 3 3 3 3 3
 */
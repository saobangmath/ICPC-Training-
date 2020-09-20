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

int n, k;
int a[maxn];

bool check(ll x) {
  ll s = 0;
  FOR(i, 1, n) s += min(ll(a[i]), x);
  return s >= x * k;
}

void solve() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  ll lo = 0, hi = 1e12;
  while (lo < hi) {
    ll mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%lld\n", lo);
}

int main() {
  int T; scanf("%d", &T);
  FOR(i, 1, T) {
    printf("Case %d: ", i);
    solve();
  }
}

/*
3

 3 3
 1 2 3

 3 1
 1 2 3

 3 2
 3 2 4
 */
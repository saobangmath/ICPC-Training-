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

int d;
ll x;

void solve() {
  scanf("%d%lld", &d, &x);
  ll now = 0;
  ROF(i, d, 0) {
    if (x == now) {
      printf("YES %d\n", d - i);
      return;
    }
    if (x > now) now += 1LL << i;
    else now -= 1LL << i;
  }
  if (x == now) printf("YES %d\n", d + 1);
  else puts("NO");
}

int main() {
  int T; scanf("%d", &T);
  FOR(cs, 1, T) {
    printf("Case %d: ", cs);
    solve();
  }
}
/*
4
 2 6
 2 5
 3 8
 1 5
 */
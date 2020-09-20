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

const int maxn = 112345;

int n;
int cnt[maxn];

void solve() {
  scanf("%d", &n);
  reset(cnt, 0);
  FOR(i, 1, n) {
    int x; scanf("%d", &x);
    cnt[x]++;
  }
  bool same = false;
  FOR(i, 1, 1e5) if (cnt[i] > 1) {
    same = true;
    break;
  }
  if (!same) {
    printf("%lld\n", ll(n) * (n - 1) / 2);
    return;
  }
  ll ans = 1, pre = 0;
  FOR(i, 1, 1e5) {
    ans += pre * cnt[i];
    pre += cnt[i];
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}

/*
 1
 5
 2 3 2 3 3
 */
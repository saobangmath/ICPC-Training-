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
int cnt[maxn], s[maxn], pre[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, 2 * n - 2) {
    int x; cin >> x;
    cnt[x]++;
  }
  FOR(i, 1, n - 1) {
    s[i] = s[i - 1] + cnt[i] - 1;
    if (s[i] < 0) {
      FOR(j, 1, n - 1) cout << "-1 ";
      return 0;
    }
  }
  int l = 1, r = 0;
  FOR(i, 1, n - 1) if (cnt[i]) r++;
  FOR(i, 1, n - 1) if (!s[i]) {
    l++;
    cnt[i + 1]++;
  }
  cnt[1]--;
  memcpy(pre, cnt, sizeof(cnt));
  int lo = 1, hi = n - 1, acc = 0;
  ll ans = 0;
  FOR(i, 1, n - 1) {
    if (i < l || i > r) cout << "-1 ";
    else {
      if (i > l) {
        while (!cnt[lo] || !s[lo - 1]) lo++;
        if (pre[lo]) pre[lo]--;
        else {
          ans -= lo;
          acc--;
        }
        lo++;
      }
      while (acc < i) {
        while (!pre[hi]) hi--;
        pre[hi]--;
        ans += hi;
        acc++;
      }
      cout << ans << ' ';
    }
  }
}

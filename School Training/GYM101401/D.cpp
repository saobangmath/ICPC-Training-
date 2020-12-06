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

int n;
int w[maxn];
ll pre[maxn], ps[maxn], suf[maxn], ss[maxn];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", w + i);
  FOR(i, 1, n - 1) {
    pre[i] = pre[i - 1] + w[i - 1];
    ps[i] = ps[i - 1] + pre[i];
  }
  ROF(i, n - 1, 1) {
    suf[i] = suf[i + 1] + w[i];
    ss[i] = ss[i + 1] + suf[i];
  }
  ll ans = 0;
  int j = 1;
  REP(i, n) {
    while (true) {
      while (j <= i) j++;
      if (j < n && pre[j] - pre[i] > suf[j] + pre[i]) {
        ans += ss[j] + (n - j) * pre[i];
        ans += ps[j - 1] - ps[i] - (j - 1 - i) * pre[i];
        break;
      }
      if (j >= n) {
        ans += ps[n - 1] - ps[i] - (j - i - 1) * pre[i];
        break;
      }
      j++;
    }
  }
  printf("%lld", ans);
}

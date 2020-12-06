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

const int MOD = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = mul(ret, a);
    a = mul(a, a);
    p >>= 1;
  }
  return ret;
}

int g(int a, int p) {
  return add(pow_mod(a, p), MOD - pow_mod(a - 1, p));
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n + m + 1), peak(n + m + 1), cnt(n + m + 1);
  FOR(i, 1, n + m) cin >> a[i];
  FOR(i, 2, n + m) cnt[i] = min(min(n, m), min(i - 1, n + m - i + 1));
  FOR(i, 1, k) {
    int x, y, h;
    cin >> x >> y >> h;
    cnt[x + y]--;
    chkmax(peak[x + y - 1], h);
    chkmax(peak[x + y], h);
  }
  FOR(i, 2, n + m) if (cnt[i] < 0) {
    cout << "0\n";
    return;
  }
  FOR(i, 1, n + m) if (peak[i] > a[i]) {
    cout << "0\n";
    return;
  }
  vector<vector<int>> f(n + m + 1, vector<int>(2));
  if (peak[1] < a[1]) f[1][0] = 1;
  else f[1][1] = 1;
  FOR(i, 2, n + m) {
    int pre = a[i - 1], now = a[i];
    if (peak[i] == a[i]) {
      if (pre <= a[i]) f[i][1] = add(f[i][1], mul(f[i - 1][0], g(pre, cnt[i])));
      f[i][1] = add(f[i][1], mul(f[i - 1][1], pow_mod(min(pre, now), cnt[i])));
    } else {
      f[i][0] = add(f[i][0], mul(f[i - 1][1], pow_mod(min(pre, now - 1), cnt[i])));
      if (pre < now) f[i][0] = add(f[i][0], mul(f[i - 1][0], g(pre, cnt[i])));
      if (pre == now) f[i][1] = add(f[i][1], mul(f[i - 1][0], g(pre, cnt[i])));
      if (pre >= now) f[i][1] = add(f[i][1], mul(f[i - 1][1], g(now, cnt[i])));
    }
  }
  cout << f[n + m][1] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  FOR(cs, 1, T) {
    cout << "Case #" << cs << ": ";
    solve();
  }
}

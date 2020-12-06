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

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n + 1);
  REP(i, n) cin >> a[i]._1 >> a[i]._2;
  a[n] = {1e18, 0};
  sort(all(a));
  ll pre = 0, w = -1, ans = 1;
  vector<ll> f;
  REP(i, n + 1) {
    while (w != a[i]._1 && pre) {
      f.eb(1 - pre % 2);
      pre /= 2;
      w++;
    }
    if (w != a[i]._1 || !pre) {
      ll cur = 1, m = f.size();
      ROF(j, m - 1, 0) cur = (cur + cur - f[j]) % MOD;
      f.clear();
      w = a[i]._1;
      ans = ans * cur % MOD;
    }
    pre += a[i]._2;
  }
  cout << ans << '\n';
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

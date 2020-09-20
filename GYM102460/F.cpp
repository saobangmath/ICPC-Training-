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

int n;
ll k;
pair<ll, ll> a[maxn];
ll f[2][12][1 << 11], weight[1 << 11];
int cnt[1 << 11];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  ll d = 0;
  FOR(i, 1, n) {
    cin >> a[i]._2;
    d = gcd(d, a[i]._2);
  }
  if (d == 1) {
    cout << 0;
    return 0;
  }
  FOR(i, 1, n) cin >> a[i]._1;
  sort(a + 1, a + n + 1);
  vector<ll> facs;
  for (ll i = 2; sqr(i) <= d; i++) if (d % i == 0) {
    facs.eb(i);
    while (d % i == 0) d /= i;
  }
  if (d != 1) facs.eb(d);
  map<ll, int> passed;
  int m = facs.size();
  reset(f, 0x3f);
  f[0][0][0] = 0;
  FOR(i, 1, n) {
    ll prod = 1;
    REP(j, m) {
      weight[1 << j] = 1;
      while (a[i]._2 % facs[j] == 0) {
        weight[1 << j] *= facs[j];
        a[i]._2 /= facs[j];
      }
      prod *= weight[1 << j];
    }
    if (passed[prod] >= m) continue;
    passed[prod]++;
    weight[0] = 1;
    FOR(mask, 1, (1 << m) - 1) {
      int lowbit = mask & -mask;
      weight[mask] = weight[mask ^ lowbit] * weight[lowbit];
      if (weight[mask] > k || cnt[mask] >= m) continue;
      cnt[mask]++;
      int need = ((1 << m) - 1) ^ mask;
      for (int sub = need; ; sub = (sub - 1) & need) {
        REP(j, m) chkmin(f[1][j + 1][mask ^ sub], f[0][j][sub] + a[i]._1);
        if (!sub) break;
      }
    }
    REP(j, m + 1) REP(mask, 1 << m) chkmin(f[0][j][mask], f[1][j][mask]);
  }
  __int128 ans = 1e18;
  FOR(i, 1, m) chkmin(ans, __int128(i) * f[0][i][(1 << m) - 1]);
  if (ans > __int128(5e17)) ans = -1;
  cout << (ll)ans;
}
/*
 3 6
 30 30 30
 100 4 5

 1 1000000
 1
 100

 3 5
 7 7 7
 1 1 1
 */
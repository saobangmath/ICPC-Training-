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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<bitset<500>> f(1 << m), a(m);
  REP(i, m) {
    string s; cin >> s;
    REP(j, n) if (s[j] == '1') a[i][j] = true;
  }
  REP(mask, 1 << m) REP(i, m) if (mask & (1 << i)) f[mask] |= a[i];
  if (f[(1 << m) - 1].count() < n) {
    cout << "-1\n";
    return;
  }
  int ans = m;
  REP(mask, 1 << m) if (f[mask].count() == n) chkmin(ans, __builtin_popcount(mask));
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
/*
5
 3 3
 100
 011
 111
 5 6
 10000
 01001
 01110
 00111
 10110
 00101
 6 7
 000010
 011000
 100100
 001000
 000010
 010000
 110001
 7 6
 1001001
 1001000
 0001101
 0010110
 0110011
 0100001
 2 1
 01
 */
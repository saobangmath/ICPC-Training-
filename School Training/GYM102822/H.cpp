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
  ll d01, d02, d12;
  cin >> d01 >> d02 >> d12;
  if (d01 > d02) swap(d01, d02);
  if (d12 == 0) {
    if (d01 != d02) cout << "0\n";
    else if (d01 == 0) cout << "1\n";
    else cout << 4 * d01 << '\n';
    return;
  }
  if (d01 + d12 == d02) {
    cout << 4 * (d01 + 1) * (d12 + 1) - 4 << '\n';
    return;
  }
  if (d01 + d02 == d12) {
    cout << 4 * (d01 + 1) * (d02 + 1) - 4 << '\n';
    return;
  }
  if (d12 < d02 - d01 || d12 > d01 + d02 || (d12 - d02 + d01) % 2 == 1) {
    cout << 0 << '\n';
    return;
  }
  ll s = (d12 - d02 + d01) / 2;
  cout << 8 * (d01 + d12 - s) << '\n';
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

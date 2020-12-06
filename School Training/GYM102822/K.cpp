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
  int x;
  cin >> x;
  if (x == 6) {
    cout << "-1\n";
    return;
  }
  if (x % 2 == 1) {
    cout << "1\n";
    return;
  }
  if (x % 4 == 0) {
    cout << "2\n";
    return;
  }
  if ((x - 3) % 3 == 0) {
    int y = (x - 3) / 3;
    if (y % 2 == 1) {
      cout << "2\n";
      return;
    }
  }
  if ((x - 4) % 3 == 0) {
    int y = (x - 4) / 3;
    if (y % 3 != 0) {
      cout << "3\n";
      return;
    }
  }
  if ((x - 5) % 3 == 0) {
    int y = (x - 5) / 3;
    if (y % 3 != 0) {
      cout << "3\n";
      return;
    }
  }
  cout << "4\n";
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

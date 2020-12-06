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
  int n; cin >> n;
  vector<int> a(n);
  for_each(all(a), [](int &x){ cin >> x; });
  priority_queue<int> q;
  for (auto x : a) q.emplace(-x);
  int ans = 0;
  while (q.size() > 1) {
    auto u = -q.top(); q.pop();
    auto v = -q.top(); q.pop();
    ans += u + v;
    q.emplace(-(u + v));
  }
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
4
 6
 2 3 4 4 5 7
 5
 5 15 40 30 10
 10
 3 1 5 4 8 2 6 1 1 2
 9
 3 2 1 6 5 2 6 4 3

 */
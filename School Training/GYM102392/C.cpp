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

int a1(int x) {
  cout << "1 " << x << endl;
  int ret;
  cin >> ret;
  return ret;
}

int ask(int n) {
  cout << "2 " << n;
  FOR(i, 1, n) cout << ' ' << i;
  cout << endl;
  int mx = 0;
  FOR(i, 1, n * (n - 1) / 2) {
    int now; cin >> now;
    chkmax(mx, now);
  }
  return mx;
}

vector<int> ask(int i, vector<int> v) {
  map<int, int> cnt;
  if (v.size() != 1) {
    cout << "2 " << v.size();
    for (auto x : v) cout << ' ' << x;
    cout << endl;
    REP(j, int(v.size()) * int(v.size() - 1) / 2) {
      int x; cin >> x;
      cnt[x]--;
    }
  }
  v.eb(i);
  cout << "2 " << v.size();
  for (auto x : v) cout << ' ' << x;
  cout << endl;
  REP(j, int(v.size()) * int(v.size() - 1) / 2) {
    int x; cin >> x;
    cnt[x]++;
  }
  vector<int> ret;
  for (auto [x, y] : cnt) if (y) ret.eb(x);
  return ret;
}

int main() {
  int n; cin >> n;
  vector<int> ans(n + 1);
  if (n <= 30) {
    FOR(i, 1, n) ans[i] = a1(i);
    cout << '3';
    FOR(i, 1, n) cout << ' ' << ans[i];
    cout << endl;
    return 0;
  }
  int mx = ask(n);
  int lo = 1, hi = n;
  while (lo <= hi) {
    int mi = lo + hi >> 1;
    if (ask(mi) == mx) hi = mi - 1;
    else lo = mi + 1;
  }
  map<int, int> d;
  REP(i, 8) {
    vector<int> now;
    FOR(j, 1, n) if (j & (1 << i) && j != lo) now.eb(j);
    if (now.empty()) continue;
    auto cur = ask(lo, now);
    for (auto x : cur) d[x] += 1 << i;
  }
  for (auto [x, y] : d) ans[y] = x;
  int x = a1(lo), y = a1(lo == 1 ? 2 : 1);
  cout << '3';
  if (x > y) FOR(i, 1, n) cout << ' ' << x - ans[i];
  else FOR(i, 1, n) cout << ' ' << x + ans[i];
  cout << endl;
}

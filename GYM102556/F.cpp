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
bool have[maxn], conn[maxn];

string fmt(int x) {
  string ret = to_string(x);
  while (ret.length() < 4) ret = "0" + ret;
  return ret += "-01-01";
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    int y, m, d;
    scanf("%d-%d-%d", &y, &m, &d);
    if (m == 1 || (m == 2 && d <= 28)) conn[y] = true;
    have[y] = true;
  }
  int mn = 1e5 + 10, mx = 0;
  FOR(i, 1, int(1e5) + 10) if (have[i]) {
    chkmin(mn, i);
    chkmax(mx, i);
  }
  vector<string> ans;
  FOR(i, mn + 1, mx) if (!conn[i]) ans.eb(fmt(i));
  printf("%d\n", int(ans.size()));
  for (auto x : ans) printf("%s\n", x.c_str());
}

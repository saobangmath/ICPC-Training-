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

int m, n;
int l[maxn], r[maxn], x[maxn];

int main() {
  scanf("%d%d", &m, &n);
  vector<pii> events;
  FOR(i, 1, m) {
    scanf("%d%d%d", l + i, r + i, x + i);
    int in = l[i] - x[i], out = r[i] - x[i];
    events.eb(in, i); events.eb(out, -i);
  }
  sort(all(events));
  set<pii> guards;
  int j = 0;
  FOR(i, 1, n) {
    int t;
    scanf("%d", &t);
    while (j < events.size() && events[j]._1 <= t) {
      int id = events[j]._2;
      if (id > 0) guards.emplace(x[id], id);
      else guards.erase(mp(x[-id], -id));
      j++;
    }
    if (guards.empty()) puts("-1");
    else printf("%d\n", guards.begin()->_1);
  }
}
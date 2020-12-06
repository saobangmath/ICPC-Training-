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

int nex[maxn];
int r, g, b, n, m;
char s[maxn];

int Find(int x) {
  return nex[x] == x ? x : nex[x] = Find(nex[x]);
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  iota(nex + 1, nex + n + 2, 1);
  FOR(i, 1, n) {
    if (s[i] == 'R') r++;
    else if (s[i] == 'G') g++;
    else b++;
  }
  while (m--) {
    int x, y; scanf("%d%d", &x, &y);
    x = Find(x);
    while (x <= y) {
      if (s[x] == 'R') r--, b++;
      else if (s[x] == 'G') g--, r++;
      else b--, g++;
      nex[x] = x + 1;
      x = Find(x);
    }
    printf("%d %d %d\n", r, g, b);
  }
}

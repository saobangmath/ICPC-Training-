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

const int maxn = 112;

bool vis[maxn];
int n, a, b;
vector<int> G[maxn];

int main() {
  scanf("%d%d%d", &n, &a, &b);
  while (b--) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].eb(y);
  }
  queue<int> q;
  q.emplace(1); vis[1] = true;
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    if (!G[u].empty()) {
      int v = G[u][0];
      if (!vis[v]) {
        vis[v] = true;
        q.emplace(v);
      }
    } else {
      if (u > 1 && !vis[u - 1]) {
        vis[u - 1] = true;
        q.emplace(u - 1);
      }
      if (u < n && !vis[u + 1]) {
        vis[u + 1] = true;
        q.emplace(u + 1);
      }
    }
  }
  puts(vis[a] ? "YES" : "NO");
}

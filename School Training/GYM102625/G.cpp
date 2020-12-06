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

int n;
vector<tuple<int, int, int, int>> edges;
int par[maxn], f[maxn], vis[maxn];
ll ans[maxn];
vector<pii> G[maxn];
vector<int> anc, tot;

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void dfs(int u, int fa) {
  vis[u] = anc.back();
  for (auto [v, id] : G[u]) if (v != fa) {
    dfs(v, u);
    f[u] += f[v];
  }
}

void dfs2(int u, int fa) {
  for (auto [v, id] : G[u]) if (v != fa) {
    dfs2(v, u);
    ans[id] = ll(tot.back() - f[v]) * f[v];
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n - 1) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edges.eb(w, i, u, v);
  }
  sort(all(edges));
  iota(par + 1, par + n + 1, 1);
  fill(f + 1, f + n + 1, 1);
  for (int i = 0; i < n - 1; ) {
    int j = i + 1;
    while (j < n - 1 && get<0>(edges[i]) == get<0>(edges[j])) j++;
    vector<int> cc;
    FOR(k, i, j - 1) {
      auto [w, id, u, v] = edges[k];
      u = Find(u), v = Find(v);
      G[u].eb(v, id); G[v].eb(u, id);
      cc.eb(u); cc.eb(v);
    }
    sort(all(cc)); uni(cc);
    for (auto u : cc) if (!vis[u]) {
      anc.eb(u);
      dfs(u, 0);
      tot.eb(f[u]);
      dfs2(u, 0);
    }
    for (auto u : cc) par[u] = vis[u];
    for (auto u : cc) G[u].clear();
    for (auto u : cc) vis[u] = 0;
    anc.clear(); tot.clear();
    i = j;
  }
  vector<int> best{1};
  FOR(i, 2, n - 1) {
    if (ans[i] > ans[best[0]]) best = {i};
    else if (ans[i] == ans[best[0]]) best.eb(i);
  }
  printf("%lld %d\n", ans[best[0]] * 2, int(best.size()));
  for (auto x : best) printf("%d ", x);
}

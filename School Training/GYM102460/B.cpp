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
vector<int> G[maxn];
bool mark[maxn], propagate[maxn];

bool dfs(int u, int par) {
  int need = 0;
  for (auto v : G[u]) if (v != par) need += dfs(v, u);
  if (need >= 2) {
    mark[u] = propagate[par] = true;
    return false;
  }
  if (propagate[u]) {
    if (!need) propagate[par] = true;
    return false;
  }
  if (!par) mark[u] = true;
  return true;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  cout << accumulate(mark + 1, mark + n + 1, 0);
}
/*
10
 1 2
 2 3
 2 4
 4 5
 4 6
 6 7
 6 8
 8 9
 8 10

 5
 1 2
 1 3
 1 4
 1 5

 2
 1 2
 */
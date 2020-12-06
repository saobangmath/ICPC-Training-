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

const int maxn = 512;

ll f[2][maxn][maxn];
int n, s1, s2;
int id[maxn], x[maxn], y[maxn], t[maxn], r[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> s1 >> s2;
  FOR(i, 1, n) cin >> x[i] >> t[i] >> y[i] >> r[i];
  reset(f, 0x3f);
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [](int i, int j){ return x[i] < x[j]; });
  f[0][s1][s2] = 0;
  REP(i, n) {
    int pre = i & 1, now = 1 - pre;
    reset(f[now], 0x3f);
    REP(j, s1 + 1) REP(k, s2 + 1) {
      chkmin(f[now][j][k], f[pre][j][k]);
      if (j) {
        int nj = j - x[id[i + 1]], nk = k;
        if (nj < 0) {
          nk += nj;
          nj = 0;
          chkmax(nk, 0);
        }
        chkmin(f[now][nj][nk], f[pre][j][k] + t[id[i + 1]]);
      }
      if (k) {
        int nj = j, nk = max(k - y[id[i + 1]], 0);
        chkmin(f[now][nj][nk], f[pre][j][k] + r[id[i + 1]]);
      }
    }
  }
  if (f[n & 1][0][0] > 1e18) f[n & 1][0][0] = -1;
  cout << f[n & 1][0][0];
}

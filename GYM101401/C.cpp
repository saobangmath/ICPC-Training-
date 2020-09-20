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
int pre[maxn], suf[maxn], f[maxn][3][3][4];
char s[maxn];

int dfs(int i, int j, int k, int p) {
  if (i == n + 1) return -1e9;
  int &ret = f[i][j][k][p];
  if (ret != -1) return ret;
  ret = dfs(i + 1, j, k, s[i]) + (s[i] == 0 && p == 1);
  chkmax(ret, suf[i + 1] - (s[i] == 0 && s[i + 1] == 2) + (k == 0 && s[i + 1] == 2) + (j == 0 && s[i] == 1) + (p == 1 && s[i] == 0));
  return ret;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  s[0] = ')';
  ROF(i, n - 1, 0) {
    suf[i] = suf[i + 1];
    if (s[i] == ':' && s[i + 1] == ')') suf[i]++;
  }
  FOR(i, 1, n) {
    pre[i] = pre[i - 1];
    if (s[i - 1] == ':' && s[i] == ')') pre[i]++;
  }
  map<char, int> mat;
  mat[':'] = 0, mat['('] = 1, mat[')'] = 2;
  REP(i, n + 1) s[i] = mat[s[i]];
  s[n + 1] = 10;
  reset(f, -1);
  int ans = suf[1];
  FOR(i, 1, n) chkmax(ans, pre[i - 1] + dfs(i, s[i - 1], s[i], 3) - (s[i - 1] == 0 && s[i] == 2));
  printf("%d", ans);
}

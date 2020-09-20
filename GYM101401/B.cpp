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

char s[maxn];
int f[maxn];
int n;

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(i, 1, n) {
    if (s[i] == ':' && s[i - 1] == '(') f[i]++;
    if (s[i] == ':' && s[i + 1] == ')') f[i]--;
    f[i + 1] = f[i];
    if (s[i + 1] == ')' && s[1] == ':') f[i]++;
  }
  int ans = *max_element(f + 1, f + n + 1);
  FOR(i, 2, n) if (s[i - 1] == ':' && s[i] == ')') ans++;
  printf("%d", ans);
}

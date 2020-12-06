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

const int maxn = 1123456;

int f[maxn];

void solve() {
  int n;
  scanf("%d", &n);
  printf("%d\n", f[n]);
  stack<int> s; s.emplace(n);
  while (n > 1) {
    if (f[n] == f[n - 1] + 1) n--;
    else if (n % 2 == 0 && f[n] == f[n / 2] + 1) n /= 2;
    else n /= 3;
    s.emplace(n);
  }
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  putchar('\n');
}

int main() {
  f[1] = 1;
  FOR(i, 2, 1e6) {
    f[i] = f[i - 1];
    if (i % 2 == 0) chkmin(f[i], f[i / 2]);
    if (i % 3 == 0) chkmin(f[i], f[i / 3]);
    f[i]++;
  }
  int T; scanf("%d", &T);
  while (T--) solve();
}
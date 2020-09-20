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
char s[maxn];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n == 3) {
    puts("0");
    return 0;
  }
  int r = 0, g = 0, b = 0;
  auto work = [&](int i, int sig = 1) {
    if (s[i] == 'R') r += sig;
    if (s[i] == 'G') g += sig;
    if (s[i] == 'B') b += sig;
  };
  FOR(i, 1, 3) work(i);
  if (r && g && b) {
    puts("1");
    return 0;
  }
  r = g = b = 0;
  ROF(i, n, n - 2) work(i);
  if (r && g && b) {
    puts("1");
    return 0;
  }
  r = 0, g = 0, b = 0;
  FOR(i, 1, 3) work(i);
  FOR(i, 4, n) {
    work(i - 3, -1);
    work(i);
    if (r && g && b) {
      puts("2");
      return 0;
    }
  }
  r = g = b = 0;
  work(1), work(2), work(n);
  if (r && g && b) {
    puts("2");
    return 0;
  }
  r = g = b = 0;
  work(1), work(n - 1), work(n);
  if (r && g && b) {
    puts("2");
    return 0;
  }
  r = g = b = 0;
  if (s[1] != s[2] || s[n] != s[n - 1]) {
    puts("3");
    return 0;
  }
  work(1), work(2), work(3);
  FOR(i, 4, n) {
    work(i - 2, -1);
    work(i);
    if (r && g && b) {
      puts("3");
      return 0;
    }
  }
  r = g = b = 0;
  work(n), work(1), work(2);
  FOR(i, 3, n) {
    work(i - 2, -1);
    work(i);
    if (r && g && b) {
      puts("3");
      return 0;
    }
  }
  puts("4");
}

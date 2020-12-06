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

int n, k;
int cnt[30];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    int a; scanf("%d", &a);
    REP(j, 30) if (a & (1 << j)) cnt[j]++;
  }
  int ans = 0;
  REP(j, 30) if (cnt[j] % k) ans += 1 << j;
  printf("%d", ans);
}
/*
 42 18
318752492 630995896 557490717
182588146 174325727 95851943
318752492 154469437 367325359
821370300 174325727 154469437
59827913 36526605 9356383
545129895
182588146 557490717 545129895
367325359 202714501 613423725
545129895 613423725 630995896
862808465 124864154 745008828
202714501 745008828 124864154
9356383
545129895 545129895 545129895
36526605 95851943 821370300
472683539
59827913 472683539 862808465
 */
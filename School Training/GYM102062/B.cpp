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

const double pi = acos(-1);

double m, d;

void solve() {
  scanf("%lf%lf", &m, &d);
  printf("%.4lf\n", pow(4 * pi, 1.0 / 3) * pow(3 * (m / d), 2.0 / 3));
}

int main() {
  int T; scanf("%d", &T);
  FOR(cs, 1, T) {
    printf("Case %d: ", cs);
    solve();
  }
}
/*
5
 1 2
 30 400
 11 112
 79 100000
 500 12
 */
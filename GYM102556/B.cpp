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

const int leap = 229;
const int year = 180758;
const int MOD = 104206969;

int main() {
  ll A, B;
  scanf("%lld%lld", &A, &B);
  ll n = 0;
  if (A > 0) n = (B / 4 - (A - 1) / 4) - (B / 100 - (A - 1) / 100) + (B / 400 - (A - 1) / 400);
  else n = B / 4 - B / 100 + B / 400 + 1;
  n %= MOD;
  if (n < 0) n += MOD;
  if (A == 0 && B == 0) printf("%d", year);
  else printf("%d", ((B - A + 1) % MOD * year + n * leap % MOD) % MOD);
}

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

namespace LinearBasis {
  int a[30], bits;

  bool seek(int t) {
    ROF(i, bits - 1, 0) if ((t ^ a[i]) < t) t ^= a[i];
    return t > 0;
  }

  void insert(int t) {
    ROF(i, bits - 1, 0) if ((t ^ a[i]) < t) t ^= a[i];
    ROF(i, bits - 1, 0) if ((t ^ a[i]) < a[i]) a[i] ^= t;
    a[bits++] = t;
    ROF(i, bits - 1, 1) {
      if (a[i] >= a[i - 1]) break;
      swap(a[i], a[i - 1]);
    }
  }

  int query(int x) {
    int ret = 0;
    REP(i, bits) if (x & (1 << i)) ret ^= a[i];
    return ret;
  }
}

int q;

int main() {
  scanf("%d", &q);
  while (q--) {
    int p, n;
    scanf("%d%d", &p, &n);
    if (p == 1) {
      if (LinearBasis::seek(n)) LinearBasis::insert(n);
    } else {
      printf("%d\n", LinearBasis::query(n - 1));
    }
  }
}

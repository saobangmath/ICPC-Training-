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

namespace Rho {
  ll f[105], fcnt;

  ll mul(ll a, ll b, ll n) {
    return (a * b - ll(a / (long double) n * b + 1e-3) * n + n) % n;
  }

  ll pow(ll a, ll b, ll n) {
    ll d = 1;
    a %= n;
    while (b) {
      if (b & 1)d = mul(d, a, n);
      a = mul(a, a, n);
      b >>= 1;
    }
    return d;
  }

  bool check(ll a, ll n) {
    ll m = n - 1, x, y;
    int i, j = 0;
    while (!(m & 1)) m >>= 1, j++;
    x = pow(a, m, n);
    for (i = 1; i <= j; x = y, i++) {
      y = pow(x, 2, n);
      if ((y == 1) && (x != 1) && (x != n - 1)) return true;
    }
    return y != 1;
  }

  bool miller_rabin(int tries, ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    while (tries--) if (check(rand() % (n - 1) + 1, n)) return false;
    return true;
  }

  ll rho(ll n, int c) {
    ll i = 1, k = 2, x = rand() % n, y = x, d;
    while (true) {
      i++, x = (mul(x, x, n) + c) % n, d = gcd(y - x, n);
      if (d > 1 && d < n) return d;
      if (y == x) return n;
      if (i == k) y = x, k <<= 1;
    }
  }

  void fac(ll n, int c) {
    if (miller_rabin(20, n)) {
      f[fcnt++] = n;
      return;
    }
    ll p = n;
    while (p == n) {
      p = rho(p, c);
      c--;
    }
    fac(p, c);
    fac(n / p, c);
  }
}

const ll MOD = 1000000001;

map<ll, vector<int>> cnt;

void solve() {
  vector<ll> q;
  ll n;
  scanf("%lld", &n);
  if (n <= 63211236) {
    for (ll i = 2; sqr(i) <= n; i++)
      while (n % i == 0) {
        q.eb(i);
        n /= i;
      }
    if (n > 1) q.eb(n);
  } else {
    Rho::fcnt = 0;
    Rho::fac(n, 1234);
    REP(i, Rho::fcnt) q.eb(Rho::f[i]);
  }
  sort(all(q));
  for (int i = 0; i < q.size();) {
    int j = i;
    while (j < q.size() && q[i] == q[j]) j++;
    cnt[q[i]].eb(j - i);
    i = j;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  ll ans = 1;
  for (auto[x, v] : cnt) {
    sort(all(v));
    int now;
    if (v.size() == 1) now = v[0];
    else now = v[int(v.size()) - 1] - v[int(v.size()) - 2];
    while (now--) ans = x % MOD * ans % MOD;
  }
  printf("%lld", ans);
}

/*
10
 1 2 3 4 5 6 7 8 9 10

 1
 2305843009213693951
 */
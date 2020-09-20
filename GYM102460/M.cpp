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

vector<ll> prime, fac, pw, have, rem;
ll facs[16123456];

ll fac_pw(ll n, ll p) {
  ll ret = 0;
  while (n) {
    ret += n / p;
    n /= p;
  }
  return ret;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
  ll g = a;
  x = 1, y = 0;
  if (b) g = exgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

ll pow_mod(ll a, ll k, ll MOD) {
  ll ret = 1;
  while (k) {
    if (k & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    k >>= 1;
  }
  return ret;
}

ll inv(ll a, ll MOD) {
  ll x, y;
  exgcd(a, MOD, x, y);
  return (x + MOD) % MOD;
}

ll dfs(ll n, ll p, ll MOD) {
  if (!n) return 1;
  return dfs(n / p, p, MOD) * facs[n % MOD] % MOD * pow_mod(facs[MOD], n / MOD, MOD) % MOD;
}

ll calc(ll n, ll m, ll p, ll MOD) {
  facs[0] = 1;
  FOR(i, 1, MOD) {
    facs[i] = facs[i - 1];
    if (i % p) facs[i] = facs[i] * i % MOD;
  }
  return dfs(n, p, MOD) * inv(dfs(m, p, MOD), MOD) % MOD * inv(dfs(n - m, p, MOD), MOD) % MOD;
}

ll CRT() {
  ll prod = 1;
  int n = rem.size();
  REP(i, n) prod *= fac[i];
  ll ret = 0;
  REP(i, n) {
    ll pp = prod / fac[i];
    ret = (ret + rem[i] * inv(pp, fac[i]) % prod * pp) % prod;
  }
  return ret < 0 ? ret + prod : ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  ll n, m, D;
  cin >> n >> m >> D;
  {
    ll d = D;
    for (ll i = 2; sqr(i) <= d; i++) if (d % i == 0) {
      prime.eb(i);
      fac.eb(1);
      pw.eb(0);
      while (d % i == 0) {
        d /= i;
        fac.back() *= i;
        pw.back()++;
      }
    }
    if (d > 1) {
      prime.eb(d);
      fac.eb(d);
      pw.eb(1);
    }
  }
  int sz = fac.size();
  have.resize(sz); rem.resize(sz);
  ll mi = 8e18;
  REP(i, sz) {
    have[i] = fac_pw(n, prime[i]) - fac_pw(m, prime[i]) - fac_pw(n - m, prime[i]);
    chkmin(mi, have[i] / pw[i]);
  }
  REP(i, sz) {
    have[i] -= mi * pw[i];
    rem[i] = calc(n, m, prime[i], fac[i]) * pow_mod(prime[i], have[i], fac[i]) % fac[i];
    rem[i] = rem[i] * pow_mod(inv(D / fac[i], fac[i]), mi, fac[i]) % fac[i];
  }
  cout << CRT();
}
/*
 9 2 3
 5 2 5
 6 3 6
 7654321 1234567 1050
 9 5 9
 */
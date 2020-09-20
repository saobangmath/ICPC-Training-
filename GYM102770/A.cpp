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

const int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int tab[3123456];

bool peak(int y) {
  if (y % 4) return false;
  if (y % 400 == 0) return true;
  return y % 100;
}

bool check(const string &s) {
  return s.find("202", 0) != string::npos;
}

int h(int y, int m, int d) {
  y -= 2000;
  m--;
  d--;
  return y * 12 * 31 + m * 31 + d;
}

void solve() {
  string a[3], b[3];
  REP(i, 3) cin >> a[i];
  REP(i, 3) cin >> b[i];
  string A = a[0] + a[1] + a[2], B = b[0] + b[1] + b[2];
  int y1 = stoi(a[0]), m1 = stoi(a[1]), d1 = stoi(a[2]);
  int y2 = stoi(b[0]), m2 = stoi(b[1]), d2 = stoi(b[2]);
  cout << tab[h(y2, m2, d2)] - tab[h(y1, m1, d1)] + check(A) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int y = 2000, m = 1, d = 1, pre = 0;
  while (y < 10000) {
    char s[10] = {};
    sprintf(s, "%d%2d%2d", y, m, d);
    if (s[4] == ' ') s[4] = '0';
    if (s[6] == ' ') s[6] = '0';
    string now = s;
    if (check(now)) pre++;
    tab[h(y, m, d)] = pre;
    d++;
    if (d == day[m] + 2 || (d == day[m] + 1 && (m != 2 || !peak(y)))) m++, d = 1;
    if (m == 13) y++, m = 1;
  }
  int T; cin >> T;
  while (T--) solve();
}

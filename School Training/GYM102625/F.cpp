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

vector<string> all[10];

int main() {
  int a, b, c, q;
  scanf("%d%d%d%d", &a, &b, &c, &q);
  vector<int> avails;
  if (a) all[1].eb(to_string(a));
  if (b) all[1].eb(to_string(b));
  if (c) all[1].eb(to_string(c));
  FOR(i, 2, 9) {
    for (const auto &x : all[i - 1]) {
      all[i].eb(x + to_string(a));
      all[i].eb(x + to_string(b));
      all[i].eb(x + to_string(c));
    }
    sort(all(all[i])); uni(all[i]);
  }

  FOR(i, 2, 9) for (const auto &x : all[i]) {
    auto check = [&]() -> bool {
      int tot = 0;
      for (auto y : x) tot += y - '0';
      if (tot % x.size() != 0) return false;
      int tar = tot / x.size();
      for (auto y : x) if (y == tar + '0') return true;
      return false;
    };
    if (check()) avails.eb(stoi(x, nullptr, 10));
  }
  sort(all(avails)); uni(avails);
  int best = 0, id = 1;
  FOR(i, 1, q) {
    int l, r; scanf("%d%d", &l, &r);
    int now = lower_bound(all(avails), r + 1) - lower_bound(all(avails), l);
    if (now > best) {
      best = now;
      id = i;
    }
  }
  printf("%d", id);
}

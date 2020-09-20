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

int cnt[26];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  string s;
  cin >> s;
  int n = s.length() / 2;
  REP(i, 2 * n) cnt[s[i] - 'a']++;
  if (*max_element(cnt, cnt + 26) <= n) {
    cout << "YES\n";
    REP(i, 26) while (cnt[i]--) cout << char(i + 'a');
    return 0;
  }
  auto a = max_element(cnt, cnt + 26);
  if (*a >= 2 * n - 1) {
    cout << "NO\n";
    return 0;
  }
  vector<int> candidates;
  REP(i, 26) if (cnt[i] && i != a - cnt) candidates.eb(i);
  if (*a == 2 * n - 2) {
    if (candidates.size() == 1) cout << "NO\n";
    else {
      cout << "YES\n";
      REP(i, n) cout << char(a - cnt + 'a');
      cout << char(candidates[0] + 'a');
      REP(i, n - 2) cout << char(a - cnt + 'a');
      cout << char(candidates[1] + 'a');
    }
    return 0;
  }
  cout << "YES\n";
  REP(i, n) cout << char(a - cnt + 'a');
  *a -= n;
  cout << char(candidates[0] + 'a');
  cnt[candidates[0]]--;
  while ((*a)--) cout << char(a - cnt + 'a');
  for (auto i : candidates) while (cnt[i]--) cout << char(i + 'a');
}

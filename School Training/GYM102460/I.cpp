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

int n;
map<int, int> diff;
vector<int> cur;
vector<vector<int>> ans;

void solve(int l, int r) {
  if (l > r) {
    ans.eb(cur);
    return;
  }
  if (diff.rbegin()->_2 > 2) return;
  vector<int> used;
  if (l != r && diff.rbegin()->_2 == 2) {
    cur[r] = diff.rbegin()->_1;
    cur[l] = cur[n - 1] - diff.rbegin()->_1;
    diff.erase(diff.rbegin()->_1);
    used.eb(cur[r]); used.eb(cur[r]);
    bool good = true;
    REP(i, l) {
      int d = cur[l] - cur[i];
      if (diff.count(d)) {
        if (!--diff[d]) diff.erase(d);
      } else {
        good = false;
        break;
      }
      used.eb(d);
      d = cur[r] - cur[i];
      if (i) {
        if (diff.count(d)) {
          if (!--diff[d]) diff.erase(d);
        } else {
          good = false;
          break;
        }
        used.eb(d);
      }
    }
    if (good) FOR(i, r + 1, n - 1) {
      int d = cur[i] - cur[l];
      if (i != n - 1) {
        if (diff.count(d)) {
          if (!--diff[d]) diff.erase(d);
        } else {
          good = false;
          break;
        }
        used.eb(d);
      }
      d = cur[i] - cur[r];
      if (diff.count(d)) {
        if (!--diff[d]) diff.erase(d);
      } else {
        good = false;
        break;
      }
      used.eb(d);
    }
    if (good) {
      int d = cur[r] - cur[l];
      if (diff.count(d)) {
        if (!--diff[d]) diff.erase(d);
        used.eb(d);
      } else good = false;
    }
    if (good) solve(l + 1, r - 1);
  } else {
    cur[l] = cur[n - 1] - diff.rbegin()->_1;
    used.eb(diff.rbegin()->_1);
    if (!--diff[diff.rbegin()->_1]) diff.erase(diff.rbegin()->_1);
    bool good = true;
    REP(i, l) {
      int d = cur[l] - cur[i];
      if (diff.count(d)) {
        if (!--diff[d]) diff.erase(d);
      } else {
        good = false;
        break;
      }
      used.eb(d);
    }
    if (good) FOR(i, r + 1, n - 2) {
      int d = cur[i] - cur[l];
      if (diff.count(d)) {
        if (!--diff[d]) diff.erase(d);
      } else {
        good = false;
        break;
      }
      used.eb(d);
    }
    if (good) solve(l + 1, r);
    for (auto x : used) diff[x]++;
    used.clear();
    cur[r] = diff.rbegin()->_1;
    used.eb(diff.rbegin()->_1);
    if (!--diff[diff.rbegin()->_1]) diff.erase(diff.rbegin()->_1);
    good = true;
    FOR(i, 1, l - 1) {
      int d = cur[r] - cur[i];
      if (diff.count(d)) {
        if (!--diff[d]) diff.erase(d);
      } else {
        good = false;
        break;
      }
      used.eb(d);
    }
    if (good) FOR(i, r + 1, n - 1) {
      int d = cur[i] - cur[r];
      if (diff.count(d)) {
        if (!--diff[d]) diff.erase(d);
      } else {
        good = false;
        break;
      }
      used.eb(d);
    }
    if (good) solve(l, r - 1);
  }
  for (auto x : used) diff[x]++;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n * (n - 1) / 2) {
    int x; cin >> x;
    diff[x]++;
  }
  if (diff.rbegin()->_2 > 1) {
    cout << 0;
    return 0;
  }
  cur = vector<int>(n, -1);
  cur[0] = 0, cur[n - 1] = diff.rbegin()->_1;
  diff.erase(diff.rbegin()->_1);
  solve(1, n - 2);
  cout << ans.size() << '\n';
  for (const auto &v : ans) {
    for (auto x : v) cout << x << ' ';
    cout << '\n';
  }
}
/*
 4
2 2 2 4 4 6

 5
 3 3 6 9 9 12 12 15 18 21

 4
 5 6 7 8 9 10
 */
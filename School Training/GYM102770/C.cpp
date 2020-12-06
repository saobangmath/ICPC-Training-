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

struct Trie {
  struct Node {
    vector<int> ch;
    int v;

    Node() {
      ch = vector<int>(26, -1);
      v = 0;
    }
  };

  vector<Node> trie;

  Trie() {
    trie = vector<Node>(1);
  }

  void insert(string s, int v) {
    int u = 0, n = s.length();
    REP(i, n) {
      int idx = s[i] - 'a';
      if (trie[u].ch[idx] == -1) {
        trie[u].ch[idx] = trie.size();
        trie.eb();
      }
      u = trie[u].ch[idx];
    }
    trie[u].v = v;
  }

  int query(string s) {
    int u = 0, n = s.length();
    REP(i, n) {
      int idx = s[i] - 'a';
      if (trie[u].ch[idx] == -1) return 0;
      u = trie[u].ch[idx];
    }
    return trie[u].v;
  }
};

const int maxn = 1123;

int n, m;
string s[maxn];

void solve() {
  cin >> n >> m;
  REP(i, n) cin >> s[i];
  Trie trie;
  while (m--) {
    string t;
    int v;
    cin >> t >> v;
    trie.insert(t, v);
  }
  ll ans = 0;
  REP(i, n) {
    string now;
    REP(j, n) {
      if (s[i][j] == '#') {
        if (!now.empty()) {
          int cur = trie.query(now);
          if (!cur) {
            cout << -1 << '\n';
            return;
          }
          ans += cur;
        }
        now.clear();
      } else now += s[i][j];
    }
    if (!now.empty()) {
      int cur = trie.query(now);
      if (!cur) {
        cout << -1 << '\n';
        return;
      }
      ans += cur;
    }
  }
  REP(j, n) {
    string now;
    REP(i, n) {
      if (s[i][j] == '#') {
        if (!now.empty()) {
          int cur = trie.query(now);
          if (!cur) {
            cout << -1 << '\n';
            return;
          }
          ans += cur;
        }
        now.clear();
      } else now += s[i][j];
    }
    if (!now.empty()) {
      int cur = trie.query(now);
      if (!cur) {
        cout << -1 << '\n';
        return;
      }
      ans += cur;
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}

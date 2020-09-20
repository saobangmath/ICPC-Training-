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

int n, s, m;
int cnt[5];

int main() {
  scanf("%d%d%d", &n, &s, &m);
  FOR(i, 1, m) {
    int a; scanf("%d", &a);
    cnt[a]++;
  }
  int ans = 0;
  FOR(i, 1, n) {
    int need = s;
    while (need > 4 && cnt[3]) {
      need -= 3;
      cnt[3]--;
    }
    if (need == 4 && cnt[2] >= 2) {
      need = 0;
      cnt[2] -= 2;
    }
    if (need == 4 && cnt[1] && cnt[3]) {
      need = 0;
      cnt[1]--;
      cnt[3]--;
    }
    if (need == 3 && cnt[3]) {
      need = 0;
      cnt[3]--;
    }
    while (need > 1 && cnt[2]) {
      need -= 2;
      cnt[2]--;
    }
    while (need && cnt[1]) {
      need--;
      cnt[1]--;
    }
    while (need > 0 && cnt[2]) {
      need -= 2;
      cnt[2]--;
    }
    while (need > 0 && cnt[3]) {
      need -= 3;
      cnt[3]--;
    }
    if (need <= 0) ans++;
  }
  printf("%d", ans);
}
/*
 10 3 5
 3 3 1 2 2

 10 7 6
 3 2 2 2 2 3
 */
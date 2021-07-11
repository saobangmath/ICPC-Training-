#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

#define rep(i, n) \
for(int i = 0; i <n; i++)
#define rRep(i, n) \
for(int i = n-1; i>=0; i--)
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define bug(x) cerr << x << "\n";

//#define INF 2000000000

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
/**
 * @author anhtaitran
 *
 */

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--){
        int n, m; cin >> n >> m;
        vector<vector<int>> Cnt(m, vector<int>(26));
        for (int i = 0; i < n; i++){
            string s; cin >> s;
            for (int j=0;j<m;j+=1) Cnt[j][s[j]-'a']++;
        }
        for (int i=0;i<n-1;i++){
            string s; cin >> s;
            for (int j=0;j<m;j++) Cnt[j][s[j]-'a']--;
        }
        for (int i=0;i<m;i++){
            for (int c=0;c<26;c++){
                if (Cnt[i][c]>0) cout << char(c+'a');
            }
        }
        cout << "\n";
        cout.flush();
    }
    return 0;
}

// BE CONSISTENT (THINKING VERY CLEAR BEFORE CODING)
// NOT STUCK ON ONE APPROACHES AND STAY ORGANIZED
// DO SOMETHING INSTEAD OF NOTHING
// SEEING A PROBLEM IN A GENERAL MANNER (OPEN MIND)


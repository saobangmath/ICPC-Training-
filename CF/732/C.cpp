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

/**
 * Observation: first turns right -> at the end turn right -> each number move even times.
 * -> for a specific number, no of odds before and after are similar;
 * We will proof that this is also a sufficient condition for constructing the satisfying resulted array.
 * for n = 2 -> ez (base case);
 * for n = k -> choosing the first minimum number with odd position let say at a[i] (i%2==1) -> swaps each (a_j, a_j+1) with j = [i-1, 0, -1]
 * after this steps, a[i] is at the right position and the turn is still right -> ok!
 * -> after that, make pair each number from [2,j] (cos they have exactly even elements) and do the swap -> the turns and the parity of initial position is preserved.
 * -> Applying the induction to the array [2, n] -> this condition also sufficient
 */
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        vector<int>a(n) , b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i]; b[i] = a[i];
        }
        sort(b.begin(), b.end());
        multiset<pair<int,int>> sa, sb;
        for (int i = 0; i < n;i++){
            sa.insert(make_pair(a[i], i%2));
        }
        for (int i = 0; i < n;i++){
            sb.insert(make_pair(b[i], i%2));
        }
        bool ok = true;
        while (sa.size()){
            if (*sa.begin() == *sb.begin()){
                sa.erase(sa.begin());
                sb.erase(sb.begin());
                continue;
            }
            ok = false; break;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

// BE CONSISTENT (THINKING VERY CLEAR BEFORE CODING)
// NOT STUCK ON ONE APPROACHES AND STAY ORGANIZED
// DO SOMETHING INSTEAD OF NOTHING
// SEEING A PROBLEM IN A GENERAL MANNER (OPEN MIND)


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
        int n; cin>>n;
        vector<int>a(n), b(n);
        int total = 0;
        vector<int> op1, op2;
        for (int i = 0; i <n;i++){
            cin >> a[i];
            total -= a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
            total+=b[i];
            if (a[i]>b[i]){
                op1.pb(i);
            }
            else if (a[i]<b[i]){
                op2.pb(i);
            }
        }
        if (total!=0){
            cout << -1 << "\n"; continue;
        }
        vector<pair<int, int>> res;
        while (op1.size()){
            int last = op1.back();
            for (int i = 0; i < a[last] - b[last]; i++){
                b[op2.back()]--;
                res.pb(make_pair(op2.back(),last));
                if (b[op2.back()] == a[op2.back()]){
                    op2.pop_back();
                }
            }
            op1.pop_back();
        }
        cout << res.size() << "\n";
        for (auto p : res){
            cout << p.second+1 << " " << p.first+1 << "\n";
        }
    }
    return 0;
}

// BE CONSISTENT (THINKING VERY CLEAR BEFORE CODING)
// NOT STUCK ON ONE APPROACHES AND STAY ORGANIZED
// DO SOMETHING INSTEAD OF NOTHING
// SEEING A PROBLEM IN A GENERAL MANNER (OPEN MIND)


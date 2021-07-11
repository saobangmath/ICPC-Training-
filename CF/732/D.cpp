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

const int MOD = 998244353;
const int N = 1e5+1;
vector<int> fact(N), ifact(N);

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int add(int a, int b){
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int pow(int a, int b){
    if (b==0) return 1;
    int au = pow(a, b >> 1);
    au = mul(au, au);
    if (b&1)au = mul(au, a);
    return au;
}

int Ckn(int k, int n){
    return mul(fact[n], mul(ifact[k], ifact[n-k]));
}

int chiakeo(int zeros, int ones){
    assert(ones%2==0);
    return Ckn(zeros, zeros + ones/2);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    fact[0] = 1; ifact[0] = 1;
    for (int i = 1; i < N; i++){
        fact[i] = mul(fact[i-1], i);
        ifact[i] = pow(fact[i], MOD-2);
    }
    while (T--){
        int n; cin>>n;string s; cin>> s;
        int res=1, cnt0=0, cnt1=0;
        vector<pair<int,int>> p;
        for (int i = 0; i < n;i++){
            if (s[i] == '0'){
                if (cnt1!=0){
                    p.pb(make_pair(cnt1, 1));
                }
                cnt1=0; cnt0++;
            }
            else{
                if (cnt0!=0){
                    p.pb(make_pair(cnt0, 0));
                }
                cnt0=0; cnt1++;
            }
        }
        if (cnt1!=0){
            p.pb(make_pair(cnt1, 1));
        }
        if (cnt0!=0){
            p.pb(make_pair(cnt0, 0));
        }
        int ones = 0;
        int zeros = 0;
        for (pair<int, int> x : p){
            if (x.second == 0){
                zeros+=x.first;
            }
            else{
                ones+=x.first;
                if (ones%2==1){
                    res  = mul(res, chiakeo(zeros, ones-1));
                    ones--; zeros = 0;
                }
                else{
                    res = mul(res, chiakeo)
                }
            }
        }
        assert(ones%2==0);
        res = mul(res, chiakeo(zeros, ones));
        cout<<add(res,1)<<"\n";
    }
    return 0;
}

// BE CONSISTENT (THINKING VERY CLEAR BEFORE CODING)
// NOT STUCK ON ONE APPROACHES AND STAY ORGANIZED
// DO SOMETHING INSTEAD OF NOTHING
// SEEING A PROBLEM IN A GENERAL MANNER (OPEN MIND)


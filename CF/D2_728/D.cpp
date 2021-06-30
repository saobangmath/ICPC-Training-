#include<bits/stdc++.h>
#define pb push_back

using namespace std;

/**
 * @author GennadyTran
 */

 /**
  * Observation: for each (i, j) (i < j) find the probability that i appears after j;
  */

const int mod = 1e9 + 7;
const int N = 200;

template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;

    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:

    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v -= MOD-o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};


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

vector<vector<int>> g(N+1, vector<int>());
vector<vector<int>> lca(N + 1, vector<int>(8));
vector<int> depth(N + 1);

struct LCA{
    void reset(){
        for (int i = 1; i <= N; i++){
            depth[i] = 0;
            for (int lift = 0; lift < 8; lift++){
                lca[i][lift] = 0;
            }
        }
    }
    LCA(int r){
        reset();
        auto dfs = y_combinator([&](auto self, int root, int par) -> void{
            lca[root][0] = par;
            for (int lift = 1; lift <= 7; lift++){
                int au = lca[root][lift-1];
                lca[root][lift] = lca[au][lift-1];
            }
            for (int next : g[root]){
                if (next!=par){
                    depth[next] = depth[root] + 1;
                    self(next, root);
                }
            }
        });
        dfs(r, 0);
    }
    int query(int u, int v){
        if (depth[u] > depth[v]){
            swap(u, v);
        }
        for (int lift = 7; lift >= 0; lift--){
            if ((1 << lift) & (depth[v]-depth[u])){
                v = lca[v][lift];
            }
        }
        if (u == v){
            return u;
        }
        assert(depth[u] == depth[v]);
        for (int lift = 7; lift >= 0; lift--){
            if (lca[u][lift] != lca[v][lift]){
                u = lca[u][lift];
                v = lca[v][lift];
            }
        }
        assert(lca[u][0] == lca[v][0]);
        return lca[u][0];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using Mint = modnum<mod>;
    int n; cin >> n;
    vector<vector<int>>dist(n + 1, vector<int>(n + 1));
    vector<vector<Mint>> dp(n, vector<Mint>(n));
    Mint ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dist[i][j] = (i == j ? 0 : n);
        }
    }
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        dist[x][y] = dist[y][x] = 1;
        g[x].pb(y);
        g[y].pb(x);
    }
    // floyd;
    for (int k = 1; k <= n; k++){
        for (int j = 1; j <= n; j++){
            for (int i = 1; i <= n; i++){
                dist[i][j] = min(dist[i][j], dist[i][k] +  dist[k][j]);
            }
        }
    }
    // probability
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == 0){
                dp[i][j] = 1;
            }
            else if (j == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j - 1]) / 2;
            }
        }
    }
    // re-root;
    for (int root = 1; root <= n; root++){
        LCA *lca = new LCA(root);
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                int ancestor = lca->query(i, j);
                int u = dist[i][ancestor];
                int v = dist[j][ancestor];
                //cout << root << " " << i << " " << j << " " << ancestor << "\n";
                ans += dp[v][u];
            }
        }
    }
    cout << ans / n;
    return 0;
}

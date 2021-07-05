#include<bits/stdc++.h>
#define pb push_back

using namespace std;

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

const int mod = 998244353;
using Mint = modnum<mod>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    struct Op{
        char op;
        int num;
    };
    vector<Op> ops;
    for (int i = 0; i < n; i++){
        string op; cin >> op;
        int num = -1;
        if (op == "+"){
            cin >> num;
        }
        ops.pb({.op = op[0], .num = num});
    }
    vector<vector<Mint>> dp(n + 1, vector<Mint>(n + 2));
    dp[0][0] = 1;
    Mint ans = 0;
    for (int i = 1; i <= n; i++){
        if (ops[i-1].op == '+'){
            for (int u = 1; u <= n; u++){
                for (int v = 0; v <= n; v++){
                    if (u!=i) dp[u][v] = dp[u-1][v];
                    if (u < i){
                        if (ops[u-1].op == '-'){
                            dp[u][v]+=dp[u-1][v+1];
                            if (v==0) dp[u][v]+=dp[u-1][v];
                        }
                        if (ops[u-1].op == '+'){
                            if (ops[u-1].num<=ops[i-1].num){
                                if (v>0)dp[u][v]+=dp[u-1][v-1];
                            }
                            else dp[u][v]+=dp[u-1][v];
                        }
                    }
                    else if (u == i){
                        dp[u][v]=dp[u-1][v];
                    }
                    else{
                        if (ops[u-1].op == '-'){
                            dp[u][v]+=dp[u-1][v+1];
                        }
                        if (ops[u-1].op == '+'){
                            if (ops[u-1].num<ops[i-1].num){
                                if (v>0)dp[u][v]+=dp[u-1][v-1];
                            }
                            else dp[u][v]+=dp[u-1][v];
                        }
                    }
                }
            }
            Mint contrib = 0;
            for (int u=0;u<=n;u++){
                contrib+=dp[n][u];
                //cout << "i = " << i << " dp[" << n << "][" << u << "] = " << dp[n][u] << "\n";
            }
            //cout<<ops[i-1].num << " " << contrib << "\n";
            ans+=contrib*ops[i-1].num;
        }
    }
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void solveC(){
    int T; cin >> T;
    const int mod = 1e9+7;
    auto add = [&](int &a, long long b){
        b%mod;
        a+=b; if (a>=mod) a -= mod;
    };
    while (T--){
        long long n; cin >> n;
        int ans = 0;
        int cur = 2;
        long long lcm = 2;
        long long all = n;
        while (all > 0){
            add(ans, 1LL * cur * ((all-n/lcm)%mod)%mod);
            all = n / lcm;
            cur++;
            lcm = lcm / __gcd(lcm, 1LL*cur) * cur;
        }
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solveC();
    return 0;
}

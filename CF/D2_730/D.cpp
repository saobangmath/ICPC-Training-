#include<bits/stdc++.h>
#define pb push_back
using namespace std;

/**
 * pw_new = guess (xor -) pw_old;
 * at each query -> query with the assumption of the first password = i;
 * for even time i -> the form is: i (xor - ) initial_pass;
 * for odd time i -> the form is initial_pass (xor - )  i
 */
void solveD(){
    int T; cin >> T;
    while (T--){
        int n, k; cin >> n >> k;
        auto query = [&](int num) -> bool{
            cout << num << std::endl; cout.flush();
            int r; cin >> r;
            return r==1;
        };
        auto convert_base = [&](int u) -> vector<int>{
            vector<int> x;
            while (u>0){
                x.pb(u%k); u /= k;
            }
            return x;
        };
        auto do_minus_xor = [&](int u, int v) -> int{
            vector<int> toBaseU = convert_base(u);
            vector<int> toBaseV = convert_base(v);
            int lu = toBaseU.size(), lv = toBaseV.size();
            for (int i = 0; i < lv - lu; i++){
                toBaseU.pb(0);
            }
            for (int i = 0; i < lu - lv; i++){
                toBaseV.pb(0);
            }
            reverse(toBaseU.begin(), toBaseU.end());
            reverse(toBaseV.begin(), toBaseV.end());
            assert(toBaseU.size() == toBaseV.size());
            int r = 0;
            for (int i = 0; i < max(lu, lv); i++){
                r = r * k + ((toBaseU[i]-toBaseV[i]+k)%k);
            }
            return r;
        };
        for (int i = 0; i < n; i++){
            int q = 0;
            if (i == 0){
                q=0;
            }
            else if (i%2==0){
                q=do_minus_xor(i, i-1);
            }
            else{
                q=do_minus_xor(i-1, i);
            }
            if (query(q)) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solveD();
    return 0;
}

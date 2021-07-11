#include<bits/stdc++.h>

using namespace std;

/**
 * @author GennadyTran
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int>d(n);
        for (int i = 0; i< n; i++) cin >> d[i];
        sort(d.begin(), d.end());
        int64_t ans = 0;
        for (int i = 0; i < n-1; i++){
            ans = ans + 1LL * (d[i+1]-d[i]) * (1LL * (i+1) * (n-1-i) - 1);
        }
        cout << -ans << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

/**
 * @author GennadyTran
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    // 3 <= a[i] + a[j] = i + j <= 2 * n - 1
    while (t--){
        int n; cin >> n;
        map<int,int> pos_map;
        for (int i = 1; i <= n; i++){
            int num; cin >> num;
            pos_map[num] = i;
        }
        int ans = 0;
        for (int s = 3; s < 2 * n; s++){
            for (int x = 1; x * x < s; x++){
                if (s%x==0 && pos_map[x] && pos_map[s/x] && pos_map[x] + pos_map[s/x] == s){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

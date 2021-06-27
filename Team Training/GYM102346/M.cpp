#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c, t; cin >> n >> c >> t;
    vector<int>A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int lo = 1, hi = 1e9;
    auto get = [](int x, int y) -> int{
        return x/y+(x%y!=0);
    };
    auto check = [&](int time) -> bool{
        int cnt=1,cur=0;
        for (int i = 0; i < n; i++){
            int au = get(A[i], t);
            if (au > time){
                return false;
            }
            cur+=A[i];
            if (get(cur, t)>time){
                cur = A[i]; cnt++;
            }
        }

        return cnt <= c;
    };
    while (lo < hi){
        int mid =(lo + hi) >> 1;
        if (check(mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    cout << lo;
    return 0;
}

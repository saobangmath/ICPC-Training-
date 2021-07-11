#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int s, f; cin >> s >> f;
    int cur = 0, ans = s, M = 0;
    for (int i = 1; i <= f-s; i++) cur+=A[i];
    for (int i = 0; i < n; i++){
        cout << cur << "\n";
        if (cur >= M){
            M = cur; ans = min(ans, (s-i+n)%n);
        }
        cur+=(A[(i+f-s+1)%n]-A[(i+1)%n]);
    }
    if (cur>=M){
        ans = (s-(n-1)+n)%n;
    }
    cout << ans;
    return 0;
}

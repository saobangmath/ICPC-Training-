#include<bits/stdc++.h>
#define pb push_back

using namespace std;
const int N = 5001;
int dp[N][N];
vector<int>a(N);
map<int,int> indexes;

int dfs(int now, int pre){
    if (dp[now][pre] > 0) return dp[now][pre];
    dp[now][pre] = 2;
    int dd = a[now] - a[pre];//assert(dd>0);
    if(a[pre] >= dd){
        auto it = indexes.find(a[pre]-dd);
        if (it!=indexes.end() && it->second != pre){
            dp[now][pre] = dfs(pre, it->second) + 1;
        }
    }
    return dp[now][pre];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.begin() + n);
    for (int i = 0; i < n; i++){
        indexes[a[i]] = i;
    }
    int ans = 2;
    for (int i = 0; i < n; i++){
        for (int j = i-1; j >= 0; j--){
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}

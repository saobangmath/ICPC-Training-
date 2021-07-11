#include<bits/stdc++.h>
#define pb push_back

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<vector<int>> e(n, vector<int>());
    vector<int> subTree(n), depth(n);
    vector<int> cost;
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].pb(v); e[v].pb(u);
    }
    function<void(int, int)> dfs = [&](int u, int par){
        subTree[u] = 1;
        for (int v : e[u]){
            if (v!=par){
                depth[v] = depth[u] + 1;
                dfs(v, u);
                subTree[u]+=subTree[v];
            }
        }
        cost.pb(depth[u] - (subTree[u]-1));
    };
    dfs(0,-1);
    sort(cost.begin(), cost.end());
    long long ans = 0;
    for (int i = n - 1; i >= n - k; i--){
        ans += cost[i];
    }
    cout << ans;
    return 0;
}

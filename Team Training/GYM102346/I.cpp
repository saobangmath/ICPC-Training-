#include<bits/stdc++.h>
#define pb push_back

using namespace std;
using int64 = long long;
const int N = 400;
const int INF = 1e9;

int dp[N][N];
vector<pair<int,int>> g[N];
vector<bool> vis(false);
vector<int> ans(1e5+1);

struct Query{
    int index;
    int start;
    int dest;
    int k;
    friend operator<(Query q1, Query q2){
        return q1.k<q2.k;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r; cin >> n >> r;
    vector<pair<int,int>> T(n);
    for (int i = 0; i < n; i++){
        dp[i][i] = 0;
        cin >> T[i].first;
        T[i].second = i;
    }
    sort(T.begin(), T.end());
    for (int i = 0; i < r; i++){
        int x, y, d; cin >> x >> y >> d;
        x--;y--;
        g[x].pb(make_pair(y,d));
        g[y].pb(make_pair(x,d));
    }
    int q; cin >> q;
    vector<Query> queriesLow, queriesHigh;
    for (int i = 0; i < q; i++){
        int a,b,k,t; cin >> a >> b >> k >> t;
        a--; b--;
        if (t==0){
            queriesLow.pb({i, a, b, k});
        }
        else{
            queriesHigh.pb({i, a, b, k});
        }
    }
    sort(queriesLow.begin(), queriesLow.end());
    sort(queriesHigh.begin(), queriesHigh.end());
    //for (Query q : queriesLow){
    //    cout << q.k << " ";
    //}
    //cout << "\n";
    //for (Query q : queriesHigh){
    //    cout << q.k << " ";
    //}
    //cout << "\n";
    // Solve Low;
    {
        int last = -1;
        for (int i = 0; i < (int)queriesLow.size(); i++){
            Query query = queriesLow[i];
            int index = query.index;
            int start = query.start;
            int dest = query.dest;
            int k = query.k;
            for (int u = max(0, last); u < k; u++){
                vis[u] = true;
                for (pair<int,int> edge : g[u]){
                    int v = edge.first;
                    int w = edge.second;
                    if (vis[v] || v == start || v == dest){
                        dp[u][v] = min(dp[u][v], w);
                        dp[v][u] = dp[u][v];
                        for (int v1 = 0; v1 < n; v1++){
                            for (int v2 = v1 + 1; v2 < n; v2++){
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][u] + dp[u][v2]);
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][v] + dp[v][v2]);
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][u] + dp[v][v2] + w);
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][v] + dp[u][v2] + w);
                                dp[v2][v1] = dp[v1][v2];
                            }
                        }
                    }
                }
            }
            last = k;
            ans[index] = (dp[start][dest]==INF?-1:dp[start][dest]);
        }
    }
    // Solve High;
    {
        for (int i = 0; i < n ;i++){
            vis[i] = false;
            for (int j = 0; j < n; j++){
                if (i == j){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[j][i] = INF;
                }
            }
        }
        int last = n;
        for (int i = 0; i < (int)queriesHigh.size(); i++){
            Query query = queriesHigh[i];
            int index = query.index;
            int start = query.start;
            int dest = query.dest;
            int k = query.k;
            for (int u = min(last,n-1); u >= n - k; u--){
                vis[u] = true;
                for (pair<int,int> edge : g[u]){
                    int v = edge.first;
                    int w = edge.second;
                    if (vis[v]){
                        dp[u][v] = min(dp[u][v], w);
                        dp[v][u] = dp[u][v];
                        for (int v1 = 0; v1 < n; v1++){
                            for (int v2 = v1 + 1; v2 < n; v2++){
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][u] + dp[u][v2]);
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][v] + dp[v][v2]);
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][u] + dp[v][v2] + w);
                                dp[v1][v2] = min(dp[v1][v2], dp[v1][v] + dp[u][v2] + w);
                                dp[v2][v1] = dp[v1][v2];
                            }
                        }
                    }
                }
            }
            last = n - k;
            ans[index] = (dp[start][dest]==INF?-1:dp[start][dest]);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << " ";
    return 0;
}

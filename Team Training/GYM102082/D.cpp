#include<bits/stdc++.h>
#define pb

using namespace std;
const int N = 4001;
const int INF = 1e9;

int next0[N+2][2], next1[N+2][2];
int dp[N+1][N+1];
int l1 = 0, l2 = 0;

int dfs(int i, int j){
    assert(i <= l1+1 && j<= l2+1);
    assert(min(i,j)>=0);
    if (dp[i][j]!=INF){
        return dp[i][j];
    }
    // set 0 as the next;
    {
        dp[i][j] = dfs(min(next0[i][0]+1, l1+1), min(next0[j][1]+1, l2+1)) + 1;
    }
    // set 1 as the next;
    {
        dp[i][j] = min(dp[i][j], dfs(min(l1+1, next1[i][0]+1), min(l2+1, next1[j][1]+1)) + 1);
    }
    return dp[i][j];
}

void trace(int i, int j){
    if (i == l1+1 && j == l2+1) return;
    int zero = dp[min(l1+1, next0[i][0]+1)][min(l2+1, next0[j][1]+1)];
    int one = dp[min(l1+1, next1[i][0]+1)][min(l2+1, next1[j][1]+1)];
    if (zero <= one){
        cout << 0;
        trace(min(l1+1, next0[i][0]+1), min(l2+1, next0[j][1]+1));
    }
    else{
        cout << 1;
        trace(min(l1+1, next1[i][0]+1), min(l2+1, next1[j][1]+1));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2; cin >> s1 >> s2;
    l1 = s1.size(), l2 = s2.size();
    for (int i = 0; i <= l1+1; i++){
        for (int j = 0; j <= l2+1; j++){
            dp[i][j] = INF;
            if (i>=l1 && j>=l2) dp[i][j]=1;
        }
    }
    dp[l1+1][l2+1] = 0;
    {
        next0[l1+1][0] = l1; next1[l1+1][0] = l1;
        next0[l1][0] = l1; next1[l1][0] = l1;
        for (int i = l1 - 1; i >= 0; i--){
            next0[i][0] = next0[i+1][0];
            next1[i][0] = next1[i+1][0];
            if (s1[i] == '0'){
                next0[i][0] = i;
            }
            else{
                next1[i][0] = i;
            }
        }
    }
    {
        next0[l2+1][1] = l2; next1[l2+1][1] = l2;
        next0[l2][1] = l2; next1[l2][1] = l2;
        for (int i = l2 - 1; i >= 0; i--){
            next0[i][1] = next0[i+1][1];
            next1[i][1] = next1[i+1][1];
            if (s2[i] == '0'){
                next0[i][1] = i;
            }
            else{
                next1[i][1] = i;
            }
        }
    }
    int result = dfs(0,0);
    //cout << dfs(l1,l2) << "\n";
    //cout << result << "\n";
    trace(0,0);
    return 0;
}

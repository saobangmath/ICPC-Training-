#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int>f(n+1);
    bool found = false;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++){
        int u = f[i];
        int v = f[u];
        if (v != i && f[v]==i){
            found =true;
            break;
        }
    }
    cout << (found ? "Yes" : "No");
    return 0;
}

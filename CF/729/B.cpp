#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void solveB(){
    // kind of nice number theory problem
    int T; cin >> T;
    while (T--){
        int n, a, b; cin >> n >>  a >> b;
        long long cur = 1;
        bool stop = false;
        if (a == 1){
            cout << ((n-1)%b==0 ? "Yes" : "No") << "\n"; continue;
        }
        while (cur <= n){
            if ((n-cur)%b==0){
                cout << "Yes\n"; stop = true; break;
            }
            cur*=a;
        }
        if (!stop)cout << "No\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solveB();
    return 0;
}

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void solveB(){
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        int64_t sum = 0;
        for (int i = 0; i < n; i++){
            int a; cin >> a; sum += a;
        }
        int b = sum%n;
        int a = n-b;
        cout<<1LL*a*b<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solveB();
    return 0;
}

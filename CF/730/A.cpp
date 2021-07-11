#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void solveA(){
    int  T; cin >> T;
    while (T--){
        int64_t a, b; cin >> a >> b;
        if (a == b){
            cout << 0 << " " << 0 << "\n";
        }
        else{
            if (a < b) swap(a, b);
            int64_t d = a-b;
            cout << d << " " << min(a%d, d-a%d)<< "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solveA();
    return 0;
}

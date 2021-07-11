#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void solveA(){
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        int odd = 0, even=  0;
        for (int i = 0; i < 2*n; i++){
            int num; cin >> num;
            if (num%2==0) even++;
            else odd++;
        }
        cout << (odd ==even ? "Yes" : "No") << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solveA();
    return 0;
}

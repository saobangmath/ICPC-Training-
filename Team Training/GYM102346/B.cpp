#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int idx = -1, M = -1;
    for (int i = 0; i < n; i++){
        int num; cin>> num;
        if (num > M){
            M = num; idx = i;
        }
        if (idx!=0){
            cout << "N"; return 0;
        }
    }
    cout << "S";
    return 0;
}

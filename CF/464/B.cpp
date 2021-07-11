#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    int k;
    cin >> n >> k;
    int id=0; long long M = 0, boxes = 0;
    for (int i = 1; i <= k; i++){
        long long x; cin >> x;
        long long hamsters = n / x * x;
        if (hamsters >= M){
            M = hamsters; id = i; boxes = n / x;
        }
    }
    cout << id << " " << boxes;
    return 0;
}

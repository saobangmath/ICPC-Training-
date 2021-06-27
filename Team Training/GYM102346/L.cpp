#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; cin >> n;
    long long cnt = 1;
    while (n > 0){
        if (n %2==1)cnt<<=1;
        n/=2;
    }
    cout << cnt;
    return 0;
}

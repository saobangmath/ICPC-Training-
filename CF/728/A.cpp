#include<bits/stdc++.h>

using namespace std;

/**
 * @author GennadyTran
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (n % 2 == 0){
            for (int i = 1; i < n; i+=2){
                cout << i + 1 << " " << i << " ";
            }
        }
        else{
            cout << "2 3 1 ";
            for (int i = 4; i < n; i+=2){
                cout << i + 1 << " " << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

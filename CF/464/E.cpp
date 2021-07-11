#include<bits/stdc++.h>

using namespace std;
using ld = long double;

struct DS{
    ld ans = 0;
    int n = 0;
    long long cur = 0;

    ld query(){
        return ans;
    }
    void add(int num){
        ans = max(ans, num - (ld)(num + cur) / (n + 1));
        cur+=num;
        n++;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    DS ds;
    for (int i =0;i < q;i++){
        int op;
        cin >> op;
        if (op==2){
            cout << setprecision(10) << ds.query() <<"\n";
        }
        else{
            int num; cin >> num;
            ds.add(num);
        }
    }
    return 0;
}

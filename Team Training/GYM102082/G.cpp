#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> incSet;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> decSet;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int>a;
    for (int i = 0; i < n; i++){
        int num; cin >> num; a.emplace_back(num);
    }
    vector<int>swaps(n);
    incSet inc;
    decSet dec;
    int ans=0;
    // initialize for dec;
    for (int i = n-1; i >= 0; i--){
        swaps[i] = (int)dec.size() - dec.order_of_key(a[i]);
        dec.insert(a[i]);
        ans+=swaps[i];
    }
    for (int i = 0; i < n; i++) cout << swaps[i] << " ";
    cout << "\n";
    int cur=ans;
    int Xlong=ans;
    for (int i = 0; i < n; i++){
        //cur -= swaps[i];
        //cout << swaps[i] << " " << (int)inc.size() - inc.order_of_key(a[i]) << "\n";
        ans = min(ans, Xlong+(int)inc.size() - (int)inc.order_of_key(a[i]) - swaps[i]);
        inc.insert(a[i]);
        ans = min(ans, cur);
    }
    cout <<ans;
    return 0;
}

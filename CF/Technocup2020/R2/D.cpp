#include<bits/stdc++.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    long long ans = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++){
        int num; cin >> num; m[num]++;
    }
    if (k == 2){
        vector<map<int,int>> HashTable(11);
        for (auto it = m.begin(); it!=m.end(); it++){
            ans+=it->second*(it->second-1)/2;
            int cur = it->first, primeCnt = 0, ex = 0, key = 0;
            for (int i = 2; i * i <= cur; i++){
                ex = 0;
                while (cur % i == 0){
                    cur /= i; ex++;
                }
                if ((ex>0) && (ex&1)){
                    primeCnt++; key += i;
                }
            }
            if (cur>1){
                primeCnt++; key+=cur;
            }
            HashTable[primeCnt][key]++;
            //cout << primeCnt << " " << key << "\n";
        }
        for (int i = 1; i <= 10; i++){
            for (auto it = HashTable[i].begin(); it!=HashTable[i].end(); it++){
                ans+=1LL*it->second * (it->second-1)/2;
            }
        }
        cout << ans;
        return 0;
    }
    bool die = false;
    for (int cur = 1; ; cur++){
        long long x = 1;
        for (int i = 0; i < k; i++){
            x = x * cur;
            if (x > 1e10){
                die = true;
            }
        }
        if (die){
            //cerr << cur << "\n";
            break;
        }
        for (auto it = m.begin(); it!=m.end(); it++){
            if (1LL * it->first * it->first > x){
                break;
            }
            if (x%it->first==0){
                int u = x/it->first;
                if (u!=it->first) ans+=1LL*m[it->first]*m[u];
                else ans+=1LL*m[it->first]*(m[it->first]-1)/2;
            }
        }
    }
    cout << ans;
    return 0;
}

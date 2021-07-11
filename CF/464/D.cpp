#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    vector<int> par(26);
    iota(par.begin(), par.end(), 0);
    vector<pair<int, int>> choosen;
    function<int(int)> get = [&](int u){
      if (u == par[u]) return u;
      return par[u] = get(par[u]);
    };
    function<bool(int, int)> merge = [&](int u, int v){
        //cout << u << " " << v << "\n";
        u = get(u); v = get(v);
        //cout << u << " " << v << "\n";
        if (u!=v){
            choosen.pb(make_pair(u, v));
            par[u] = v;
            return true;
        }
        return false;
    };
    for (int i = 0; i < n; i++){
        if (s1[i]!=s2[i]){
            merge(s1[i]-'a', s2[i]-'a');
        }
    }
    cout << choosen.size() << "\n";
    for (pair<int, int> p : choosen){
        cout << char('a' + p.first) << " " << char('a' + p.second) << "\n";
    }
    return 0;
}

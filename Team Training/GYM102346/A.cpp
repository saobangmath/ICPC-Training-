#include<bits/stdc++.h>

using namespace std;

struct Circle{
    int x, y, r;
    friend double getDist(Circle c1, Circle c2){
        int squareDist = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
        return sqrt(squareDist);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k; cin >> m >> n >> k;
    vector<Circle> sensors(k+4);
    vector<int> father(4 + k);
    iota(father.begin(), father.end(), 0);
    function<int(int)> get = [&](int u){
        if (father[u]==u)return u;
        return father[u] = get(father[u]);
    };
    function<void(int, int)> merge = [&](int u, int v){
        u = get(u); v = get(v);
        if (u!=v){
            father[u] = v;
        }
    };
    for (int i = 0; i < k; i++){
        int x,y,r; cin >> x >> y >> r;
        sensors[i].x = x;
        sensors[i].y = y;
        sensors[i].r = r;
    }
    for (int i = 4; i < k + 4; i++){
        int x = sensors[i-4].x, y = sensors[i-4].y, r = sensors[i-4].r;
        {
            if (x <= r) merge(1, i);
        }
        {
            if (y <= r) merge(0, i);
        }
        {
            if (m - x <= r) merge(3, i);
        }
        {
            if (n - y <= r) merge(2, i);
        }
    }
    for (int i = 4; i < k + 4; i++){
        for (int j = i + 1; j < k + 4; j++){
            double dist = getDist(sensors[i-4], sensors[j-4]);
            if (dist > sensors[i-4].r + sensors[j-4].r){
                continue;
            }
            merge(i, j);
        }
    }
    if (get(0) == get(1) || get(2) == get(3) || get(0) == get(2) || get(1) == get(3)){
        cout << "N";
    }
    else{
        cout << "S";
    }
    return 0;
}

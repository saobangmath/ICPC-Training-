#include<bits/stdc++.h>

using namespace std;

void SolveD(){
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        int prev = -1;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            if (prev == -1){
                cout << "0 ";
                prev = a;
            }
            else{
                int cur = 0;
                for (int bit = 29; bit >= 0;bit--){
                    cur <<= 1;
                    if ((!(a&(1<<bit))) && (prev&(1<<bit))){
                        cur++;
                    }
                }
                cout << cur << " ";
                prev = cur^a;
            }
        }
        cout << "\n";
    }
}

void solveE(){
    // can think but lazy to code lol; will code tmw;
}

struct SegmentTree{
    vector<int> segs;
    SegmentTree(vector<int>&a){
        int n = a.size();
        segs.resize(n << 2, 0);
        build(a, 0, 0, n - 1);
    }
    void build(vector<int>&a, int root, int l, int r){
        if (l == r){
            segs[root] = a[l]; return;
        }
        int m = (l + r) >> 1;
        build(a, root*2+1, l, m);
        build(a, root*2+2, m+1, r);
        segs[root] = __gcd(segs[root*2+1], segs[root*2+2]);
    }
    int query(int root, int l, int r, int lq, int rq){
        if (lq <= l && rq >= r){
            return segs[root];
        }
        if (lq > r || rq < l){
            return 0;
        }
        int m = (l + r) >> 1;
        int left = query(root * 2 + 1, l, m, lq, rq);
        int right = query(root * 2 + 2, m+1, r, lq, rq);
        return __gcd(left, right);
    }
};

void solveF(){
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        vector<int> a(n<<1);
        int g = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i]; a[i+n] = a[i];
            g = __gcd(g, a[i]);
        }
        int lo = 0;
        int hi = n-1;
        SegmentTree *tree = new SegmentTree(a);
        auto check = [&](int target) -> bool{
            for (int i = 0; i < n; i++){
                if (tree->query(0, 0, 2 * n - 1, i, i+target)!=g) return false;
            }
            return true;
        };
        while (lo < hi){
            int mid = (lo + hi) >> 1;
            if (check(mid)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
    }
}

/**
 * Kosaraju/Tarjan used to find the SSC -> the graph become the new_graph. Then dfs from the vertice contains the node to other vertice.
 */
void solveG(){
    int T; cin >> T;
    while (T--){

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solveF();
    return 0;
}

#include<map>
#include<set>
#include<list>
#include<stack>
#include<array>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<iterator>
#include<iostream>
#include<assert.h>
#include<algorithm>
#include<unordered_map>

using namespace std;
/**
* @author Tran Anh Tai
*/

typedef set<int> si;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef map<string, int> msi;

#define rep(i, n) \
for(int i = 0; i <n; i++)
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++)

#define INF 2000000000
int n;
int maxN=2e5;
vector<list<int>> e(maxN, list<int>());
vector<bool> vis(maxN);
vector<bool> ap(maxN); // is a articulation point?
vector<int> low(maxN);
vector<int> disc(maxN); // discovered time of node u;
vector<int> par(maxN); // parent of node u;
vector<array<int, 2>> bridges; // all bridges in the graph;
int Time=0;

void dfs(int src){
    int children=0;
    vis[src]=true;
    disc[src]=low[src] = ++Time;
    list<int>::iterator it;
    for (it=e[src].begin(); it!=e[src].end();it++){
        int dest=*it;
        if (!vis[dest]){
            children++;
            par[dest]=src;
            dfs(dest);
            low[src]=min(low[src], low[dest]);
            if (low[dest] > disc[src]){ // when src-dest is a bridge;
                bridges.push_back({src, dest});
            }
            if (par[src]==-1 && children>=2){ // when src is the root of dfs tree and src has at least 2 children;
                ap[src]=true;
            }
            if (par[src]!=-1 && low[dest]>=disc[src]){ // when src is not the root but it has one descendant which have np back-edge to src ancestor;
                ap[src]=true;
            }
        }
        else if (dest != par[src]){
            low[src]=min(low[src], disc[dest]);
        }
    }
}

void BridgesAndArticulationPointsFinder(){
    Time=0; // reset time;
    bridges.clear();
    rep(i, n){
        vis[i]=false;
        ap[i]=false;
        par[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    // print all articulation points in the graph;
    cout << "All articulation points: \n";
    for(int i=0;i<n;i++){
        if(ap[i]) cout << i << " ";
    }
    cout << "\n";
    cout << "All bridges: \n";
    // print all bridges in the graph;
    for(array<int, 2> bridge : bridges){
        cout << bridge[0] << " " <<bridge[1] << "\n";
    }
    cout << "\n";
}

void addEdge(int u, int v){
    e[u].push_back(v);
    e[v].push_back(u);
}
void test(){
    n=5;
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
    BridgesAndArticulationPointsFinder();
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test();
    return 0;
}

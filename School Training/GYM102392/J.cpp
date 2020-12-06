#include<bits/stdc++.h>

using namespace std;

const int N=210000;
const int M=1100000;

typedef long long LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

LL ans;
int n;
vector<int> g[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*(n-1)/2;i++)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		g[x].pb(w);
		g[y].pb(w);
	}
	for (int i=1;i<=n;i++)
	{
		sort(g[i].begin(),g[i].end());
		for (int j=1;j<g[i].size();j+=2)
			ans+=max(g[i][j-1],g[i][j]);
	}
	printf("%lld\n",ans);
	return 0;
}
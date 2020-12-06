#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LC k<<1
#define RC k<<1|1

const int N=110000;
const int M=1100000;
const LL mod=1e9+7;

int T,n,m,k;
vector<int> g[N],f[N];
int dp[N][52],cas,du[N];
queue<pair<int,int> > que;
int ans[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for (int i=1;i<=n;i++)
			g[i].clear(),f[i].clear(),du[i]=0;
		while (m--)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			g[x].pb(y),g[y].pb(x);
			f[y].pb(x);
			du[x]++;
		}
		for (int i=1;i<=n;i++)
			if (du[i]==0) f[i].pb(i),du[i]=1;
		memset(ans,0,sizeof(ans));
		memset(dp,0,sizeof(dp));
		dp[n][0]=1;
		que.push(mp(n,0));
		while (!que.empty())
		{
			pair<int,int> p=que.front();
			que.pop();
			int x=p.fi,y=p.se;
			if (y<k)
			{
				for (auto u:g[x])
					if (dp[u][y+1]==0) dp[u][y+1]=dp[x][y]+1,que.push(mp(u,y+1));
			}
			if (ans[x]) continue;
			ans[x]=dp[x][y];
			for (auto u:f[x])
			{
				du[u]--;
				if (du[u]==0)
				{
					dp[u][0]=ans[x]+1;
					que.push(mp(u,0));
				}
			}
		}
		printf("Case #%d:\n",++cas);
		for (int i=1;i<=n;i++)
			printf("%d\n",ans[i]-1);
	}
	return 0;
}
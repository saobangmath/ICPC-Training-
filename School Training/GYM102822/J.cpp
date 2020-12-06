#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LC k<<1
#define RC k<<1|1

const int N=210000;
const int M=1100000;
const LL mod=1e9+7;
int T,cas,n,m;
int f[N],pp[N];
vector<int> g[N];
struct node
{
	int id,x;
	friend bool operator < (node a,node b)
	{
		return a.x<b.x;
	}
};
priority_queue<node> q;
int mx;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=m;i++)
			f[i]=pp[i]=0,g[i].clear();
		mx=0;
		for (int i=1;i<=n;i++)
		{
			int t,x;
			scanf("%d %d",&t,&x);
			f[t]=max(f[t],x);
			if (t>m) mx=max(mx,x);
		}
		while (!q.empty()) q.pop();
		for (int i=1;i<=m;i++)
			if (f[i])
			{
				for (int j=1;j<=m;j+=2*i)
				{
					g[j].pb(i);
					g[j+i].pb(-i);
				}
			}
		printf("Case #%d:",++cas);
		for (int i=1;i<=m;i++)
		{
			for (auto x:g[i])
			{
				if (x>0) q.push({x,f[x]}),pp[x]=1;
				else pp[-x]=0;
			}
			int ans=0;
			while (!q.empty())
			{
				node p=q.top();
				if (!pp[p.id]) q.pop();
				else
				{
					ans=p.x;
					break;
				}
			}
			printf(" %d",max(ans,mx));
		}
		printf("\n");
	}
	return 0;
}
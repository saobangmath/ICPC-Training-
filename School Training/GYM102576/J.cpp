#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

typedef long long LL;
const int N=1100000;
const int M=1100000;
const LL mod=1e9+7;

int T,n,q;
int a[3][3][N],pp[3][3][N];
int f[N];
map<pair<int,int>,int> S[3];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void Union(int x,int y)
{
	int fx=find(x),fy=find(y);
	if (fx!=fy) f[fx]=fy;
}
struct node
{
	int x,y,z;
}b[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(a,0,sizeof(a));
		memset(pp,0,sizeof(pp));
		S[0].clear(),S[1].clear(),S[2].clear();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			f[i]=i;
		for (int i=1;i<=n;i++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			b[i].x=x,b[i].y=y,b[i].z=z;
			if (x==-1)
			{
				if (a[2][1][y]) Union(a[2][1][y],i),pp[2][1][y]=1;
				if (a[2][1][y-1]) Union(a[2][1][y-1],i),pp[2][1][y-1]=1;
				if (a[2][1][y+1]) Union(a[2][1][y+1],i),pp[2][1][y+1]=1;
				if (a[1][2][z]) Union(a[1][2][z],i),pp[1][2][z]=1;
				if (a[1][2][z-1]) Union(a[1][2][z-1],i),pp[1][2][z-1]=1;
				if (a[1][2][z+1]) Union(a[1][2][z+1],i),pp[1][2][z+1]=1;
				a[0][1][y]=i;
				a[0][2][z]=i;
				if (S[0].count(mp(y,z))) Union(S[0][mp(y,z)],i);
				if (S[0].count(mp(y,z-1))) Union(S[0][mp(y,z-1)],i);
				if (S[0].count(mp(y,z+1))) Union(S[0][mp(y,z+1)],i);
				if (S[0].count(mp(y-1,z))) Union(S[0][mp(y-1,z)],i);
				if (S[0].count(mp(y+1,z))) Union(S[0][mp(y+1,z)],i);
				S[0][mp(y,z)]=i;
			}
			else if (y==-1)
			{
				if (a[2][0][x]) Union(a[2][0][x],i),pp[2][0][x]=1;
				if (a[2][0][x-1]) Union(a[2][0][x-1],i),pp[2][0][x-1]=1;
				if (a[2][0][x+1]) Union(a[2][0][x+1],i),pp[2][0][x+1]=1;
				if (a[0][2][z]) Union(a[0][2][z],i),pp[0][2][z]=1;
				if (a[0][2][z-1]) Union(a[0][2][z-1],i),pp[0][2][z-1]=1;
				if (a[0][2][z+1]) Union(a[0][2][z+1],i),pp[0][2][z+1]=1;
				a[1][0][x]=i;
				a[1][2][z]=i;
				if (S[1].count(mp(x,z))) Union(S[1][mp(x,z)],i);
				if (S[1].count(mp(x,z-1))) Union(S[1][mp(x,z-1)],i);
				if (S[1].count(mp(x,z+1))) Union(S[1][mp(x,z+1)],i);
				if (S[1].count(mp(x-1,z))) Union(S[1][mp(x-1,z)],i);
				if (S[1].count(mp(x+1,z))) Union(S[1][mp(x+1,z)],i);
				S[1][mp(x,z)]=i;
			}
			else
			{
				if (a[1][0][x]) Union(a[1][0][x],i),pp[1][0][x]=1;
				if (a[1][0][x-1]) Union(a[1][0][x-1],i),pp[1][0][x-1]=1;
				if (a[1][0][x+1]) Union(a[1][0][x+1],i),pp[1][0][x+1]=1;
				if (a[0][1][y]) Union(a[0][1][y],i),pp[0][1][y]=1;
				if (a[0][1][y-1]) Union(a[0][1][y-1],i),pp[0][1][y-1]=1;
				if (a[0][1][y+1]) Union(a[0][1][y+1],i),pp[0][1][y+1]=1;
				
				a[2][0][x]=i;
				a[2][1][y]=i;
				if (S[2].count(mp(x,y))) Union(S[2][mp(x,y)],i);
				if (S[2].count(mp(x,y-1))) Union(S[2][mp(x,y-1)],i);
				if (S[2].count(mp(x,y+1))) Union(S[2][mp(x,y+1)],i);
				if (S[2].count(mp(x-1,y))) Union(S[2][mp(x-1,y)],i);
				if (S[2].count(mp(x+1,y))) Union(S[2][mp(x+1,y)],i);
				S[2][mp(x,y)]=i;
			}
		}
		for (int i=1;i<=n;i++)
		{
			int x=b[i].x,y=b[i].y,z=b[i].z;
			if (x==-1)
			{
				if (a[0][1][y]&&pp[0][1][y]) Union(i,a[0][1][y]);
				if (a[0][2][z]&&pp[0][2][z]) Union(i,a[0][2][z]);
			}
			else if (y==-1)
			{
				if (a[1][0][x]&&pp[1][0][x]) Union(i,a[1][0][x]);
				if (a[1][2][z]&&pp[1][2][z]) Union(i,a[1][2][z]);
			}
			else
			{
				if (a[2][0][x]&&pp[2][0][x]) Union(i,a[2][0][x]);
				if (a[2][1][y]&&pp[2][1][y]) Union(i,a[2][1][y]);
			}
		}
		scanf("%d",&q);
		while (q--)
		{
			int x1,y1,z1,x2,y2,z2;
			scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
			int idx1=0;
			int idx2=0;
			if (S[0].count(mp(y1,z1))) idx1=S[0][mp(y1,z1)];
			else if (S[1].count(mp(x1,z1))) idx1=S[1][mp(x1,z1)];
			else if (S[2].count(mp(x1,y1))) idx1=S[2][mp(x1,y1)];
			
			if (S[0].count(mp(y2,z2))) idx2=S[0][mp(y2,z2)];
			else if (S[1].count(mp(x2,z2))) idx2=S[1][mp(x2,z2)];
			else if (S[2].count(mp(x2,y2))) idx2=S[2][mp(x2,y2)];
			
			if (idx1==0||idx2==0||find(idx1)!=find(idx2)) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}
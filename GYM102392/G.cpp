#include<bits/stdc++.h>

using namespace std;

const int N=110;
const int M=1100000;

typedef long long LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

int n,m,h,num;
int a[N][N],b[N][N];
int g[N][N][N];
int pa[N][N],pb[N][N];
char s[N];
vector<int> tmpa,tmpb;
int main()
{
	scanf("%d %d %d",&n,&m,&h);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			for (int k=0;k<h;k++)
				g[i][j][k]=1;
	for (int i=0;i<n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<m;j++)
		{
			a[i][j]=s[j]-'0';
			if (a[i][j]==0)
			{
				for (int k=0;k<h;k++)
					g[i][j][k]=0;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		scanf("%s",s);
		for (int k=0;k<h;k++)
		{
			b[i][k]=s[k]-'0';
			if (b[i][k]==0)
			{
				for (int j=0;j<m;j++)
					g[i][j][k]=0;
			}
		}
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			for (int k=0;k<h;k++)
				if (g[i][j][k]) pa[i][j]=1,pb[i][k]=1,num++;
	int flag=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (a[i][j]!=pa[i][j]) flag=1;
	for (int i=0;i<n;i++)
		for (int k=0;k<h;k++)
			if (b[i][k]!=pb[i][k]) flag=1;
	if (flag)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",num);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			for (int k=0;k<h;k++)
				if (g[i][j][k]) printf("%d %d %d\n",i,j,k);
	num=0;
	memset(g,0,sizeof(g));
	for (int i=0;i<n;i++)
	{
		int n1=0,n2=0,nn,cn;
		tmpa.clear(),tmpb.clear();
		for (int j=0;j<m;j++)
			if (a[i][j]) n1++,tmpa.pb(j);
		for (int k=0;k<h;k++)
			if (b[i][k]) n2++,tmpb.pb(k);
		nn=max(n1,n2);
		if (nn==0) continue;
		num+=nn;
		cn=0;
		for (int j=0;j<nn-n1;j++)
			tmpa.pb(tmpa[0]);
		for (int k=0;k<nn-n2;k++)
			tmpb.pb(tmpb[0]);
		sort(tmpa.begin(),tmpa.end());
		sort(tmpb.begin(),tmpb.end());
		for (int j=0;j<nn;j++)
			g[i][tmpa[j]][tmpb[j]]=1;
	}
	printf("%d\n",num);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			for (int k=0;k<h;k++)
				if (g[i][j][k]) printf("%d %d %d\n",i,j,k);
	return 0;
}
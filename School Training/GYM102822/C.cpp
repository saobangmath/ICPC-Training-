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
const int M=2100000;
const LL mod=1e9+7;
int T,cas,n,pos,root;
int len[N],beg[N],lim[N],now,val[N];
char s[M];
int num[M],num2[M];
int ch[M][26],flag;
void insert(int root,char s[],int n)
{
	int now=root;
	num[now]++;
	for (int i=0;i<n;i++)
	{
		if (ch[now][s[i]-'a']==0) ch[now][s[i]-'a']=++pos;
		now=ch[now][s[i]-'a'];
		num[now]++;
	}
}

struct node
{
	int id,v,op;
	friend bool operator < (node a,node b)
	{
		if (a.v!=b.v) return a.v<b.v;
		else return a.id<b.id;
	}
}a[N],b[N];
void add(int root,char s[],int n,int f)
{
	int now=root;
	num2[now]+=f;
	num[now]-=f;
	for (int i=0;i<n;i++)
	{
		now=ch[now][s[i]-'a'];
		num2[now]+=f;
		num[now]-=f;
	}
}
void work(int l,int r)
{
	for (int i=l;i<=r;i++)
	{
		int id=a[i].id;
		add(1,s+beg[id],len[id],1);
	}
	for (int i=l;i<=r;i++)
	{
		int id=a[i].id;
		int now=1,length=0;
		for (int j=beg[id];j<beg[id]+len[id];j++)
		{
			char x=s[j];
			if (num2[ch[now][x-'a']]==r-l+1) now=ch[now][x-'a'],length++;
			else break;
		}
		lim[id]=length;
		now=1,length=0;
		for (int j=beg[id];j<beg[id]+len[id];j++)
		{
			char x=s[j];
			if (num[ch[now][x-'a']]) now=ch[now][x-'a'],length++;
			else break;
		}
		insert(root,s+beg[id],length);
	}
	for (int i=l;i<=r;i++)
	{
		int id=a[i].id;
		add(1,s+beg[id],len[id],-1);
	}
}
int ans;
void dfs(int x)
{
	ans++;
	for (int i=0;i<26;i++)
		if (ch[x][i]) dfs(ch[x][i]);
}
map<int,int> S;
map<int,int>::iterator it;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		now=pos=1;
		memset(ch[1],0,sizeof(ch[1]));
		for (int i=1;i<=n;i++)
		{
			beg[i]=now;
			scanf("%s %d",s+now,&a[i].v);
			val[i]=a[i].v;
			a[i].id=i;
			len[i]=strlen(s+now);
			now+=len[i]+1;
			insert(1,s+beg[i],len[i]);
		}
		sort(a+1,a+1+n);
		root=++pos;
		int l=1,r=1;
		while (l<=n)
		{
			while (r<n&&a[r+1].v==a[l].v) r++;
			work(l,r);
			l=r+1;
		}
		
		int flag=0;
		for (int i=1;i<=n;i++)
		{
			int now=root,length=0;
			for (int j=beg[i];j<beg[i]+len[i];j++)
			{
				if (ch[now][s[j]-'a']) now=ch[now][s[j]-'a'],length++;
				else break;
			}
			if (length>lim[i]) flag=1;
			b[i]={i,now,(length<lim[i]&&length<len[i])?0:1};
		}
		ans=0;
		dfs(root);
		sort(b+1,b+1+n);
		l=1,r=1;
		while (l<=n)
		{
			while (r<n&&b[r+1].v==b[l].v) r++;
			int num=0;
			S.clear();
			for (int i=l;i<=r;i++)
				S[val[b[i].id]]|=b[i].op;
			for (it=S.begin();it!=S.end();it++)
				num+=(*it).se;
			if (num>1) flag=1;
			else ans+=S.size()-1;
			l=r+1;
		}
		printf("Case #%d: %d\n",++cas,flag?-1:ans);
		for (int i=1;i<=pos;i++)
		{
			num[i]=num2[i]=0;
			for (int j=0;j<26;j++)
				ch[i][j]=0;
		}
	}
	return 0;
}
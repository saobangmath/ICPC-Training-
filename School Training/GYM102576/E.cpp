#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

typedef long long LL;
const int N=110000;
const int M=8100000;
const LL mod=1e9+7;

int mx[M],n,q;
void update(int k)
{
	mx[k]=max(mx[LC],mx[RC]);
}
struct node
{
	int ymin,ymax,xmin,xmax,op,id;
	friend bool operator < (node a,node b)
	{
		if (a.ymin!=b.ymin) return a.ymin<b.ymin;
		return a.op<b.op;
	}
}a[M];
int c[M],nn,num;
int pp[M];
map<int,int> S;
void add(int k,int l,int r,int a,int b)
{
	if (l==r)
	{
		mx[k]=max(mx[k],b);
		return;
	}
	int mid=(l+r)/2;
	if (a<=mid) add(LC,l,mid,a,b);
	else add(RC,mid+1,r,a,b);
	update(k);
}
int ask(int k,int l,int r,int a,int b)
{
	if (l==a&&r==b) return mx[k];
	int mid=(l+r)/2;
	if (b<=mid) return ask(LC,l,mid,a,b);
	else if (a>mid) return ask(RC,mid+1,r,a,b);
	else return max(ask(LC,l,mid,a,mid),ask(RC,mid+1,r,mid+1,b));
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		mx[k]=(-2e9)-10;
		return;
	}
	int mid=(l+r)/2;
	build(LC,l,mid);
	build(RC,mid+1,r);
	update(k);
}

int main()
{
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		int x,y,r;
		scanf("%d %d %d",&x,&y,&r);
		a[i].ymin=y-r,a[i].ymax=y+r,a[i].xmin=a[i].xmax=x;
		a[i].op=0;
		c[++nn]=x;
	}
	for (int i=1;i<=q;i++)
	{
		int px,py,qx,qy,ymin,ymax;
		scanf("%d %d %d %d %d %d",&px,&py,&qx,&qy,&ymin,&ymax);
		a[i+n].xmin=px,a[i+n].xmax=qx;
		a[i+n].ymin=ymin,a[i+n].ymax=ymax;
		a[i+n].op=1;
		if (a[i+n].xmin>a[i+n].xmax) swap(a[i+n].xmin,a[i+n].xmax);
		c[++nn]=px,c[++nn]=qx;
		a[i+n].id=i;
	}
	sort(c+1,c+1+nn);
	S[c[1]]=num=1;
	for (int i=2;i<=nn;i++)
		if (c[i]!=c[i-1]) S[c[i]]=++num;
	sort(a+1,a+1+n+q);
	build(1,1,num);
	for (int i=1;i<=n+q;i++)
	{
		a[i].xmin=S[a[i].xmin],a[i].xmax=S[a[i].xmax];
		if (a[i].op==0) add(1,1,num,a[i].xmin,a[i].ymax);
		else
		{
			int ans=ask(1,1,num,a[i].xmin,a[i].xmax);
			if (ans>=a[i].ymax) pp[a[i].id]=1;
			else pp[a[i].id]=0;
		}
	}
	for (int i=1;i<=q;i++)
		if (pp[i]) printf("NO\n");
		else printf("YES\n");
	return 0;
}
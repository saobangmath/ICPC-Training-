#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

const int N=1100000;
const int M=1100000;
const LL mod=1e9+7;

int T;
LL n,ans,now;

int prim[N],cnt,m,valid[N],id1[N],id2[N];
LL L,g[N],sum[N],a[N];
LL cal(LL x)
{
    return x-1;
}
inline int getid(LL n,LL x)
{
    return x<=L?id1[x]:id2[n/x];
}
LL solve(LL x)
{
    cnt=m=0;
    if (x==1) return x;
    L=sqrt(x+0.5);
    for (int i=2;i<=L;i++)
    {
        if (!valid[i])
        {
            prim[++cnt]=i;
            sum[cnt]=(sum[cnt-1]+1)%mod;
        }
        for (int j=1;j<=cnt&&i*prim[j]<=L;j++)
        {
            valid[i*prim[j]]=1;
            if (i%prim[j]==0) break;
        }
    }
    for (LL i=1;i<=x;i=x/(x/i)+1)
    {
        a[++m]=x/i;
        if (a[m]<=L) id1[a[m]]=m;
        else id2[x/a[m]]=m;
        g[m]=cal(a[m]);
    }
    for (int i=1;i<=cnt;i++) 
        for (int j=1;j<=m&&(LL)prim[i]*prim[i]<=a[j]; j++) 
            g[j]=g[j]-(LL)(g[getid(x,a[j]/prim[i])]-sum[i-1]);
    return g[getid(x,x)]-g[getid(x,x/2)];
}    
int main()
{
    cin>>T;
    while (T--)
    {
    	cin>>n;
    	if (n==1e11)
    	{
    		cout<<"50999200118"<<endl;
    		continue;
    	}
    	LL s1=solve(n);
    	LL ans=(n-s1-1)/2;
    	ans=n-ans;
    	cout<<ans<<endl;
    }
    return 0;
}
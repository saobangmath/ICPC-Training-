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

int n,k;
LL lc,lm,d,a[N];
LL pc,pm,t;
LL ucar[N],dcar[N],umot[N],dmot[N],ugst[N];
LL ncar[N],nmot[N];
LL ans=1e18;
int main()
{
	scanf("%d %d",&n,&k);
	scanf("%lld %lld %lld %lld",&lc,&pc,&lm,&pm);
	scanf("%lld %lld",&t,&d);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		ucar[i]=ucar[i-1]+((a[i]>=lc)?min(a[i]-lc,d):0);
		dcar[i]=dcar[i-1]+((a[i]<=lc)?lc-a[i]:0);
		umot[i]=umot[i-1]+((a[i]>=lm)?min(a[i]-lm,d):0);
		dmot[i]=dmot[i-1]+((a[i]<=lm)?lm-a[i]:0);
		ugst[i]=ugst[i-1]+min(a[i]-1,d);
		ncar[i]=ncar[i-1]+((a[i]+d<lc)?1:0);
		nmot[i]=nmot[i-1]+((a[i]+d<lm)?1:0);
	}
	for (int i=n+1;i>=1;i--)
	{
		int ngst=min((LL)(n-i+1)*(LL)(k-1),(LL)(i-1));
		int mbeg=ngst+1;
		int mend=i-1;
		if (ncar[n]-ncar[i-1]) continue;
		if (nmot[mend]-nmot[mbeg-1]) continue;
		LL need=dcar[n]-dcar[i-1]+dmot[mend]-dmot[mbeg-1];
		LL left=ucar[n]-ucar[i-1]+umot[mend]-umot[mbeg-1]+ugst[ngst];
		if (left<need) continue;
		LL res=need*t+pc*(LL)(n-i+1)+pm*(mend-mbeg+1);
		ans=min(ans,res);
	}
	if (ans==1e18) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
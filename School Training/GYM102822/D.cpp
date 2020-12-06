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
int T,n,cas;
LL a[N];
int check(LL x)
{
	LL sum=0;
	for (int i=1;i<=n;i++)
		sum+=max(x-a[i],0LL);
	return sum<=x;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		LL l=0,r=4e9,ans;
		while (l<=r)
		{
			LL mid=(l+r)/2;
			if (check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("Case #%d: %lld\n",++cas,ans+1);
	}
	return 0;
}
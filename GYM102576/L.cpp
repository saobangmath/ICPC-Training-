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
const int M=1100000;
const LL mod=1e9+7;

int T,n,m;
int a[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		LL ans=a[n],res=0;
		for (int i=1;i<=n-m;i++)
			res+=a[i];
		printf("%I64d\n",max(res,ans));
	}
	return 0;
}
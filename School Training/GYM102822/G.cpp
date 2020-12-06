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
int T;
LL c0,c1,c2,c3,cas;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %lld %lld %lld",&c0,&c1,&c2,&c3);
		int flag=0;
		if (c0+c1+c2+c3==0) flag=1;
		else
		{
			if (c1+c2+c3==0) c0--;
			if (c1%3==2&&c2>=2) flag=0;
			else if (c0&1)
			{
				if (c1%3==2||c1%3==1&&c2>0) flag=1;
				else flag=0;
			}
			else
			{
				if (c1%3==2||c1%3==1&&c2>0) flag=0;
				else flag=1;
			}
		}
		if (flag) printf("Case #%d: Horse\n",++cas);
		else printf("Case #%d: Rabbit\n",++cas);
	}
	return 0;
}
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


int T,n,num;
char s[N],t[26][N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		reverse(s+1,s+1+n);
		num=0;
		while (n)
		{
			num++;
			t[num][n+1]=0;
			for (int i=n;i>=n/2+1;i--)
				t[num][i]=t[num][n+1-i]=s[i];
			int flag=0;
			for (int i=n;i>=1;i--)
				if (t[num][i]!=s[i])
				{
					if (t[num][i]>s[i]) flag=1;
					else flag=-1;
					break;
				}
			if (flag==1)
			{
				t[num][n/2+1]--;
				int pos=n/2+1;
				while (t[num][pos]<'0') t[num][pos]='9',pos++,t[num][pos]--;
				if (t[num][n]=='0')
				{
					if (n&1)
					{
						for (int i=n/2;i;i--)
							t[num][i]=t[num][n-i];
					}
					else
					{
						t[num][n/2]='9';
						for (int i=n/2-1;i;i--)
							t[num][i]=t[num][n-i];
					}
				}
				else
				{
					for (int i=n/2;i;i--)
						t[num][i]=t[num][n+1-i];
				}
			}
			for (int i=1;i<=n;i++)
				if (s[i]>=t[num][i]) s[i]-=t[num][i]-'0';
				else s[i]=10+s[i]-(t[num][i]-'0'),s[i+1]--;
			reverse(t[num]+1,t[num]+1+n);
			while (s[n]=='0') n--;
			
		}
		printf("%d\n",num);
		for (int i=1;i<=num;i++)
			if (t[i][1]=='0') printf("%s\n",t[i]+2);
			else printf("%s\n",t[i]+1);
	}
	return 0;
}
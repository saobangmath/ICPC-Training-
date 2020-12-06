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

int T,n;
struct point
{
	int x,y,op;
	friend bool operator < (point a,point b)
	{
		return a.y<b.y;
	}
}p[N];
stack<int> st;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d %d",&p[i].x,&p[i].y),p[i].op=0;
		for (int i=1;i<=n;i++)
			scanf("%d %d",&p[i+n].x,&p[i+n].y),p[i+n].op=1;
		sort(p+1,p+1+n+n);
		int mx=200;
		for (int i=1;i<=n+n;i++)
		{
			if (!st.empty()&&p[st.top()].op!=p[i].op)
			{
				printf("%d\n",4);
				printf("%d %d\n",p[st.top()].x,p[st.top()].y);
				printf("%d %d\n",mx,p[st.top()].y);
				printf("%d %d\n",mx,p[i].y);
				printf("%d %d\n",p[i].x,p[i].y);
				st.pop();
				mx+=10;
			}
			else st.push(i);
		}
	}
	return 0;
}
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>
 
using namespace std;
 
#define _int64 long long
#define mo 998244353

char s[210000];

int cnt[200];
char ch[200];
int d[30];

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,num,v,mi,b2;
	string ans;
	char c;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d",&n,&x,&y);
		scanf("%s",s);
		memset(cnt,0,sizeof(cnt));
		for (c='a';c<='z';c++)
			ch[x+c-'a']=c;
		for (c='A';c<='Z';c++)
			ch[y+c-'A']=c;
		for (i=0;i<n;i++)
		{
			if ((s[i]>='a')&&(s[i]<='z')) v=x+s[i]-'a';
			else v=y+s[i]-'A';
			cnt[v]++;
		}
		if (x>y) swap(x,y);
		ans="";
		b1=0;b2=0;
		mi=y+26;num=0;
		for (i=0;i<30;i++)
			d[i]=(1<<30);
		d[0]=0;
		for (i=y+25;i>=y;i--)
		{
			//cerr<<"i,cnt[i]:"<<i<<" "<<cnt[i]<<endl;
			if (cnt[i]>0)
			{
				b2=1;
			}
			if (x+25+cnt[i]+num>=i)
			{
				//cerr<<"i:"<<i<<" "<<ch[i]<<" "<<num<<endl;
				b2=0;
				b1=0;
				for (j=29;j>=0;j--)
				{
					if (d[j]==(1<<30)) continue;
					if (x+25+cnt[i]+num-d[j]>=i)
					{
						d[j+1]=min(d[j+1],d[j]+max(i-(x+25+cnt[i]),0)+min(cnt[i],1));
						b1=max(b1,j+1);
					}
				}
			}
			if (cnt[i]>0)
			{
				num++;
			}
		}
		b1+=cnt[x];
		for (i=x+1;i<x+26;i++)
		{
			if (cnt[i]>0)
				b1++;
		}
		//cerr<<x<<" "<<y<<" "<<b1<<" "<<b2<<endl;
		if (b2==0)
		{
			if (b1>0) ans.push_back(ch[x]);
		}
		else
		{
			for (i=0;i<b1;i++)
				ans.push_back(ch[x]);
			ans.push_back(ch[y]);
		}
		//reverse(ans.begin(),ans.end());
		printf("%s\n",ans.c_str());
	}
}

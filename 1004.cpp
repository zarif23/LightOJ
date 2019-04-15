#include<bits/stdc++.h>
#include<vector>
#define lo 1<<28
#define Ma 1<<16

using namespace std;
long long ban[300][300],dp[300][300];
long long r,c,n;

long long rec(long long i, long long j)
{
	if(i>=0 && i<r && j>=0 && j<c)
	{
		if(dp[i][j]!=-1) return dp[i][j];
		else
		{
			long long ret = -lo;
			if(i>=n-1)
			{
				ret = max(ret,rec(i+1,j)+ban[i][j]);
				ret = max(ret,rec(i+1,j-1)+ban[i][j]);
			}
			else
			{
				ret = max(ret,rec(i+1,j)+ban[i][j]);
				ret = max(ret,rec(i+1,j+1)+ban[i][j]);
			
			}
			dp[i][j] = ret;
			return dp[i][j];
		}
	}
	else return 0;
}


int main()
{
	long long t;
	cin>>t;
	long long ans[t];
	for(long long k=0;k<t;k++)
	{
		long long tmp;
		cin>>n;
		c = n, r = 2*n-1;
		memset(dp,-1,sizeof(dp));
		memset(ban,0,sizeof(ban));
		for(long long i=0;i<n;i++)
		{
			for(long long j=0;j<i+1;j++)
			{
				scanf("%lld",&tmp);
				ban[i][j] = tmp;
			}
		}
		for(long long i=n;i<2*n-1;i++)
		{
			for(long long j=0;j<2*n-i-1;j++)
			{
				scanf("%lld",&tmp);
				ban[i][j] = tmp;
			}
		}
		printf("Case %lld: %lld\n",k+1,rec(0,0));
	}
	
}

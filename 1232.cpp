#include<bits/stdc++.h>
#include<string.h>
#define mod 100000007

using namespace std;

int main()
{
	int i,cases=0,t,n,k,j,coins[100];
	long long dp[10010],ans[100];
	scanf("%d",&t);
	while(cases<t){
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&k);
//		cout<<n<<" "<<k<<endl;
		for(i=0;i<n;i++)
		{
			scanf("%d",&coins[i]);
		}
		dp[0]=1;
		for(i=0;i<n;i++)
		{
				for(j=1;j<=k;j++)
				{
					if(coins[i]<=j) dp[j] = (dp[j]%mod + dp[j-coins[i]]%mod)%mod;
				}
		}
		printf("Case %d: %lld\n",cases+1,dp[k]);
		ans[cases]=dp[k];
		cases++;
	}
//	for(i=0;i<t;i++) printf("Case %d: %lld\n",i+1,ans[i]);
	return 0;
}

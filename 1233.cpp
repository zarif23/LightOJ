#include<bits/stdc++.h>
#include<string.h>
#define mod 100000007

using namespace std;

int main()
{
	int i,cases=0,t,n,k,j,coins[100],times[100],count[100000];
	int dp[100001];
	set<int> num;
	scanf("%d",&t);
	while(cases<t){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		scanf("%d %d",&n,&k);
//		cout<<n<<" "<<k<<endl;
		for(i=0;i<n;i++) scanf("%d",&coins[i]);
		for(i=0;i<n;i++) scanf("%d",&times[i]);
		for(i=0;i<n;i++)
		{
			memset(count,0,sizeof(count));
			for(j=coins[i];j<=k;j++)
			{
				if(dp[j]==0)
				{
					if(dp[j-coins[i]]){
						count[j] = count[j-coins[i]]+1;
						if(count[j]<=times[i]){
							dp[j] = 1;
							num.insert(j);
						}
					}
				}
//				cout<<coins[i]<<" "<<j<<" "<<dp[j-coins[i]]<<" "<<count[coins[i]]<<endl;
			}
		}
		printf("Case %d: %lld\n",cases+1,num.size());
//		ans[cases]=num.size();
		cases++;
		num.clear();
	}
//	for(i=0;i<t;i++) printf("Case %d: %lld\n",i+1,ans[i]);
	return 0;
}

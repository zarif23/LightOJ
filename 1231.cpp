#include<bits/stdc++.h>
#include<string.h>
#include<vector>
#define mod 100000007

using namespace std;

vector<int> co;
int dp[100][1100],coins[100],n,k,times[100];
long long call(int i,int amount)
{
//	cout<<i<<" "<<amount<<endl;
    if(dp[i][amount]!=-1) return dp[i][amount]; 
    if(i==n) 
	{ 
        if(amount==k)return 1;
        else return 0;
    }
    if(amount==k) return 1;
    long long ret=0;
    if(amount<k)
	{
		for(int j=0;j<=times[i] && (j*coins[i]+amount <=k );j++)
		{
			ret = (ret%mod + call(i+1,amount + coins[i]*j)%mod)%mod;
		}
	}
    return dp[i][amount]=ret; 
}


int main()
{
	int i,cases=0,t;
	scanf("%d",&t);
	while(cases<t){
		scanf("%d %d",&n,&k);
		for(i=0;i<2*n;i++)
		{
			if(i<n)scanf("%d",&coins[i]);
			else scanf("%d",&times[i-n]);
		}
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %lld\n",cases+1,call(0,0));
		cases++;
	}
}

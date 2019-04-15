#include<bits/stdc++.h>
typedef unsigned long long ull;

using namespace std;

ull recur(int n,int m, int k)
{
	if(k>n || k>m) return 0;
	if(k==0) return 1;
	if(m==1) return n;
	return  n*recur(n-1,m-1,k-1) + recur(n,m-1,k);
}

int main()
{
	int T,t=0,i,j;
	scanf("%d",&T);
	while(t<T)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		recur(n,n,k);
		printf("Case %d: %llu\n",t+1,recur(n,n,k));
		t++;
	}
}
